///@file
#ifndef HEADER_GUARD_COLUMN_
#define HEADER_GUARD_COLUMN_
#include <cstddef>
#include "../../error.hpp"
#include "../komorka/cell.hpp"

class Column{

	Cell **cells;
	std::size_t sizeY;
	public:

	/**
	 * @brief zwraca komórkę kolumny
	 * Funkcja służy do wybierania komórki z kolumny
	 * @param[in] y parametr wyboru adresu komórki
	 * @return Cell wybrana komórka 
     * @throw std::out_of_range parametr y wskazuje na element poza zakresem tablicy komórek
	 */
	Cell getElement(int y);

	/**
	 * @brief Dostęp do komórki przez operator nawiasów kwadratowych
	 * Przeciążenie operatora '[]' celem wyboru określonej komórki
	 * @param y wybrany adres komórki
	 * @return Cell& referencja wybranej komórki 
     * @throw std::out_of_range parametr y wskazuje na element poza zakresem tablicy komórek
	 */
	Cell& operator[](int y);

	/**
	 * @brief Rozmiar kolumny
	 * Getter rozmiaru kolumny
	 * @return std::size_t Rozmiar kolumny
	 */
	std::size_t getSize();
};


#endif
