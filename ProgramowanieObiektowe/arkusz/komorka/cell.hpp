/// @file

#ifndef HEADER_GUARD_CELL_
#define HEADER_GUARD_CELL_

#include <string>

/**
 * @brief Interfejs/ klasa czysto wirtualna komórka
 * Interfejs komórka posiadający metody ogólne klas dziedziczących
 */
class Cell{
public:
	/**
	 * @brief getValue Metoda ogólna od uzyskiwania wartości komórki
	 * Metoda zwraca wartość w postaci wartości tekstowej komórki
	 * @return zawartość tekstowa komórki
	 */
	virtual std::string getValue()=0;

	/**
	 * @brief setValue Metoda ogólna od ustawiania wartości
	 * Ustawia wartość komórki za pomocą wartości string
	 * @param[in] value ustawiana wartość
	 */
	virtual void setValue(std::string value) = 0;


};

#endif
