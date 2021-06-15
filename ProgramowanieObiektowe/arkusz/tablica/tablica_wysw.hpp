///@file
#ifndef HEADER_GUARD_TABLICA_WYSW_
#define HEADER_GUARD_TABLICA_WYSW_

#include "tablica.hpp"

/**
 * @brief Metoda od wyświetlania arkusza
 * Metoda wyświetla wszystkie elementy znajdujące się w arkuszu
 * @param[in] sheet Arkusz przeznaczony do wyświetlenia 
 */
void DisplaySheet(Sheet sheet);

/**
 * @brief columnWidth Metoda od uzyskiwania szerokości tekstu w kolumnie
 * @param[in] column Kolumna której długość tekstów będzie sprawdzana
 * @return długość najszerszego tekstu
 */
size_t columnWidth(Column column);
#endif
