/// @file

#include <fstream>
#include "zapisOdczyt.hpp"
#include <iostream>

using namespace std;

Wyjatki zapisPliku(Arkusz arkusz, string nazwa)
{
	ofstream plik(nazwa);
	size_t iloscKolumn = arkusz.rozmiarX();
	size_t iloscWierszy = arkusz.rozmiarY();
	if (plik.good())
	{
		plik << iloscWierszy << endl;
		plik << iloscKolumn << endl;
		for (size_t y = 0; y < iloscWierszy; y++)
		{
			for (size_t x = 0; x < iloscKolumn; x++)
			{
				plik << arkusz.zwrocWartosc(x, y).toString() << (x < iloscKolumn - 1 ? ", " : "");
			}
			if (y < iloscWierszy - 1)
			{
				plik << endl;
			}
		}
	}

	else
	{
		return Wyjatki::PLIK_ACCESS;
	}

	plik.close();
	return Wyjatki::BRAK;
}

Wyjatki wczytajPlik(Arkusz *arkusz, string nazwa)
{
	ifstream plik(nazwa);
	if (plik.good())
	{
		size_t rozmiarWczytY{}, rozmiarWczytX{};
		plik >> rozmiarWczytY;
		plik >> rozmiarWczytX;

		if (rozmiarWczytX < 1 || rozmiarWczytY < 1)
		{
			return Wyjatki::PLIK_ROZMIAR;
		}

		Arkusz nowyArkusz(rozmiarWczytX, rozmiarWczytY, true);
		string wartosc{};
		for (size_t y = 0; y < rozmiarWczytY; y++)
		{
			for (size_t x = 0; x < (rozmiarWczytX)-1; x++)
			{
				getline(plik, wartosc, ',');
				static_cast<stringCell &>(nowyArkusz.zwrocWartosc(x, y)).setValue(wartosc);
			}

			getline(plik,wartosc, '\n');

			nowyArkusz.modyfikacjaWartosci((rozmiarWczytX)-1, y, wartosc);
		}
		Arkusz arkuszInt(rozmiarWczytX, rozmiarWczytY);
		int wartoscInt{};
		for (size_t y = 0; y < rozmiarWczytY; y++)
		{
			for (size_t x = 0; x < (rozmiarWczytX)-1; x++)
			{
				try
				{
					wartoscInt = stoi(nowyArkusz.zwrocWartosc(x, y).toString());
				}
				catch (const std::invalid_argument &e)
				{
					*arkusz = nowyArkusz;
					plik.close();
					return Wyjatki::BRAK;
				}
				arkuszInt.modyfikacjaWartosci(x, y, wartoscInt);
			}
		}
		*arkusz = arkuszInt;
	}

	else
	{
		return Wyjatki::PLIK_ACCESS;
	}

	plik.close();
	return Wyjatki::BRAK;
}
