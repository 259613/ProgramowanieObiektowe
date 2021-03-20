#ifndef HEADER_GUARD
#define HEADER_GUARD
/// @file

/*! \brief funkcja kontrolująca działanie programu
 * Funkcja zajmująca się obsługą menu programu
 * zarządza tym co będzie wywoływane
 */
void obslugaMenu();

/*! \brief funkcja tworząca menu
 * Funkcja od tworzenia listy dostępnych pozycji menu
 */
void generujMenu();

/*! \brief funkcja tworząca nową tablicę
 * Funkcja zawierająca interfejs umożliwiający tworzenie nowej tablicy dwuwymiarowej
 * zwraca wskaźnik na wskaźnik typu int
 * @param rozmiarX [out] wartość nowej szerokości tablicy
 * @param rozmiarY [out] wartość nowej wysokości tablicy
 * @return Tablicę do do wykorzystania w arkuszu
 */
int ** tworzArkusz(int* rozmiarX,int* rozmiarY);

/*! \brief funkcja modyfikująca rozmiar arkusza
 * Interfejs umożliwiający rozszerzanie istniejącego arkusza
 * @param tablica [in,out] wskaźnik na poprzednią tablicę arkusza
 * @param rozmiarX [in,out] parametr zawiera szerokość modyfikowanego arkusza, parametr jest modyfikowany zawierając nową szerokość
 * @param rozmiarY [in,out] parametr zawiera wysokość modyfikowanego arkusza, parametr jest modyfikowany zawierając nową wysokość
 */
void rozszerzArkusz(int *** tablica, int * rozmiarX, int * rozmiarY);

#endif
