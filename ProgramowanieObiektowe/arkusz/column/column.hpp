///@file
#ifndef HEADER_GUARD_COLUMN_
#define HEADER_GUARD_COLUMN_

#include "../../error.hpp"
#include "../cell/cell.hpp"
#include "../cell/cellType.hpp"
#include <cstddef>

/**
 * @brief Klasa określająca kolumnę
 * Klasa kolumna obsługująca podstawowe funkcjonalności kolekcji
 * posiada wskaźnik początku i końca zakresu celem wykorzystania w funkcjach
 * z biblioteki algorithm czy pętlach zakresowych
 */
class Column{
	Cell** cellArray; /// Tablica komórek w kolumnie
	size_t height;	/// Wysokość tablicy komórek
	CellType type;	/// Typ komórek w kolumnie
protected:
	/**
	 * @brief generateCellArray metoda tworząca nową tablicę komórek
	 * Statyczna metoda zajmująca się tworzeniem jednowymiarowej tablicy komórek określonego typu
	 *
	 * @param[in] height Wysokość nowej tablicy
	 * @param[in] type Typ tworzonych komórek
	 *
	 * @throws std::bad_array_new_length w przypadku zerowego rozmiaru
	 *
	 * @return Tablica jednowymiarowa wskaźników na komórki określonego typu
	 */
	static Cell** generateCellArray(size_t height, CellType type);
public:
	/**
	 * @brief resize metoda rozszerzająca kolumnę
	 * Metoda zajmuje się rozszerzaniem i zmniejszaniem obecnie przechowywanej tablicy
	 * Możliwa utrata danych przy zmienianiu rozmiaru na mniejszy
	 *
	 * @throws std::bad_array_new_length w przypadku zerowego rozmiaru
	 *
	 * @param[in] newHeight Nowy rozmiar kolumny
	 */
	void resize(size_t newHeight);

	/**
	 * @brief Column Konstruktor kolumny  o określonym rozmiarze i typie
	 * Tworzy nową kolumnę z tablicą o określonym rozmiarze na wskaźniki komórek określonego typu
	 *
	 * @param[in] height Rozmiar tablicy komórek w kolumnie
	 * @param[in] type Typ tworzonych komórek w kolumnie
	 *
	 * @throws std::bad_array_new_length w przypadku zerowego rozmiaru
	 */
	Column(size_t height, CellType type);

	/**
	 * @brief Getter wysokości kolumny
	 * Zwraca rozmiar tablicy w kolumnie
	 *
	 * @return Rozmiar kolumny
	 */
	std::size_t getHeight();

	/**
	 * @brief getType Getter typu kolumny
	 * Zwraca typ komórek jaką kolumna przechowywuje
	 * @return Typ komórek w kolumnie
	 */
	CellType getType();

	/**
	 * @brief begin Zwraca początek tablicy
	 * Metoda zwracaja wskaźnik na początek tablicy komórek
	 * @return początek wewnętrznej tablicy
	 */
	Cell** begin();

	/**
	 * @brief end Zwraca koniec tablicy
	 * Metoda zwracająca wskaźnik na koniec tablicy komórek
	 * @return koniec tablicy komórek
	 */
	Cell** end();

	void changeType(CellType newType);

	/**
	 * @brief getCell metoda zwraca referencje do komórki
	 * Metoda zwraca referencje do wybranej komórki jeśli jest ona w zakresie kolumny
	 *
	 * @param[in] y współżędna do komórki w tablicy
	 *
	 * @throws std::out_of_range Gdy y jest poza zakresem kolumny (y > height)
	 *
	 * @return referencja komórki z tablicy
	 */
	Cell& getCell(size_t y);

	/**
	 * @brief getCell operator zwracający referencje do komórki
	 * Operator zwraca referencje do wybranej komórki jeśli jest ona w zakresie kolumny
	 *
	 * @param[in] y współżędna do komórki w tablicy
	 *
	 * @throws std::out_of_range Gdy y jest poza zakresem kolumny (y > height)
	 *
	 * @return referencja komórki z tablicy
	 */
	Cell& operator[](size_t y);

	/*! \brief Funkcja szukania maksymalnej wartości kolumny
	 *
	 * Funkcja przeszukuje całą kolumne celem określenia największej wprowadzonej wartości
	 *
	 * @return Zwraca wartość największą kolumny
	 */
	double max();

	/*! \brief Funkcja szukania minimalnej wartości kolumny
	 *
	 * Funkcja przeszukuje całą kolumne celem określenia najmniejszej wprowadzonej wartości
	 *
	 * @return Zwraca wartość najmniejszą kolumny
	 */
	double min();

	/*! \brief Funkcja licząca sumę elementów kolumny
	 *
	 * Funkcja zwraca sumę całej kolumny
	 *
	 * @return Zwraca sumę wszystkich elementów kolumny
	 */
	double sum();


};

#endif
