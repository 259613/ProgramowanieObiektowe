///@file
#ifndef HEADER_GUARD_OPERACJE_
#define HEADER_GUARD_OPERACJE_

#include "../arkusz/tablica/tablica.hpp"

/*! \brief Funkcja szukania maksymalnej wartości wiersza
 *
 * Funkcja przeszukuje cały wiersz celem określenia największej wprowadzonej wartości
 * 
 * @param [in] sheet Arkusz przeznaczony do obliczania parametru
 * @param [in] row Wiersz względem którego obliczamy parametr
 *
 * @throws NotNumericValue W przypadku próby zwrócenia wartości nie numerycznej
 *
 * @return Zwraca wartość maksymalną wiersza
 */
double maxRow(Sheet sheet, size_t row);

/*! \brief Funkcja szukania minimalnej wartości wiersza
 *
 * Funkcja przeszukuje cały wiersz celem określenia najmniejszej wprowadzonej wartości
 * 
 * @param [in] sheet Arkusz przeznaczony do obliczania parametru
 * @param [in] row Wiersz względem którego obliczamy parametr
 *
 * @throws NotNumericValue W przypadku próby zwrócenia wartości nie numerycznej
 *
 * @return Zwraca wartość najmniejszą wiersza
 *
 */
double minRow(Sheet sheet, size_t row);

/*! \brief Funkcja licząca sumę elementów wiersza
 *
 * Funkcja zwraca sumę całego wiersza
 * 
 * @param [in] sheet Arkusz przeznaczony do obliczania parametru
 * @param [in] row Wiersz względem którego obliczamy parametr
 *
 * @throws NotNumericValue W przypadku próby zwrócenia wartości nie numerycznej
 *
 * @return Zwraca sumę wszystkich elementów wiersza
 *
 */
double sumRow(Sheet sheet, size_t row);

/**
 * @brief countCalculateableRow Liczy ilość kolumn obliczalnych
 * Liczy ile jest kolumn które mogą być wykorzystywane przy obliczeniach
 * @param sheet Arkusz którego elementy będą liczone
 *
 * @return liczba kolumn typów obliczalnych
 */
int countCalculateableColumns(Sheet sheet);

/*! \brief Funkcja szukania maksymalnej wartości kolumny
 *
 * Funkcja przeszukuje całą kolumne celem określenia największej wprowadzonej wartości
 * 
 * @param [in] column Kolumna względem którego obliczamy parametr
 *
 * @throws NotNumericValue W przypadku próby zwrócenia wartości nie numerycznej
 *
 * @return Zwraca wartość największą kolumny
 *
 */
double maxColumn(Column column);

/*! \brief Funkcja szukania minimalnej wartości kolumny
 *
 * Funkcja przeszukuje całą kolumne celem określenia najmniejszej wprowadzonej wartości
 * 
 * @param [in] column Kolumna względem którego obliczamy parametr
 *
 * @throws NotNumericValue W przypadku próby zwrócenia wartości nie numerycznej
 *
 * @return Zwraca wartość najmniejszą kolumny
 *
 */
double minColumn(Column column);

/*! \brief Funkcja licząca sumę elementów kolumny
 *
 * Funkcja zwraca sumę całej kolumny
 * 
 * @param [in] column Kolumna względem którego obliczamy parametr
 * @return Zwraca sumę wszystkich elementów kolumny
 *
 */
double sumColumn(Column column);

/**
 * @brief sortKolumna Sortuje komórki w kolumnie rosnąco lub malejąco
 * Sortuje kolumne w zależności od podanego parametru descending
 * @param[in,out] column Kolumna przeznaczona do sortowania
 * @param[in] descending Definiuje czy kolumna będzie sortowana rosnąco lub malejąco
 */
void sortColumn(Column *column, bool descending = false);

#endif
