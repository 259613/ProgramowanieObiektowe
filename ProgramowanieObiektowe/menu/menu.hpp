#ifndef HEADER_GUARD
#define HEADER_GUARD

/// @file
#include "../arkusz/tablica/tablica.hpp"
#include <string>
#include "../error.hpp"

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


/** \brief Funkcja menu od wyboru względem czego wyznazcza parametry
 * 
 * Funkcja menu od wyboru atrybutu tablicy (kolumny lub wiersza)
 * która ma za wyświetlenie parametrów wybranego atrybutu.
 * Funkcja nie wykona się dla tablic czysto tekstowych.
 *
 * @param [in] arkusz Przekazywany arkusz do wykorzystania w funkcji wyboru parametrów
 */
void parametry(Arkusz arkusz);


/** \brief Funkcja od wyznaczania parametrów wiersza arkusza
 * 
 * Funkcja zwraca w postaci tekstowej wszystkie parametry wybranego wiersza
 *
 * @param [in] arkusz Przekazywany arkusz do wykorzystania w funkcji obliczania parametrów
 * @param [in] wiersz Wiersz względem której zostaną obliczone parametry
 */
std::string parametryWiersza(Arkusz arkusz, int wiersz);

/** \brief Funkcja od wyznaczania parametrów kolumny arkusza
 * 
 * Funkcja zwraca w postaci tekstowej wszystkie parametry wybranej kolumny
 *
 * @param [in] arkusz Przekazywany arkusz do wykorzystania w funkcji obliczania parametrów
 * @param [in] kolumna Kolumna względem której zostaną obliczone parametry
 */
std::string parametryKolumny(Arkusz arkusz, int kolumna);

/** \brief Funkcja zajmująca się "Przechwytywaniem wyjątków" i ich wypisywaniem
 * Wypisuje napotkany "Wyjątek", Nie wypisze nic jeśli wyjątek ma wartość ::BRAK
 * 
 * @param [in] wyjatek Wyjątek który zostanie przechwycony
 */
void obslugaBledow(Wyjatki wyjatek);

/**
 * @brief Funkcja od zmiany typu kolumny w arkuszu
 * 
 * @param [in] arkusz Arkusz w którym jest modyfikowana kolumna
 */
void zmienKolumne(Arkusz *arkusz);

#endif
