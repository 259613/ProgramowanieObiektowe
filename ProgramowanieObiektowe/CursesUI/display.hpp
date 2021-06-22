///@file

#include "../arkusz/tablica/tablica.hpp"
#include <ncurses.h>

/**
 * @brief Display Klasa wyświetlacza Curses
 */
class Display{
    size_t height;
    size_t width;
    WINDOW *display;
    Sheet *sheet;
    protected:
	/**
	 * @brief simpleControl Metoda obsługi klawiatury w prostym menu
	 * @return wartości 1 i -1 służą do poruszania strzałkami w górę i w dół, wartość 0 w przypadku kliknięcia klawisza enter
	 */
    int simpleControl();
    public:
	/**
	 * @brief Display konstruktor domniemany wyświetlacza
	 */
    Display();
	/**
	 * @brief refreshDisplay Odświeża w pełni wyświetlacz curses
	 * Potrafi wykryć zmianę rozmiaru okna terminala
	 */
    void refreshDisplay();
	/**
	 * @brief simpleMenu Metoda wyświetlająca proste menu
	 * @return Indeks wybranego elementu
	 */
    int simpleMenu();
};

