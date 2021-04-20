#ifndef HEADER_GUARD_UTIL
#define HEADER_GUARD_UTIL
#include <limits>

/** \brief funkcja od wprowadzania wartości typu int
 *
 */
int wprowadzInt();

/** \brief Wprowadź wartość z wyznaczonego zakresu w konsoli
 * Funkcja służy do zwracania wartości wprowadzonej konsolowo, 
 * która mieści się wyznaczonym zakresie.
 *
 * @param [in] min Minimalna wartość jaką można wprowadzić
 * @param [in] max Maksymalna wartość jaką można wprowadzić
 * @return Wartość z zakresu <min; max>
 */
int wprowadzZakres(int min=1, int max = std::numeric_limits<int>::max());

/** \brief Funkcja od czyszczenia buforu strumienia CIN
 *
 * Funkcja ma za zadanie wyczyścić bufor strumienia wejściowego CIN celem wprowadzenia np. string'a
 */
void czyscBufor();

#endif
