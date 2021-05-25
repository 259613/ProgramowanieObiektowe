/// @file

#ifndef HEADER_GUARD_INTCELL_
#define HEADER_GUARD_INTCELL_
#include "cell.hpp"

/**
 * @brief Klasa komórki wartości całkowitych
 * 
 * Klasa komórki posiadającej wartość typu Int
 * 
 */
class intCell : public Cell
{
	/**
	 * @brief Wartość komórki
	 * Wartość string komórki
	 */
	int Value;

public:

	/**
     * @brief Konstruktor komórki całkowitej
     * Konstruktor komórki z wartością początkową 
     * @param[in] Val Wartość początkowa komórki
     */
	intCell(int Val);


	int getValue();


	std::string toString();

	/**
     * @brief setter wartości komórki
     * Setter umożliwiający ustawienie wartości całkowitej w komórce
     * @param[in] Val umożliwia modyfikacje wartości komórki
     */
	void setValue(int Val);

	~intCell(){};
};

#endif