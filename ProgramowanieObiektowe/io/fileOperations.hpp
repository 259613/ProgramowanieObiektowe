#ifndef HEADER_GUARD_IO_OPERACJE_
#define HEADER_GUARD_IO_OPERACJE_
/// @file
#include "../arkusz/tablica/tablica.hpp"
#include "../error.hpp"



/*! \brief Funkcja zapisu do pliku
 *
 * Funkcja wykonuje zapis do wybranego przez nas pliku
 * 
 * @param [in] sheet Arkusz przeznaczony do zapisu
 * @param [in] fileName Nazwa zapisywanego pliku
 *
 * @throws BadFileException W przypadku braku dostępu do zapisu
 */
void saveFile(Sheet sheet, std::string fileName = "Arkusz.csv");

/*! \brief Funkcja wczytywania tablicy z pliku
 *
 * Funkcja wykonuje wczytanie arkusza z wybranego pliku.
 *
 * @param [in,out] sheet Arkusz do nadpisania wczytywaną tablicą
 * @param [in] fileName Nazwa wczytywanego pliku
 *
 * @throws BadFileException W przypadku braku pliku lub braku dostępu
 */
void loadFile(Sheet * sheet, std::string fileName);

#endif
