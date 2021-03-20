#include <iostream>
#include <cstdlib>

#include "menu.h"
#include "tablica.h"

using namespace std;
void generujMenu(){
    string elementy[] = { "Wypisz arkusz", "Modyfikuj element", "Zmień rozmiar", "Utwórz nowy arkusz", "Wyjdź z programu"};
    int i{};
    for(auto x: elementy){
        cout << ++i << ". " << x << endl;
    }
    cout << "Wprowadź wybór: ";
}
void obslugaMenu(){
    int opcja{};
    int rozmiarX, rozmiarY;
    int ** tablica = tworzArkusz(&rozmiarX, &rozmiarY);
    while(true){
        generujMenu();
        cin >> opcja;
        switch(opcja){
            case 1:{
                       wyswietlTablica(tablica, rozmiarX, rozmiarY);
                       break;
                   }
            case 2: {
                        wprowadzWartosc(tablica, rozmiarX, rozmiarY);
                     
                        break;
                    }
            case 3: {
                        rozszerzArkusz(&tablica, &rozmiarX, &rozmiarY);
                        break;
                    }
            case 4: {
                        tablica = tworzArkusz(&rozmiarX, &rozmiarY);
                        break;
                    }
            case 5: {
                        exit(0);
                    }
        }
    }
}

int ** tworzArkusz(int * rozmiarX, int * rozmiarY ){
    cout << "Wprowadź ilość kolumn tablicy: ";
    cin >> *rozmiarY;
    cout << "Wprowadź ilość wierszy tablicy:";
    cin >> *rozmiarX;

    return tworzTablica(rozmiarX, rozmiarY);
}
void rozszerzArkusz(int *** tablica, int * rozmiarX, int * rozmiarY){
    int nowyX, nowyY;
    cout << "Wprowadź ilość wierszy tablicy: ";    
    cin >> nowyX;
    cout << "Wprowadź ilość kolumn tablicy: ";
    cin >> nowyY;

    rozszerzTablice(tablica, rozmiarX, rozmiarY, nowyX, nowyY);
}
