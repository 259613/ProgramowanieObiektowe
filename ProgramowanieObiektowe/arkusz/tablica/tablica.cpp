/// @file

#include "tablica.hpp"
#include <limits>

Arkusz::Arkusz(size_t kolumny, size_t wiersze, bool czyTekstowa) : tekstowa(czyTekstowa)
{
	iloscWierszy = wiersze;
	iloscKolumn = kolumny;
	typeTracker = new cellType[iloscKolumn];
	cellType type = cellType::typeInt;

	if (czyTekstowa)
	{
		type = cellType::typeString;
	}

	for (size_t i = 0; i < iloscKolumn; i++)
	{
		typeTracker[i] = type;
	}
	if (czyTekstowa)
	{
		tablica = tworzTablicaString(kolumny, wiersze);
	}
	else
	{
		tablica = tworzTablicaInt(kolumny, wiersze);
	}
}

Wyjatki Arkusz::rozszerzArkusz(size_t nowyX, size_t nowyY)
{
	if (nowyX < 1 || nowyY < 1)
	{
		return Wyjatki::TABLICA_SIZE;
	}

	if (iloscKolumn > nowyX)
	{
		iloscKolumn = nowyX;
	}
	if (iloscWierszy > nowyY)
	{
		iloscWierszy = nowyY;
	}
	Tablica nowaTablica;
	cellType * newTracker = new cellType[nowyX];
	if (tekstowa)
	{
		nowaTablica = tworzTablicaString(nowyX, nowyY);
	}
	else
	{
		nowaTablica = tworzTablicaInt(nowyX, nowyY);
	}
	for(size_t i = 0; i < nowyX; i++){
		if(i < iloscKolumn){
			newTracker[i] = typeTracker[i];
		}
		else if(tekstowa){
			newTracker[i] = cellType::typeString;
		}
		else{
			newTracker[i] = cellType::typeInt;
		}
	}

	for (size_t y = 0; y < iloscWierszy; y++)
	{
		for (size_t x = 0; x < iloscKolumn; x++)
		{
			if (tekstowa)
			{
				static_cast<stringCell &>(*nowaTablica[y][x]).setValue((*tablica[y][x]).toString());
			}
			else
			{
				static_cast<intCell &>(*nowaTablica[y][x]).setValue((*tablica[y][x]).getValue());
			}
		}
		delete[](tablica)[y];
	}

	delete[](tablica);
	iloscWierszy = nowyY;
	iloscKolumn = nowyX;
	tablica = nowaTablica;
	typeTracker = newTracker;
	return Wyjatki::BRAK;
}

Tablica Arkusz::tworzTablica(size_t rozmiarX, size_t rozmiarY)
{
	Tablica tablica = new Cell **[rozmiarY];

	int licznik = rozmiarY;

	while (licznik)
	{
		tablica[--licznik] = new Cell *[rozmiarX];
	}

	return tablica;
}

Tablica Arkusz::tworzTablicaInt(size_t rozmiarX, size_t rozmiarY)
{
	Tablica tablica = tworzTablica(rozmiarX, rozmiarY);

	for (size_t i = 0; i < rozmiarY; i++)
	{
		for (size_t j = 0; j < rozmiarX; j++)
		{
			tablica[i][j] = new intCell(0);
		}
	}

	return tablica;
}

Tablica Arkusz::tworzTablicaString(size_t rozmiarX, size_t rozmiarY)
{
	Tablica tablica = tworzTablica(rozmiarX, rozmiarY);

	for (size_t i = 0; i < rozmiarY; i++)
	{
		for (size_t j = 0; j < rozmiarX; j++)
		{
			tablica[i][j] = new stringCell("x");
		}
	}

	return tablica;
}

Wyjatki Arkusz::modyfikacjaWartosci(size_t x, size_t y, std::string wartosc)
{
	if (x > iloscKolumn || y > iloscWierszy)
	{
		return Wyjatki::TABLICA_ZAKR;
	}

	static_cast<stringCell &>((*tablica[y][x])).setValue(wartosc);
	return Wyjatki::BRAK;
}

Wyjatki Arkusz::modyfikacjaWartosci(size_t x, size_t y, int wartosc)
{
	if (x > iloscKolumn || y > iloscWierszy)
	{
		return Wyjatki::TABLICA_ZAKR;
	}

	static_cast<intCell &>((*tablica[y][x])).setValue(wartosc);
	return Wyjatki::BRAK;
}

Komorka &Arkusz::zwrocWartosc(size_t x, size_t y)
{
	/*if(x > iloscKolumn || y > iloscWierszy){
		
	}*/
	return *(tablica[y][x]);
}

size_t Arkusz::rozmiarX()
{
	return iloscKolumn;
}

size_t Arkusz::rozmiarY()
{
	return iloscWierszy;
}

bool Arkusz::czyTekstowa()
{
	return tekstowa;
}

void Arkusz::convertColumn(cellType type, size_t column)
{
	auto currentType = typeTracker[column];
	if (currentType != type)
	{

		switch (type)
		{
		case cellType::typeGeneric:
			break;
		case cellType::typeInt:
		{

			for (size_t y = 0; y < iloscWierszy; y++)
			{
				auto currentCell = static_cast<stringCell &>(*tablica[y][column]);
				delete tablica[y][column];
				tablica[y][column] = toIntCell(currentCell);
			}
		}
		case cellType::typeString:
		{

			for (size_t y = 0; y < iloscWierszy; y++)
			{
				auto currentCell = static_cast<intCell &>(*tablica[y][column]);
				delete tablica[y][column];
				tablica[y][column] = toStringCell(currentCell);
			}
		}
		}
		typeTracker[column] = type;
	}
}

cellType Arkusz::getColumnType(size_t column)
{
	return typeTracker[column];
}

bool Arkusz::calculateableColumn(size_t column)
{
	for (size_t i = 0; i < calculateableTypesCount; i++)
	{
		if (typeTracker[column] == calculateableTypes[i])
		{
			return true;
		}
	}
	return false;
}

bool Arkusz::hasCalculateableColumn()
{
	for (size_t i = 0; i < iloscKolumn; i++)
	{
		if (calculateableColumn(i))
		{
			return true;
		}
	}
	return false;
}

size_t Arkusz::calculateableColumnsCount()
{
	size_t x{};
	for (size_t i = 0; i < iloscKolumn; i++)
	{
		if (calculateableColumn(i))
		{
			x++;
		}
	}
	return x;
}