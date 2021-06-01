/// @file

#ifndef HEADER_GUARD_COLUMN_
#define HEADER_GUARD_COLUMN_
#include "../../error.hpp"
#include "../komorka/cell.hpp"
#include "../komorka/cellTypes.hpp"



/**
 * @brief 
 * 
 */
class Column{
	Cell ** cells;
	size_t sizeY;
	cellType columnType;

	public:

	Column(){};

	Column(size_t y, cellType type);

	cellType getType();

	Cell& getElement(size_t y);

	size_t getSizeY();

	/** 
	 * \brief Wstawia określoną wartość do komórki tekstowej tablicy w arkuszu.
	 * 
	 * Funkcja wstawia wartość do komórki o określonym adresie
	 * 
	 * @param[in] y określony wiersz
	 * @param[in] wart wprowadzana wartość
	 * @return Kod błędu, ::BRAK - Brak błędu, ::TABLICA_ZAKR - indeks spoza zakresu tablicy
	 */
	Wyjatki modifyCell(size_t y, std::string wartosc);

	/** 
	 * \brief Wstawia określoną wartość do komórki liczbowej tablicy w arkuszu.
	 * 
	 * Funkcja wstawia wartość do komórki o określonym adresie
	 * 
	 * @param[in] y określony wiersz
	 * @param[in] wart wprowadzana wartość
	 * @return Kod błędu, ::BRAK - Brak błędu, ::TABLICA_ZAKR - indeks spoza zakresu tablicy
	 */
	Wyjatki modifyCell(size_t y, int wartosc);

	/** 
	 * \brief Modyfikacja rozmiaru tablicy.
	 * 
	 * Funkcja modyfikująca rozmiar arkusza,
	 * wartości modyfikowanego arkuszu zostają zachowane 
	 * wraz z rozszerzaniem bądź redukcją rozmiaru 
	 * (przy redukcji możliwa utrata kolumn/wierszy)
	 * 
	 * @param[in] nowyY nowa wysokość kolumny
	 * @return Kod błędu, ::BRAK - Brak błędu, ::TABLICA_SIZE - Niepoprawny rozmiar tablicy
	 */
	Wyjatki expandColumn(size_t newY);

	Cell** createColumnArray(size_t newY, cellType type);

};


#endif