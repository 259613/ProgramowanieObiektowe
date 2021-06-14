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
	 * @brief StringCell Konstruktor domyślny z opcjonalnym parametrem
	 * Konstruktor umożliwiający określenie początkowej wartości komórki
	 *
	 * @param[in] value Wartość początkowa komórki
	 */
	StringCell(std::string value = "?");

	std::string getValue();
	void setValue(std::string value);

	/**
	 * @brief operator + Operator dodawania zwracający wartość rhs
	 * Operator dodawania w przypadku komórki która przyjmuje tylko wartości tekstowe
	 * zwraca domyślnie wartość wprowadzoną w parametrze operator+
	 *
	 * @param rhs Zwracana wartość
	 *
	 * @return Wartość wprowadzona w argumencie rhs
	 */
	double operator+(double rhs);

	/**
	 * @brief operator > operator porównania
	 * perator porównania
	 * Operator porównania czy obecny obiekt jest większy od drugiej komórki,
	 * Zwracana wartość w przypadku komórek które nie są klasy StringCell
	 * uzyskiwana jest wartość true - komórka po prawej stronie będzie dominowała w porównaniu
	 *
	 * @param rhs komórka którą porównujemy
	 *
	 * @return Czy wartość obecnej komórki jest większa od komórki rhs
	 */
	bool operator>(Cell&);

	/**
	 * @brief operator < operator porównania
	 * perator porównania
	 * Operator porównania czy obecny obiekt jest mniejszy od drugiej komórki,
	 * Zwracana wartość w przypadku komórek które nie są klasy StringCell
	 * uzyskiwana jest wartość true - komórka po prawej stronie będzie dominowała w porównaniu
	 *
	 * @param rhs komórka którą porównujemy
	 *
	 * @return Czy wartość obecnej komórki jest większa od komórki rhs
	 */
	bool operator<(Cell&);

};

#endif
