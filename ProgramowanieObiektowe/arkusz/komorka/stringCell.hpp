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

	std::string getValue();
	void setValue(std::string value);

};

#endif
