#ifndef HEADER_GUARD_TABLICA_
#define HEADER_GUARD_TABLICA_


/// @file

#include <cstddef>
#include "../../error.hpp"
#include "../kolumna/column.hpp"

/**
 * @brief Klasa opisująca Arkusz
 * Klasa Arkusz przechowywujaca tablicę kolumn i jej rozmiar
 */
class Sheet{

	Column** array; /// Tablica wskaźników na kolumny
	size_t width;	/// Szerokość tablicy - ilość kolumn
	size_t height;	/// Wysokość tablicy - ilość komórek w utworzonych kolumnach

protected:

	/**
	 * @brief createColumnArray Tworzy nową dwuwymiarową tablice.
	 * Funkcja generujaca tablicę o określonym rozmiarze
	 *
	 * @param[in] width Szerokość nowej tablicy  - ilość kolumn
	 * @param[in] height Wysokość nowej tablicy  - ilość komórek w kolumnach
	 * @param[in] types Typy tworzonych kolumn
	 *
	 * @throws bad_array_new_length Zły rozmiar tworzonego arkusza
	 *
	 * @return Tworzy nową tabilce wskaźników kolumn o wyznaczonych rozmiarach
	 */
	static Column** createColumnArray(size_t width, size_t height, CellType* types);
public:

	/**
	 * @brief Sheet Konstruktor tworzący akrusz z tablicą o wyznaczonym rozmiarze
	 * Konstruktor tworzący arkusz z tablicą o wyznaczonej ilości kolumn określonego typu i wierszy
	 *
	 * @param[in] width Szerokość tablicy nowego arkusza
	 * @param[in] height Wysokość nowej tablicy
	 * @param[in] types Typy tworzonych kolumn
	 *
	 * @throws bad_array_new_length Zły rozmiar tworzonego arkusza
	 */
	Sheet(size_t width, size_t height, CellType* types);

	/**
	 * @brief getWidth getter szerokości
	 * Zwraca ilość kolumn w arkuszu
	 *
	 * @return ilość kolumn
	 */
	size_t getWidth();

	/**
	 * @brief getHeight getter wysokości
	 * Zwraca ilość komórek w kolumnie kiedy arkusz był tworzony/rozszerzany
	 *
	 * @return wysokość arkusza / ilość wierszy
	 */
	size_t getHeight();

	/**
	 * @brief getColumn Metoda zwracająca referencję na kolumnę
	 * Zwraca referencję na wybraną kolumnę z arkusza
	 *
	 * @param[in] x Indeks kolumny
	 *
	 * @throws std::out_of_range Gdy x jest poza zakresem arkusza (x > width)
	 *
	 * @return Referencja na kolumnę
	 */
	Column& getColumn(size_t x);

	/**
	 * @brief operator [] przeciążenie operatora[] celem uzyskiwania odrębnej kolumny
	 *
	 * Zwraca referencję na wybraną kolumnę
	 *
	 * @param[in] x Indeks kolumny
	 *
	 * @throws std::out_of_range Gdy x jest poza zakresem arkusza (x > width)
	 *
	 * @return Referencja na wybraną kolumnę
	 */
	Column& operator[](size_t x);

	/**
	 * @brief resize Metoda rozszerzania arkusza
	 *
	 * Metoda zmienia rozmiar arkusza kopiując kolumny które także przechodzą zmianę rozmiaru
	 * Nowe kolumny są automatycznie przeznaczone pod komórki typu IntCell
	 * Utrata danych w przypadku zmniejszania rozmiaru arkusza
	 *
	 * @param[in] x Nowa szerokość arkusza
	 * @param[in] y Nowa wysokość kolumn arkusza
	 *
	 * @throws bad_array_new_length Zły rozmiar tworzonego arkusza
	 */
	void resize(size_t x, size_t y);
};

#endif
