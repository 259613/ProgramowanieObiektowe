#ifndef HEADER_GUARD_TABLICA_
#define HEADER_GUARD_TABLICA_


/// @file

#include <cstddef>
#include "../../error.hpp"
#include "../komorka/cell.hpp"
#include "../komorka/intCell.hpp"
#include "../komorka/stringCell.hpp"
/*! Definicja/alias typu  int jako typ określający komórkę */
typedef Cell Komorka;
/*! Definicja/alias typu  Komórka** jako Tablica komórek */
typedef Komorka *** Tablica;


/** 
 * \brief Struktura Arkusz
 * Struktura Arkusz przechowywujaca tablicę i jej rozmiar
 */
class Arkusz{

    Tablica tablica; /*!< Tablica dwuwymiarowa */  
    size_t iloscKolumn; /*!< Ilość kolumn - rozmiar X */  
    size_t iloscWierszy; /*!< Ilość wierszy - rozmiar Y */
    bool tekstowa; /*! Określa czy tabela jest tylko typu tekstowego */
    public:
    
    /** 
     * \brief Tworzy nową dwuwymiarową tablice.
     *
     * Funkcja generujaca tablicę pustą tablicę komórek o określonym rozmiarze
     * 
     * @param[in] rozmiarX Szerokość nowej tablicy
     * @param[in] rozmiarY Wysokość nowej tablicy 
     * @return Nową tabilce dwuwymiarową z komórkami liczbowymi o wyznaczonych rozmiarach
     */
    static Tablica tworzTablica(size_t kolumny, size_t wiersze);

    /** 
     * \brief Tworzy nową dwuwymiarową tablice typu komórek Int.
     *
     * Funkcja generujaca tablicę tekstową o określonym rozmiarze
     * 
     * @param[in] rozmiarX Szerokość nowej tablicy
     * @param[in] rozmiarY Wysokość nowej tablicy 
     * @return Nową tabilce dwuwymiarową z komórkami liczbowymi o wyznaczonych rozmiarach
     */
    static Tablica tworzTablicaInt(size_t kolumny, size_t wiersze);

    /** 
     * \brief Tworzy nową dwuwymiarową tablice typu tekstowego.
     *
     * Funkcja generujaca tablicę tekstową o określonym rozmiarze
     * 
     * @param[in] rozmiarX Szerokość nowej tablicy
     * @param[in] rozmiarY Wysokość nowej tablicy 
     * @return Nową tabilce dwuwymiarową z komórkami tekstowymi o wyznaczonych rozmiarach
     */
    static Tablica tworzTablicaString(size_t kolumny, size_t wiersze);


    /**
     * \brief Konstruktor tworzący akrusz z tablicą o wyznaczonym rozmiarze i wybranym typie
     * Konstruktor tworzący arkusz z tablicą o wyznaczonej ilości kolumn i wierszy
     * 
     * @param[in] x Szerokość tablicy nowego arkusza
     * @param[in] y Wysokość tablicy nowego arkusza
     */    
    Arkusz(size_t x, size_t y, bool czyTekstowa=false);

    /** 
     * \brief Wstawia określoną wartość do komórki tablicy w arkuszu.
     * 
     * Funkcja wstawia wartość do komórki o określonym adresie
     * 
     * @param[in] x określona kolumna
     * @param[in] y określony wiersz
     * @param[in] wart wprowadzana wartość
     * @return Kod błędu, ::BRAK - Brak błędu, ::TABLICA_ZAKR - indeks spoza zakresu tablicy
     */
    Wyjatki modyfikacjaWartosci(size_t x, size_t y, std::string wartosc);

    /** 
     * \brief Wstawia określoną wartość do komórki tablicy w arkuszu.
     * 
     * Funkcja wstawia wartość do komórki o określonym adresie
     * 
     * @param[in] x określona kolumna
     * @param[in] y określony wiersz
     * @param[in] wart wprowadzana wartość
     * @return Kod błędu, ::BRAK - Brak błędu, ::TABLICA_ZAKR - indeks spoza zakresu tablicy
     */
    Wyjatki modyfikacjaWartosci(size_t x, size_t y, int wartosc);


    /** 
     * \brief Modyfikacja rozmiaru tablicy.
     * 
     * Funkcja modyfikująca rozmiar arkusza,
     * wartości modyfikowanego arkuszu zostają zachowane 
     * wraz z rozszerzaniem bądź redukcją rozmiaru 
     * (przy redukcji możliwa utrata kolumn/wierszy)
     * 
     * @param[in] nowyX nowa szerokość tablicy
     * @param[in] nowyY nowa wysokość tablicy
     * @return Kod błędu, ::BRAK - Brak błędu, ::TABLICA_SIZE - Niepoprawny rozmiar tablicy
     */
    Wyjatki rozszerzArkusz(size_t x, size_t y);
    
    /**
     * \brief Zwraca wartość wybranej komórki  
     * 
     * Funkcja zwraca wartość wybranej komórki... 
     * jeśli koordynaty x lub y są poza zakresem
     * funkcja zwróci najmniejszą możliwą wartość komórki
     * 
     * @param[in] x Wybrana kolumna
     * @param[in] y Wybrany wiersz
     * @return Wartość komórki w przeciwnym wypadku najmniejsza możliwa wartość
     * 
     */
    Komorka& zwrocWartosc(size_t x, size_t y);


    /**
     * \brief Getter ilości kolumn
     * 
     * Funkja zwraca ilość kolumn danego arkusza
     * 
     * @return Ilość kolumn arkusza
     */
    size_t rozmiarX();

    /**
     * \brief Getter ilości wierszy
     * 
     * Funkja zwraca ilość wierszy danego arkusza
     * 
     * @return Ilość wierszy arkusza
     */
    size_t rozmiarY();


    /**
     * @brief zwraca czy tablica jest typu tekstowego
     * Funkja zwraca czy tablica jest typu tekstowego
     * @return true komórki tablicy są typu std::string 
     * @return false komórki są typu int
     */
    bool czyTekstowa();

};


#endif
