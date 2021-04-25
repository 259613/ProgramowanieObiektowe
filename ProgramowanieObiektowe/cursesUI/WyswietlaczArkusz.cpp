#include <iostream>
#include <cstdlib>
#include <ncurses.h>
#include <string>
#include <sstream>

#include "WyswietlaczArkusz.hpp"
#include "../tablica/tablica.hpp"

namespace CursesMenu
{
    WyswietlaczArkusz::WyswietlaczArkusz(int **tablica, int x, int y) { zmienRozmiar(tablica, x, y); }
    void WyswietlaczArkusz::zmienRozmiar(int **tablica, int x, int y){
        this->tablica = tablica;
        rozmiarX = x;
        rozmiarY = y;
    }

    void WyswietlaczArkusz::wyswietlArkusz(int x, int y){
        
        use_default_colors();
        init_pair(2, COLOR_RED, 0);
        init_pair(1, -1, -1);
        for(int i = 0; i < rozmiarY; i++)
        {
            for(int j = 0; j < rozmiarX; j++)
            {

            move(3+(i*2), 3+(j*8));
            if(y==i && x == j){
                addstr("> ");
                attron(COLOR_PAIR(2));
            }
            else{
                addstr("  ");
            }
            addstr(stringLiczba(j,i).c_str());
            attron(COLOR_PAIR(1));
            }            
        }
}

    void WyswietlaczArkusz::obslugaArkusz(){
        initscr();
        std::cout<<stringLiczba(0,0);
        noecho();
        refresh();
        start_color();
        int selektorX = 0, selektorY = 0;
        curs_set(0);
        while (true)
        {
            int x = 0;
            wyswietlArkusz(selektorX, selektorY);
            switch (x = getch())
            {
            case 65:
                if (selektorY > 0)
                    selektorY--;
                break;
            case 66:
                if (selektorY < rozmiarY-1)
                    selektorY++;
                break;
            case 67:
                if (selektorX < rozmiarX-1){
                    selektorX++;
                }
                break;
            case 68:
                if (selektorX > 0){
                    selektorX--;
                }
                break;
                
            case 10:{

                    curs_set(1);
                    int liczba;
                    while(true){
                        clear();
                        addstr("Podaj wartość: ");
                        
                        char wartosc[9]{};
                        getnstr(wartosc,8);
                        std::stringstream nietypowyKonwertor;
                        nietypowyKonwertor << wartosc;
                        nietypowyKonwertor >> liczba;
                        if(!nietypowyKonwertor.fail()){
                            break;
                        }
                        refresh();
                    }
                    
                    modyfikacjaWartosci(tablica, selektorX, selektorY, liczba);
                    curs_set(0);
                }
                break;
            case 81:
                [[fallthrough]]
            case 81+32:
                {
                    clear();
                    refresh();
                    endwin();
                    exit(0);
                }
                break;
            default:
                break;
            }
            refresh();
            clear();
        }
    }

    int WyswietlaczArkusz::wartoscElement(int x, int y){
        return tablica[y][x];
    }

    std::string WyswietlaczArkusz::stringLiczba(int x, int y){
        std::string element = std::to_string(wartoscElement(x,y));
        if(element.length() > szerokoscElementu){
            element = element.substr(0,2) + "...";
            return element;
        }
        else {
            return element;
        }
    }
}
