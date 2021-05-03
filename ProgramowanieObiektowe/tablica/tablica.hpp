#ifndef HEADER_GUARD_TABLICA_
#define HEADER_GUARD_TABLICA_
#include <cstddef>


/// @file

/*! Definicja/alias typu  int jako typ określający komórkę */
typedef int Komorka;
/*! Definicja/alias typu  Komórka** jako Tablica komórek */
typedef Komorka ** Tablica;


/** 
 * \brief Struktura Arkusz
 * Struktura Arkusz przechowywujaca tablicę i jej rozmiar
 */
class Arkusz{

    Tablica tablica; /*!< Tablica dwuwymiarowa */  
    size_t iloscKolumn; /*!< Ilość kolumn - rozmiar X */  
    size_t iloscWierszy; /*!< Ilość wierszy - rozmiar Y */

    public:
    
    /** 
     * \brief Tworzy nową dwuwymiarową tablice.
     *
     * Funkcja generujaca tablicę o określonym rozmiarze
     * 
     * @param[in] rozmiarX Szerokość nowej tablicy
     * @param[in] rozmiarY Wysokość nowej tablicy 
     * @return Nową tabilce dwuwymiarową o wyznaczonych rozmiarach
     */
    static Tablica tworzTablica(size_t kolumny, size_t wiersze);

    /**
     * \brief Konstruktor tworzący akrusz z tablicą o wyznaczonym rozmiarze
     * Konstruktor tworzący arkusz z tablicą o wyznaczonej ilości kolumn i wierszy
     * 
     * @param[in] x Szerokość tablicy nowego arkusza
     * @param[in] y Wysokość tablicy nowego arkusza
     */    
    Arkusz(size_t x, size_t y);

    /** 
     * \brief Wstawia określoną wartość do komórki tablicy w arkuszu.
     * 
     * Funkcja wstawia wartość do komórki o określonym adresie
     * 
     * @param[in] x określona kolumna
     * @param[in] y określony wiersz
     * @param[in] wart wprowadzana wartość
     * @return Kod błędu
     */
    int modyfikacjaWartosci(size_t x, size_t y, Komorka wartosc);

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
     * @return Kod błędu
     */
    int rozszerzArkusz(size_t x, size_t y);
    
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
    Komorka zwrocWartosc(size_t x, size_t y);


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

#endif
