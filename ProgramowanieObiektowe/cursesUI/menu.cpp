#include <iostream>
#include <cstdlib>

#include "menu.hpp"
#include "WyswietlaczArkusz.hpp"
#include "../menu/menu.hpp"
#include "../tablica/tablica.hpp"

using namespace std;

namespace CursesMenu
{
    void obslugaMenu(){
        int opcja{};
        int rozmiarX, rozmiarY;
        int **tablica = tworzArkusz(&rozmiarX, &rozmiarY);

        WyswietlaczArkusz arkusz(tablica, rozmiarX, rozmiarY);
        while(true){
            
            arkusz.obslugaArkusz();
        }
    }

    void obslugaArkusza(){

    }
}
