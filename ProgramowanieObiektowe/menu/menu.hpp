#ifndef HEADER_GUARD
#define HEADER_GUARD

/// @file
#include "../tablica/tablica.hpp"



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
 * Funkcja zawierająca interfejs umożliwiający tworzenie nowego Arkusza z tablicą  dwuwymiarową.
 * 
 * @return Nowy Arkusz do wykorzystywania w programie 
 */
Arkusz tworzArkusz();

/** 
 * \brief Funkcja modyfikująca rozmiar arkusza.
 * 
 * Interfejs umożliwiający modyfikację rozmiaru istniejącego arkusza.
 * 
 * @param[in,out] arkusz Arkusz przeznaczony do modyfikacji rozmiaru
 */
void rozszerzArkusz(Arkusz * arkusz);

/** \brief Funkcja wczytywania arkusza
 * Funkcja menu od wczytywania arkusza, ma za zadanie opakowanie funkcji IO wczytajPlik
 * @param [in,out] arkusz Arkusz do którego mogą być wczytane elementy
 * 
 */
void wczytanie(Arkusz * arkusz);

/** \brief Funkcja menu od zapisu
 * 
 * Funkcja menu od zapisu która ma za zadanie przetworzenie i opakowanie funkcji IO zapisPliku
 *
 * @param [in] arkusz Przekazywany arkusz do wykorzystania w funkcji zapisującej do pliku
 */
void zapis(Arkusz arkusz);



#endif
