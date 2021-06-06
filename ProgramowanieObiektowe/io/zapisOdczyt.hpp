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
 *
 *
 */
void saveFile(Sheet sheet, std::string fileName = "Arkusz.csv");

/*! \brief Funkcja wczytywania tablicy z pliku
 *
 * Funkcja wykonuje wczytanie arkusza z wybranego pliku, w przypadku niepowodzenia zwraca wartość różną od 0.
 *
 * @param [in,out] arkusz Arkusz do nadpisania wczytywaną tablicą
 * @param [in] nazwa Nazwa wczytywanego pliku
 *
 */
void loadFile(Sheet * sheet, std::string fileName);

#endif
