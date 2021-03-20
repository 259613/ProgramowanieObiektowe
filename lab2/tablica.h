#ifndef GUARD_HEADER
#define GUARD_HEADER
/// @file

/** \brief generuje podgląd tablicy
 * Generuje tablicę na konsoli wyświetlając wszystkie zawarte w niej komórki
 * @param[in] tablica pobiera tablicę celem jej wyświetlenia
 * @param[in] rozX pobiera szerokość tablicy
 * @param[in] rozY pobiera wysokość tablicy
 */
void wyswietlTablica(int** tablica, int rozX, int rozY);

/** \brief interfejs użytkownika wprowadzania nowej wartości
 * Funkcja interfejsu wprowadzenia wartości do tablicy.
 * Wprowadzana wartość spoza przedziału zostanie zablokowana
 * @param[in,out] tablica tablica która zostaje zmodyfikowana
 * @param[in] rozX szerokość modyfikowanej tablicy
 * @param[in] rozY wysokość modyfikowanej tablicy
 */
void wprowadzWartosc(int** tablica, int rozX, int rozY);

/** \brief modyfikacja rozmiaru tablicy
 * Funkcja modyfikująca rozmiar tablicy,
 * wartości modyfikowanej tablicy zostają zachowane 
 * wraz z rozszerzaniem bądź redukcją rozmiaru 
 * (przy redukcji możliwa utrata kolumn/wierszy)
 * @param[in,out] tablica modyfikowana tablica
 * @param[in,out] rozmiarX szerokość przed zmianą, zostaje nadpisany przez nowyX
 * @param[in,out] rozmiarY wysokość przed zmianą, zostaje nadpisany przez nowyY
 * @param[in] nowyX nowa szerokość tablicy
 * @param[in] nowyY nowa wysokość tablicy
 */
void rozszerzTablice(int*** tablica, int* rozmiarX, int* rozmiarY, int nowyX, int nowyY);

/** \brief tworzy nową tablice dwuwymiarową
 * Funkcja generujaca nową tablicę o określonym rozmiarze
 * @param[in] rozmiarX szerokość nowej tablicy
 * @param[in] rozmiarY wysokość nowej tablicy 
 * @return Nowa tablica dwuwymiarowa
 */
int ** tworzTablica(int* rozmiarX,int* rozmiarY);

/** \brief wstawia określoną wartość do komórki w tablicy
 * Funkcja wstawia wartość do komórki o określonym adresie
 * FUNKCJA NIE POSIADA KONTROLI POPRAWNOŚCI
 * @param[in,out] tablica tablica do której wprowadzamy dane
 * @param[in] x określona kolumna
 * @param[in] y określony wiersz
 * @param[in] wart wprowadzana wartość
 */
void modyfikacjaWartosci(int** tablica, int x, int y, int wart);
#endif
