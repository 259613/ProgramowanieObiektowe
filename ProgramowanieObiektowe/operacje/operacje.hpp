#ifndef HEADER_GUARD_OPERACJE_
#define HEADER_GUARD_OPERACJE_

#include "../tablica/tablica.hpp"

/*! \brief Funkcja szukania maksymalnej wartości wiersza
 *
 * Funkcja przeszukuje cały wiersz celem określenia największej wprowadzonej wartości
 * 
 * @param [in] arkusz Arkusz przeznaczony do obliczania parametru
 * @param [in] wiersz Wiersz względem którego obliczamy parametr
 * @return Zwraca wartość maksymalną wiersza
 *
 */
int maxWiersz(Arkusz arkusz, size_t wiersz);

/*! \brief Funkcja szukania minimalnej wartości wiersza
 *
 * Funkcja przeszukuje cały wiersz celem określenia najmniejszej wprowadzonej wartości
 * 
 * @param [in] arkusz Arkusz przeznaczony do obliczania parametru
 * @param [in] wiersz Wiersz względem którego obliczamy parametr
 * @return Zwraca wartość najmniejszą wiersza
 *
 */
int minWiersz(Arkusz arkusz, size_t wiersz);

/*! \brief Funkcja licząca sumę elementów wiersza
 *
 * Funkcja zwraca sumę całego wiersza
 * 
 * @param [in] arkusz Arkusz przeznaczony do obliczania parametru
 * @param [in] wiersz Wiersz względem którego obliczamy parametr
 * @return Zwraca sumę wszystkich elementów wiersza
 *
 */
int sumaWiersz(Arkusz arkusz, size_t wiersz);


/*! \brief Funkcja szukania maksymalnej wartości kolumny
 *
 * Funkcja przeszukuje całą kolumne celem określenia największej wprowadzonej wartości
 * 
 * @param [in] arkusz Arkusz przeznaczony do obliczania parametru
 * @param [in] kolumna Kolumna względem którego obliczamy parametr
 * @return Zwraca wartość największą kolumny
 *
 */
int maxKolumna(Arkusz arkusz, size_t kolumna);

/*! \brief Funkcja szukania minimalnej wartości kolumny
 *
 * Funkcja przeszukuje całą kolumne celem określenia najmniejszej wprowadzonej wartości
 * 
 * @param [in] arkusz Arkusz przeznaczony do obliczania parametru
 * @param [in] kolumna Kolumna względem którego obliczamy parametr
 * @return Zwraca wartość najmniejszą kolumny
 *
 */
int minKolumna(Arkusz arkusz, size_t kolumna);

/*! \brief Funkcja licząca sumę elementów kolumny
 *
 * Funkcja zwraca sumę całej kolumny
 * 
 * @param [in] arkusz Arkusz przeznaczony do obliczania parametru
 * @param [in] kolumna Kolumna względem którego obliczamy parametr
 * @return Zwraca sumę wszystkich elementów kolumny
 *
 */
int sumaKolumna(Arkusz arkusz, size_t kolumna);

#endif
