/// @file

#ifndef HEADER_GUARD_INTCELL_
#define HEADER_GUARD_INTCELL_
#include "cell.hpp"
#include "numericCell.hpp"

/**
 * @brief IntCell komórka z wartością całkowitą
 * Komórka przyjmująca wartości całkowite
 */
class IntCell: public NumericCell{
	int value;
public:
	/**
	 * @brief IntCell Konstruktor domyślny z opcjonalnym parametrem
	 * Konstruktor umożliwiający określenie początkowej wartości komórki
	 *
	 * @param[in] value Wartość początkowa komórki
	 */
	IntCell(int value = 0);

	/**
	 * @brief IntCell Konstruktor z parametrem string
	 * Konstruktor umożliwiający określenie początkowej wartości komórki
	 * Wywołuje funkcję setValue(std::string value)
	 *
	 * @param[in] value Wartość początkowa komórki
	 */
	IntCell(std::string value);

	std::string getValue();

	/**
	 * @brief setValue Metoda ogólna od ustawiania wartości
	 * Ustawia wartość komórki za pomocą wartości string
	 * Wartość ta jest później parsowana
	 * W przypadku braku możliwości jej ustawienia wyrzucany jest wyjątek
	 *
	 * @throws NotNumericValue Brak możliwości przetworzenia wartości tekstowej na liczbową
	 *
	 * @param[in] value ustawiana wartość
	 */
	void setValue(std::string value);


	double getCalcValue();


};

#endif
