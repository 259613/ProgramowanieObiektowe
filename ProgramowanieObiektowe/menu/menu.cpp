/// @file

#include <iostream>
#include <cstdlib>

#include "menu.hpp"
#include "../tablica/tablica.hpp"
#include "../io/zapisOdczyt.hpp"

using namespace std;
void generujMenu(){
    string elementy[] = { "Wypisz arkusz", "Modyfikuj element", "Zmień rozmiar", "Utwórz nowy arkusz", "Zapisz arkusz", "Wczytaj arkusz", "Wyjdź z programu"};
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
                        string plik;
                        getline(cin, plik);
                        zapisPliku(tablica, rozmiarX, rozmiarY, plik);
                        break;
                    }
            case 6: {
                        string plik;
                        getline(cin, plik);
                        tablica = wczytajPlik(&rozmiarX, &rozmiarY, plik);
                        break;
                    }
            case 7: {
                        exit(0);
                    }
        }
    }
}

int ** tworzArkusz(int * rozmiarX, int * rozmiarY ){
    cout << "Wprowadź ilość kolumn tablicy: ";
    cin >> *rozmiarX;
    cout << "Wprowadź ilość wierszy tablicy: ";
    cin >> *rozmiarY;

    return tworzTablica(rozmiarX, rozmiarY);
}
void rozszerzArkusz(int *** tablica, int * rozmiarX, int * rozmiarY){
    int nowyX, nowyY;
    cout << "Wprowadź ilość kolumn tablicy: ";
    cin >> nowyX;
    cout << "Wprowadź ilość wierszy tablicy: ";
    cin >> nowyY;

    rozszerzTablice(tablica, rozmiarX, rozmiarY, nowyX, nowyY);
}
