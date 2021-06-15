/// @file

#ifndef HEADER_GUARD_STRINGCELL_
#define HEADER_GUARD_STRINGCELL_
#include "cell.hpp"


/**
 * @brief StringCell Komórka tekstowa
 * Klasa komórki przyjmującej wartości tekstowe
 */
class StringCell: public Cell{
	std::string value;
public:
	/**
	 * @brief StringCell Konstruktor domyślny z opcjonalnym parametrem.
	 *
	 * Konstruktor umożliwiający określenie początkowej wartości komórki.
	 *
	 * @param[in] value Wartość początkowa komórki
	 */
	StringCell(std::string value = "?");

	std::string getValue();
	void setValue(std::string value);

	/**
	 * @brief operator + Operator dodawania zwracający wartość rhs.
	 *
	 * Operator dodawania w przypadku komórki która przyjmuje tylko wartości tekstowe
	 * zwraca domyślnie wartość wprowadzoną w parametrze operator+ .
	 *
	 * @param rhs Zwracana wartość
	 *
	 * @return Wartość wprowadzona w argumencie rhs
	 */
	double operator+(double rhs);

	/**
	 * @brief operator > Operator porównania dla komórek tekstowych
	 *
	 * Operator porównania czy obecny obiekt jest większy od drugiej komórki.
	 *
	 * @return Czy obecna komórka jest wyżej leksykalnie
	 */
	bool operator>(StringCell&);

	/**
	 * @brief operator > operator porównania pozostałych typów komórek.
	 *
	 * Zwracana wartość w przypadku komórek które nie są klasy StringCell
	 * uzyskiwana jest wartość true - komórka po prawej stronie będzie dominowała w porównaniu
	 *
	 * @param rhs komórka którą porównujemy
	 *
	 * @return Wartość logiczna True
	 */
	bool operator>(Cell&);

	/**
	 * @brief operator < Operator porównania dla komórek tekstowych
	 *
	 * Operator porównania czy obecny obiekt jest większy od drugiej komórki.
	 *
	 * @return Czy obecna komórka jest niżej leksykalnie.
	 */
	bool operator<(StringCell&);

	/**
	 * @brief operator < operator porównania pozostałych typów komórek
	 *
	 * Zwracana wartość w przypadku komórek które nie są klasy StringCell
	 * uzyskiwana jest wartość true - komórka po prawej stronie będzie dominowała w porównaniu
	 *
	 * @param rhs komórka którą porównujemy
	 *
	 * @return Wartość logiczna True
	 */
	bool operator<(Cell&);

};

#endif
