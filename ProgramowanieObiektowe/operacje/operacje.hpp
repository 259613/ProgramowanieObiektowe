///@file
#ifndef HEADER_GUARD_OPERACJE_
#define HEADER_GUARD_OPERACJE_

#include "../arkusz/tablica/tablica.hpp"

/*! \brief Funkcja szukania maksymalnej wartości wiersza
 *
 * Funkcja przeszukuje cały wiersz celem określenia największej wprowadzonej wartości
 * 
 * @param [in] arkusz Arkusz przeznaczony do obliczania parametru
 * @param [in] wiersz Wiersz względem którego obliczamy parametr
 * @return Zwraca wartość maksymalną wiersza
 *
 */
int maxWiersz(Sheet sheet, size_t row);

/*! \brief Funkcja szukania minimalnej wartości wiersza
 *
 * Funkcja przeszukuje cały wiersz celem określenia najmniejszej wprowadzonej wartości
 * 
 * @param [in] arkusz Arkusz przeznaczony do obliczania parametru
 * @param [in] wiersz Wiersz względem którego obliczamy parametr
 * @return Zwraca wartość najmniejszą wiersza
 *
 */
int minWiersz(Sheet sheet, size_t row);

/*! \brief Funkcja licząca sumę elementów wiersza
 *
 * Funkcja zwraca sumę całego wiersza
 * 
 * @param [in] arkusz Arkusz przeznaczony do obliczania parametru
 * @param [in] wiersz Wiersz względem którego obliczamy parametr
 * @return Zwraca sumę wszystkich elementów wiersza
 *
 */
int sumaWiersz(Sheet sheet, size_t row);


/*! \brief Funkcja szukania maksymalnej wartości kolumny
 *
 * Funkcja przeszukuje całą kolumne celem określenia największej wprowadzonej wartości
 * 
 * @param [in] column Kolumna względem którego obliczamy parametr
 * @return Zwraca wartość największą kolumny
 *
 */
int maxKolumna(Column column);

/*! \brief Funkcja szukania minimalnej wartości kolumny
 *
 * Funkcja przeszukuje całą kolumne celem określenia najmniejszej wprowadzonej wartości
 * 
 * @param [in] column Kolumna względem którego obliczamy parametr
 * @return Zwraca wartość najmniejszą kolumny
 *
 */
int minKolumna(Column column);

/*! \brief Funkcja licząca sumę elementów kolumny
 *
 * Funkcja zwraca sumę całej kolumny
 * 
 * @param [in] column Kolumna względem którego obliczamy parametr
 * @return Zwraca sumę wszystkich elementów kolumny
 *
 */
int sumaKolumna(Column column);

/**
 * @brief sortKolumna Sortuje komórki w kolumnie rosnąco lub malejąco
 * Sortuje kolumne w zależności od podanego parametru descending
 * @param[in,out] column Kolumna przeznaczona do sortowania
 * @param[in] descending Definiuje czy kolumna będzie sortowana rosnąco lub malejąco
 */
void sortKolumna(Column *column, bool descending = false);

#endif
