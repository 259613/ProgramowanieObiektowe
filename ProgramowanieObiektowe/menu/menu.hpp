#ifndef HEADER_GUARD
#define HEADER_GUARD
/// @file

/** 
 * \brief Funkcja kontrolująca działanie programu.
 * 
 * Funkcja zajmująca się obsługą menu programu
 * zarządza tym co będzie wywoływane
 */
void obslugaMenu();

/**
 * \brief Funkcja tworząca menu.
 * 
 * Funkcja od tworzenia listy dostępnych pozycji menu.
 */
void generujMenu();

/**
 * \brief Funkcja tworząca nową tablicę.
 * 
 * Funkcja zawierająca interfejs umożliwiający tworzenie nowej tablicy dwuwymiarowej
 * zwraca wskaźnik na wskaźnik typu int.
 * 
 * @param[out] rozmiarX wartość nowej szerokości tablicy
 * @param[out] rozmiarY wartość nowej wysokości tablicy
 * @return Tablicę do do wykorzystania w arkuszu
 */
int ** tworzArkusz(int* rozmiarX,int* rozmiarY);

/** 
 * \brief Funkcja modyfikująca rozmiar arkusza.
 * 
 * Interfejs umożliwiający rozszerzanie istniejącego arkusza.
 * 
 * @param[in,out] tablica wskaźnik na poprzednią tablicę arkusza
 * @param[in,out] rozmiarX parametr zawiera szerokość modyfikowanego arkusza, parametr jest modyfikowany zawierając nową szerokość
 * @param[in,out] rozmiarY parametr zawiera wysokość modyfikowanego arkusza, parametr jest modyfikowany zawierając nową wysokość
 */
void rozszerzArkusz(int *** tablica, int * rozmiarX, int * rozmiarY);

/** \brief Funkcja od czyszczenia buforu strumienia CIN
 *
 * Funkcja ma za zadanie wyczyścić bufor strumienia wejściowego CIN celem wprowadzenia np. string'a
 */
void czyscBufor();

/** \brief Funkcja wczytywania tablicy
 * Funkcja menu od wczytywania tablicy, ma za zadanie opakowanie funkcji IO wczytajPlik
 * @param [out] rozmiarX szerokość tablicy wczytanej
 * @param [out] rozmiarY wysokość tablicy wczytanej
 * @return Tablica do wykorzystania w arkuszu
 * 
 */
int ** wczytanie(int * rozmiarX, int * rozmiarY);

/** \brief Funkcja menu od zapisu
 * 
 * Funkcja menu od zapisu która ma za zadanie przetworzenie i opakowanie funkcji IO zapisPliku
 *
 * @param [in] tablica przekazywana jest tablica do odczytu w zapisie do pliku
 * @param [in] rozmiarX szerokość zczytywanego arkusza
 * @param [in] rozmiarY wysokość zczytywanego arkusza 
 */
void zapis(int ** tablica, int rozmiarX, int rozmiarY);




#endif
