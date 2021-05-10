#ifndef HEADER_GUARD_IO_OPERACJE_
#define HEADER_GUARD_IO_OPERACJE_
/// @file
#include "../arkusz/tablica/tablica.hpp"
#include "../error.hpp"

/*! \brief Funkcja zapisu do pliku
 *
 * Funkcja wykonuje zapis do wybranego przez nas pliku, w przypadku błędu zwraca wartość różną od 0.
 * 
 * @param [in] arkusz Arkusz przeznaczony do zapisu
 * @param [in] nazwa Nazwa zapisywanego pliku
 * @return Zwraca stan funkcji "::BRAK - Funkcja wykonana bez błednie", "::PLIK_ACCESS - Niepoprawna nazwa bądź brak dostępu do pliku"
 *
 */
Wyjatki zapisPliku(Arkusz arkusz, std::string nazwa);

/*! \brief Funkcja wczytywania tablicy z pliku
 *
 * Funkcja wykonuje wczytanie arkusza z wybranego pliku, w przypadku niepowodzenia zwraca wartość różną od 0.
 *
 * @param [in,out] arkusz Arkusz do nadpisania wczytywaną tablicą
 * @param [in] nazwa Nazwa wczytywanego pliku
 * @return Zwraca stan funkcji "::BRAK - Funkcja wykonana bez błędnie", "1::PLIK_ACCESS - Niepoprawna nazwa bądź brak dostępu do pliku", "::PLIK_FORMAT - Niepoprawny format" , "::PLIK_ROZMIAR - Niepoprawny rozmiar wczytywanej tablicy"
 */
Wyjatki wczytajPlik(Arkusz * arkusz, std::string nazwa);

#endif