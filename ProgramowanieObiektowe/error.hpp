/// @file
#ifndef HEADER_GUARD_ERROR_
#define HEADER_GUARD_ERROR_
#include <stdexcept>
/** \brief Wyjątki występujące w programie
 * Typ wyliczeniowy który zawiera wszystkie występujące wyjątki
 */
enum class Wyjatki : unsigned int{
    
    BRAK = 0, /// Brak błędów
    
    TABLICA_SIZE = 1, /// Próba dostępu do elementu poza zakresem tablicy 
    TABLICA_ZAKR = 2, /// Próba utworzenia tablicy o niepoprawnym rozmiarze

    PLIK_ACCESS = 10, /// Niepoprawna nazwa lub brak dostępu do pliku 
    PLIK_FORMAT = 11, /// Niepoprawny format wczytywanego pliku
    PLIK_ROZMIAR = 12 /// Rozmiar wczytywanej tablicy nie jest poprawny

};

struct BadFileException : public std::exception
{
	const char * what() const throw()
	{
		return "Brak dostępu do pliku lub nie istnieje";
	}
};

#endif
