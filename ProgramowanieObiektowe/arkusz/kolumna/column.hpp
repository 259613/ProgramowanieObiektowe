///@file
#ifndef HEADER_GUARD_COLUMN_
#define HEADER_GUARD_COLUMN_
#include <cstddef>
#include "../../error.hpp"
#include "../komorka/cell.hpp"

class Column{

	Cell **cells;
	std::size_t sizeY;
	bool textOnly;
	
	private:

	/**
	 * @brief Metoda prywatna od tworzenia nowej kolumny
	 * 
	 * @param sizeY rozmiar nowej tablicy kolumny
	 * @param textOnly czy komórki są typu tekstowego
	 * @return Cell** tablica kolumny
	 */
	static Cell ** genColumn(size_t sizeY, bool textOnly);
	
	public:

	/**
	 * @brief Konstruktor kolumny
	 * Konstruktor kolumny tworzący kolumne o okeślonym rozmiarze i typie
	 * @param sizeY rozmiar kolumny
	 * @param textOnly czy tylko tekstowa
	 */
	Column(size_t sizeY, bool textOnly);



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

	/**
	 * @brief funkcja zmiany rozmiaru kolumny
	 * Funkcja zmienia rozmiar kolumny przepisując zawartość starego rozmiaru do nowego
	 * Możliwa utrata danych przy zmianie rozmiaru na mniejszy
	 * 
	 * @param[in] sizeY nowy rozmiar tablicy.
	 */
	void resizeColumn(std::size_t sizeY);

	/**
	 * @brief Funkcja zwraca czy kolumna jest typu tekstowego 
	 * Funkcja służy do sprawdzania czy kolumna jest typu tekstowego
	 * @return true kolumna typu tekstowego
	 * @return false kolumna jest typu liczbowego
	 */
	bool isText();
};


#endif
