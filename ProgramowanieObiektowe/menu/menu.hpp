#ifndef HEADER_GUARD
#define HEADER_GUARD

/// @file
#include <string>
#include "../arkusz/tablica/tablica.hpp"

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
Sheet sheetCreator();

/** 
 * \brief Funkcja modyfikująca rozmiar arkusza.
 *
 * Interfejs umożliwiający modyfikację rozmiaru istniejącego arkusza.
 *
 * @param[in,out] arkusz Arkusz przeznaczony do modyfikacji rozmiaru
 */
void expandSheet(Sheet * arkusz);

/** \brief Funkcja wczytywania arkusza
 * Funkcja menu od wczytywania arkusza, ma za zadanie opakowanie funkcji IO wczytajPlik
 * @param [in,out] arkusz Arkusz do którego mogą być wczytane elementy
 *
 */
void loadSheet(Sheet* arkusz);

/** \brief Funkcja menu od zapisu
 *
 * Funkcja menu od zapisu która ma za zadanie przetworzenie i opakowanie funkcji IO zapisPliku
 *
 * @param [in] arkusz Przekazywany arkusz do wykorzystania w funkcji zapisującej do pliku
 */
void saveSheet(Sheet arkusz);


/** \brief Funkcja menu od wyboru wgzględem czego wyznazcza parametry
 *
 * Funkcja menu od wyboru atrybutu tablicy (kolumny lub wiersza)
 * która ma za wyświetlenie parametrów wybranego atrybutu.
 *
 * @param [in] arkusz Przekazywany arkusz do wykorzystania w funkcji wyboru parametrów
 */
void sheetParameters(Sheet arkusz);


/** \brief Funkcja od wyznaczania parametrów wiersza arkusza
 *
 * Funkcja zwraca w postaci tekstowej wszystkie parametry wybranego wiersza
 *
 * @param [in] arkusz Przekazywany arkusz do wykorzystania w funkcji obliczania parametrów
 * @param [in] wiersz Wiersz względem której zostaną obliczone parametry
 */
std::string rowParameters(Sheet arkusz, int wiersz);

/** \brief Funkcja od wyznaczania parametrów kolumny arkusza
 *
 * Funkcja zwraca w postaci tekstowej wszystkie parametry wybranej kolumny
 *
 * @param [in] arkusz Przekazywany arkusz do wykorzystania w funkcji obliczania parametrów
 * @param [in] kolumna Kolumna względem której zostaną obliczone parametry
 */
std::string columnParameters(Sheet arkusz, int kolumna);


/**
 * @brief wprowadzWartosc modyfikuje wartość komórki
 * Frontend od modyfikacji warotści który w zależności od typu komórki zmieni jej wartość
 * @param arkusz Arkusz którego element będzie modyfikowany
 */
void inputValue(Sheet * arkusz);

/** @brief Funkcja od zmiany typu kolumny
 * Interfejs od metody zmieniającej typ kolumny arkusza
 * @param[in] arkusz Arkusz którego kolumna zostaje zmieniona
 */
void changeType(Sheet* arkusz);

/**
 * @brief Funkcja interfejsu od sortowania kolumny
 * Metoda zawiera interfejs do sortowania kolumny z arkusza
 * @param[in,out] Arkusz którego kolumna będzie sortowana
 */
void sort(Sheet* arkusz);

#endif
