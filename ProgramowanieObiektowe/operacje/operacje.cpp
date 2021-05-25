#include "operacje.hpp"
#include <iostream>
int maxWiersz(Arkusz arkusz, size_t wiersz)
{
	int max = arkusz.zwrocWartosc(0, wiersz).getValue();
	for (size_t i = 1; i < arkusz.rozmiarX(); i++)
	{
		std::cout << (arkusz.calculateableColumn(i)?"Tak ": "Nie ");
		if (arkusz.calculateableColumn(i))
		{

				std::cout << arkusz.zwrocWartosc(i, wiersz).getValue();
			if (max < arkusz.zwrocWartosc(i, wiersz).getValue())
			{
				max = arkusz.zwrocWartosc(i, wiersz).getValue();
			}
		}
	}
	return max;
}

int minWiersz(Arkusz arkusz, size_t wiersz)
{
	int min = arkusz.zwrocWartosc(0, wiersz).getValue();
	for (size_t i = 1; i < arkusz.rozmiarX(); i++)
	{
		if (arkusz.calculateableColumn(i))
		{
			if (min > arkusz.zwrocWartosc(i, wiersz).getValue())
			{
				min = arkusz.zwrocWartosc(i, wiersz).getValue();
			}
		}
	}
	return min;
}

int sumaWiersz(Arkusz arkusz, size_t wiersz)
{
	int sum = arkusz.zwrocWartosc(0, wiersz).getValue();
	for (size_t i = 1; i < arkusz.rozmiarX(); i++){

		if (arkusz.calculateableColumn(i))
		{
			{
				sum += arkusz.zwrocWartosc(i, wiersz).getValue();
			}
		}
	}
	return sum;
}

int maxKolumna(Arkusz arkusz, size_t kolumna)
{
	int max = arkusz.zwrocWartosc(kolumna, 0).getValue();
	for (size_t i = 1; i < arkusz.rozmiarY(); i++)
	{
			if (max < arkusz.zwrocWartosc(kolumna, i).getValue())
			{
				max = arkusz.zwrocWartosc(kolumna, i).getValue();
			}
	}
	return max;
}

int minKolumna(Arkusz arkusz, size_t kolumna)
{
	int min = arkusz.zwrocWartosc(kolumna, 0).getValue();
	for (size_t i = 1; i < arkusz.rozmiarY(); i++)
	{
		if (arkusz.zwrocWartosc(kolumna, i).isCalcualteable())
		{
				min = arkusz.zwrocWartosc(kolumna, i).getValue();
		}
	}
	return min;
}

int sumaKolumna(Arkusz arkusz, size_t kolumna)
{
	int sum = arkusz.zwrocWartosc(kolumna, 0).getValue();
	for (size_t i = 1; i < arkusz.rozmiarY(); i++)
	{
			sum += arkusz.zwrocWartosc(kolumna, i).getValue();
	}
	return sum;
}