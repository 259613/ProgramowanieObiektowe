/// @file
#ifndef HEADER_GUARD_CELL_TYPES_
#define HEADER_GUARD_CELL_TYPES_

#include <cstddef>

/**
 * @brief Enum do monitorowania dostępnych typów komórek.
 * Umożliwia bezproblemowe określanie jakiego typu jest kolumna czy komórka.
 */
enum class cellType{
    typeGeneric = 'G',
    typeInt = 'I',
    typeString = 'S'
};

constexpr cellType calculateableTypes[] = {cellType::typeInt}; /// Dostępne typy komórek obliczeniowych
constexpr size_t calculateableTypesCount = 1;  /// Ilość typów obliczeniowych

#endif