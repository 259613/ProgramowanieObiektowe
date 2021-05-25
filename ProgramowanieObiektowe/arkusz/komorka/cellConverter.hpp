/// @file
#ifndef HEADER_GUARD_CELL_CONVERTER_
#define HEADER_GUARD_CELL_CONVERTER_
#include "intCell.hpp"
#include "stringCell.hpp"

/**
 * @brief Funkcja konwertująca komórkę string na komórkę int
 * 
 * @param convertedCell komórka do przetworzenia
 * @return intCell* nowa komórka typu int
 */
intCell * toIntCell(stringCell convertedCell);

/**
 * @brief Funkcja konwertująca komórkę int na komórkę string
 * 
 * @param convertedCell komórka do przetworzenia
 * @return stringCell* nowa komórka typu string
 */
stringCell * toStringCell(intCell convertedCell);

#endif