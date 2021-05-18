#ifndef HEADER_GUARD_TABLICA_WYSW_
#define HEADER_GUARD_TABLICA_WYSW_

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
 * Wprowadzana wartość spoza przedziału zostanie zablokowana.
 * W zależności od typu arkusza umożliwia wprowadzenie wartości
 * tekstowej bądź liczbowej.
 * 
 * @param[in,out] arkusz arkusz która zostaje zmodyfikowany
 */
void wprowadzWartosc(Arkusz * arkusz);

#endif
