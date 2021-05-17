/// @file

#ifndef HEADER_GUARD_CELL_
#define HEADER_GUARD_CELL_
#include "../../error.hpp"
#include <string>

/**
 * @brief Prototyp klasy komórki
 * 
 * Klasa prototypowa komórki, posiadająca ogólny szkielet tego co komórka powinna zawierać
 * 
 */
class Cell
{
	/**
	 * @brief Czy komórka służy do obliczeń
	 * Służy do określania tego czy komórka może być wykorzystywana w obliczeniach
	 */
	bool calculate; 

public:

	/**
	 * @brief Konstruktor domyślny komórki 
	 * konstruktor tworzy nową "nieobliczalną" komórkę
	 */
	Cell()
	{
		calculate = false;
	}

	/**
	 *  \brief Konstruktor komórki
	 * Konstruktor komórki określający czy komórka może być "obliczalna"
	 * 
	 * @param[in] isCalc czy komórka jest obliczalna
	 */
	Cell(bool isCalc) : calculate(isCalc) {}

	/**
	 * \brief Metoda od pobierania wartości matematycznej
	 * Zwraca wartość typu Int
	 * @return Zwraca wartość typu int, jeśli komórka jest innego typu niż int zwraca 0.
	 */
	virtual int getValue();

	/**
	 * \brief Metoda od pobierania wartości ciągu znaków
	 * Zwraca wartość typu String - ciąg znaków do wykorzystywania przykładowo w wypisywaniu
	 * @return Zwraca wartość typu string
	 */
	virtual std::string toString();

	/**
	 * \brief Sprawdź czy komórka może posłużyć w obliczeniach
	 * Metoda służy do sprawdzania czy typ komórki umożliwia jej branie udziału w funkcjach arytmetycznych
	 * @return Zwraca wartość logiczną 'true' dla elementów które można obliczać a 'false' dla tych które nie mogą być obliczane.
	 */
	bool isCalcualteable();

	/**
	 * @brief Zwraca arytmetyczną sumę komórek
	 * Zwraca sumę komórek uzyskanych za pomocą wartości zwracanych przez getValue() obu sumowanych komórek
	 * @param[in] c1 druga sumowana komórka
	 * @return int Suma wartości komórek
	 */
	int operator+(Cell c1);


	/**
	 * @brief Zwraca sumę wartości Int z komórką
	 * Zwraca sumę komórki i zmiennej całkowitej 
	 * @param[in] wart wartość całkowita
	 * @return int Suma wartości komórek
	 */
	int operator+(int wart);
};

#endif