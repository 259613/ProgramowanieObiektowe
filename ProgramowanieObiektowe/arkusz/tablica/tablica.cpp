/// @file

#include "tablica.hpp"
#include <limits>
#include <utility>
#include <iostream>
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
		tablica = tworzTablica(kolumny, wiersze, cellType::typeString);
	}
	else
	{
		tablica = tworzTablica(kolumny, wiersze,cellType::typeInt);
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
		nowaTablica = tworzTablica(nowyX, nowyY, cellType::typeString);
	}
	else
	{
		nowaTablica = tworzTablica(nowyX, nowyY, cellType::typeInt);
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

		for (size_t x = 0; x < iloscKolumn; x++)
		{
			nowaTablica[x] = tablica[x];
			nowaTablica[x]->expandColumn(nowyY);
		}


	delete[](tablica);
	iloscWierszy = nowyY;
	iloscKolumn = nowyX;
	tablica = nowaTablica;
	typeTracker = newTracker;
	return Wyjatki::BRAK;
}

Tablica Arkusz::tworzTablica(size_t rozmiarX, size_t rozmiarY, cellType typ)
{

	Tablica tablica = new Column*[rozmiarX];
	for(int x; x<rozmiarX; x++){
		tablica[x] = new Column(rozmiarY, typ);
	}

	return tablica;
}

Wyjatki Arkusz::modyfikacjaWartosci(size_t x, size_t y, std::string wartosc)
{
	if (x > iloscKolumn || y > iloscWierszy)
	{
		return Wyjatki::TABLICA_ZAKR;
	}

	static_cast<stringCell &>((tablica[y]->getElement(x))).setValue(wartosc);
	return Wyjatki::BRAK;
}

Wyjatki Arkusz::modyfikacjaWartosci(size_t x, size_t y, int wartosc)
{
	if (x > iloscKolumn || y > iloscWierszy)
	{
		return Wyjatki::TABLICA_ZAKR;
	}

	static_cast<intCell &>((tablica[y]->getElement(y))).setValue(wartosc);
	return Wyjatki::BRAK;
}

Komorka &Arkusz::zwrocWartosc(size_t x, size_t y)
{
	/*if(x > iloscKolumn || y > iloscWierszy){
		
	}*/
	return tablica[x]->getElement(y);
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

			// for (size_t y = 0; y < iloscWierszy; y++)
			// {
			// 	auto currentCell = static_cast<stringCell &>(*tablica[y][column]);
			// 	intCell* newCell = toIntCell(currentCell);
			// 	//std::move(tablica[y][column]);
			// 	delete tablica[y][column];
			// 	//tablica[y][column] = newCell;
			// 	tablica[y][column] = new intCell(10);
			// }
		}
		case cellType::typeString:
		{

			// for (size_t y = 0; y < iloscWierszy; y++)
			// {
			// 	auto currentCell = static_cast<intCell &>(*tablica[y][column]);
			// 	stringCell* newCell = toStringCell(currentCell);
			// 	//std::move(tablica[y][column]);
			// 	delete (tablica[y][column]);
			// 	tablica[y][column] = newCell;
			// }
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