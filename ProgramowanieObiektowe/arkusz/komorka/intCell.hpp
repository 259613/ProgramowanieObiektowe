/// @file

#ifndef HEADER_GUARD_INTCELL_
#define HEADER_GUARD_INTCELL_
#include "cell.hpp"

class IntCell: public Cell{
	int value;
public:
	IntCell(int value = 0);
	void* getValue();
	void setValue(void* value);

	/**
	 * @brief getIntValue Metoda klasy umożliwiająca bezpośrednie uzyskanie wartości int
	 * Metoda umożliwia uzyskanie wartości bezpośrednie bez potrzeby rzutowanai i wyłuskiwania wskaźnika void* na wartość
	 * @return wartość komórki
	 */
	int getIntValue();
};

#endif
