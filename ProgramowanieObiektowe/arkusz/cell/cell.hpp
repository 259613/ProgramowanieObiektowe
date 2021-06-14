/// @file

#ifndef HEADER_GUARD_CELL_
#define HEADER_GUARD_CELL_


#include "stringinterface.hpp"

/**
 * @brief Interfejs/ klasa czysto wirtualna komórka
 * Interfejs komórka posiadający metody ogólne klas dziedziczących
 */
class Cell:public StringInterface{
public:
	/**
	 * @brief operator + Dodawanie wartości komórki z wartością double
	 * Przeciążenie operatora dodawania w przypadku wystąpienia wartości double przy sumie komórki
	 * @param[in] rhs wartość którą sumujemy z komórką
	 * @return sumę wartości
	 */
	virtual double operator+(double rhs)=0;

	/**
	 * @brief operator > operator porównania
	 * Operator porównania czy obecny obiekt jest większy od drugiej komórki,
	 * Zwracana wartość w przypadku komórek które nie są ze sobą pokrewne w dziedziczeniu
	 * mogą się róznić.
	 *
	 * @param rhs komórka którą porównujemy
	 *
	 * @return Czy wartość obecnej komórki jest większa od komórki rhs
	 */
	virtual bool operator>(Cell& rhs)=0;

	/**
	 * @brief operator < operator porównania
	 * perator porównania
	 * Operator porównania czy obecny obiekt jest większy od drugiej komórki,
	 * Zwracana wartość w przypadku komórek które nie są ze sobą pokrewne w dziedziczeniu
	 * mogą się róznić.
	 *
	 * @param rhs komórka którą porównujemy
	 *
	 * @return Czy wartość obecnej komórki jest większa od komórki rhs
	 */
	virtual bool operator<(Cell& rhs)=0;
};

#endif
