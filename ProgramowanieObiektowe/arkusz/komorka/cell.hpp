/// @file

#ifndef HEADER_GUARD_CELL_
#define HEADER_GUARD_CELL_

/**
 * @brief Interfejs/ klasa czysto wirtualna komórka
 * Interfejs komórka posiadający metody ogólne klas dziedziczących
 */
class Cell{
public:
	/**
	 * @brief getValue Metoda ogólna od uzyskiwania wartości komórki
	 * Metoda zwraca wartość w postaci wskaźnika na typ pusty który wymaga rzutowania
	 * @return pusty wskaźnik na wartość
	 */
	virtual void* getValue()=0;

	/**
	 * @brief setValue Metoda ogólna od ustawiania wartości
	 * Ustawia wartość która po zrzutowaniu znajduje się pod wskaźnikiem
	 * @param[in] value wskaźnik na wartość
	 */
	virtual void setValue(void* value) = 0;


};

#endif
