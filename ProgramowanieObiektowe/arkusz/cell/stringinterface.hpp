#ifndef STRINGINTERFACE_HPP
#define STRINGINTERFACE_HPP
/// @file
#include <string>

/**
 * @brief Intefejs elementów przyjmujących/zwracających elementy string.
 */
class StringInterface
{
public:
	/**
	 * @brief getValue Metoda ogólna od uzyskiwania wartości komórki
	 * Metoda zwraca wartość w postaci wartości tekstowej komórki
	 * @return zawartość tekstowa komórki
	 */
	virtual std::string getValue()=0;

	/**
	 * @brief setValue Metoda ogólna od ustawiania wartości
	 * Ustawia wartość komórki za pomocą wartości string
	 * @param[in] value ustawiana wartość
	 */
	virtual void setValue(std::string value) = 0;

};

#endif // STRINGINTERFACE_HPP
