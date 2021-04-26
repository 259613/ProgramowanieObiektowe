#ifndef GUARD_HEADER
#define GUARD_HEADER

#include <cstddef>

/// @file


/*! Definicja/alias typu  int** jako Tablica */
typedef int ** Tablica;


/** 
 * \brief Struktura Arkusz
 * Struktura Arkusz przechowywujaca tablicę i jej rozmiar
 */
struct Arkusz{
    Tablica tablica; /*!< Tablica dwuwymiarowa */  
    size_t iloscKolumn; /*!< Ilość kolumn - rozmiar X */  
    size_t iloscWierszy; /*!< Ilość wierszy - rozmiar Y */  
};


/** 
 * \brief Generuje podgląd tablicy.
 * 
 * Generuje tablicę na konsoli wyświetlając wszystkie zawarte w niej komórki
 * 
 * @param[in] arkusz pobiera arkusz celem jego wyświetlenia
 */
void wyswietlTablica(Arkusz arkusz);

/** 
 * \brief Interfejs użytkownika wprowadzania nowej wartości.
 * 
 * Funkcja interfejsu wprowadzenia wartości do tablicy.
 * Wprowadzana wartość spoza przedziału zostanie zablokowana
 * 
 * @param[in,out] arkusz arkusz która zostaje zmodyfikowany
 */
void wprowadzWartosc(Arkusz * arkusz);

/** 
 * \brief Modyfikacja rozmiaru tablicy.
 * 
 * Funkcja modyfikująca rozmiar arkusza,
 * wartości modyfikowanego arkuszu zostają zachowane 
 * wraz z rozszerzaniem bądź redukcją rozmiaru 
 * (przy redukcji możliwa utrata kolumn/wierszy)
 * 
 * @param[in,out] arkusz przekazywany arkusz celem zmiany jego rozmiaru
 * @param[in] nowyX nowa szerokość tablicy
 * @param[in] nowyY nowa wysokość tablicy
 */
void rozszerzArkusz(Arkusz * arkusz, size_t nowyX, size_t nowyY);

/** 
 * \brief Tworzy nowy arkusz dwuwymiarowy.
 *
 * Funkcja generujaca nowy arkusz o określonym rozmiarze
 * 
 * @param[in] rozmiarX szerokość nowej tablicy
 * @param[in] rozmiarY wysokość nowej tablicy 
 * @return Nowy arkusz z tabilcą dwuwymiarową
 */
Arkusz tworzArkusz(size_t rozmiarX, size_t rozmiarY);

/** 
 * \brief Wstawia określoną wartość do komórki tablicy w arkuszu.
 * 
 * Funkcja wstawia wartość do komórki o określonym adresie
 * 
 * 
 * @param[in,out] arkusz który modyfikujemy
 * @param[in] x określona kolumna
 * @param[in] y określony wiersz
 * @param[in] wart wprowadzana wartość
 */
int modyfikacjaWartosci(Arkusz * arkusz, int x, int y, int wart);
#endif
