#include "../tablica/tablica.hpp"
#ifndef HEADER_GUARD_
#define HEADER_GUARD_
/// @file

/*! \brief Funkcja zapisu do pliku
 *
 * Funkcja wykonuje zapis do wybranego przez nas pliku, w przypadku błędu zwraca wartość różną od 0.
 * 
 * @param [in] arkusz Arkusz przeznaczony do zapisu
 * @param [in] nazwa Nazwa zapisywanego pliku
 * @return Zwraca stan funkcji "0 - Funkcja wykonana", "1 - Niepoprawna nazwa pliku"
 *
 */
int zapisPliku(Arkusz arkusz, std::string nazwa);

/*! \brief Funkcja wczytywania tablicy z pliku
 *
 * Funkcja wykonuje wczytanie arkusza z wybranego pliku, w przypadku niepowodzenia zwraca wartość różną od 0.
 *
 * @param [in,out] arkusz Arkusz do nadpisania wczytywaną tablicą
 * @param [in] nazwa Nazwa wczytywanego pliku
 * @return Zwraca stan funkcji "0 - Funkcja wykonana", "1 - Niepoprawna nazwa pliku", "2 - Niepoprawny format" , "3 - Niepoprawny rozmiar"
 */
int wczytajPlik(Arkusz * arkusz, std::string nazwa);

#endif