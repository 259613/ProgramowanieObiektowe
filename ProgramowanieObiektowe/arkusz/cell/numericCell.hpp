#ifndef CALCULATEABLEINTERFACE_HPP
#define CALCULATEABLEINTERFACE_HPP
/// @file
#include "cell.hpp"


/**
 * @brief NumericCell komórki liczbowe
 * Ogólna klasa abstrakcyjna komórek liczbowych
 * które mogą posługiwać się wartościami rzeczywistymi
 */
class NumericCell : public Cell
{
public:
	/**
	 * @brief getCalcValue Metoda klasy umożliwiająca bezpośrednie uzyskanie wartości double
	 * Metoda umożliwia uzyskanie wartości bezpośrednie bez potrzeby parsowania wartości
	 *
	 * @return wartość komórki
	 */
	virtual double getCalcValue()=0;


	double operator+(double rhs);

	/**
	 * @brief operator > operator porównania
	 * Operator porównania czy obecny obiekt jest większy od drugiej komórki,
	 * Zwracana wartość w przypadku komórek które nie dziedziczą po RealCell
	 * porównanie zwraca wartość FALSE
	 *
	 * @param rhs komórka którą porównujemy
	 *
	 * @return Czy wartość obecnej komórki jest większa od komórki rhs, jeśli komórka nie jest typu RealCell zwraca false
	 */
	bool operator>(Cell&);

	/**
	 * @brief operator < operator porównania
	 * Operator porównania czy obecny obiekt jest mniejszy od drugiej komórki,
	 * Zwracana wartość w przypadku komórek które nie dziedziczą po RealCell
	 * porównanie zwraca wartość FALSE
	 *
	 * @param rhs komórka którą porównujemy
	 *
	 * @return Czy wartość obecnej komórki jest większa od komórki rhs, jeśli komórka nie jest typu RealCell zwraca false
	 */
	bool operator<(Cell&);
};

#endif // CALCULATEABLEINTERFACE_HPP
