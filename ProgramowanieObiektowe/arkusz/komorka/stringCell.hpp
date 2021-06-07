/// @file

#ifndef HEADER_GUARD_STRINGCELL_
#define HEADER_GUARD_STRINGCELL_
#include <string>
#include "cell.hpp"

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

	void* getValue();
	void setValue(void* value);

	/**
	 * @brief getStringValue Metoda od uzyskiwania wartości string
	 * Metoda służy do bezpośredniego uzyskiwania wartości tekstowej komórki bez potrzeby rzutowania i wyłuskiwania
	 * @return wartość string komórki
	 */
	std::string getStringValue();
};

#endif
