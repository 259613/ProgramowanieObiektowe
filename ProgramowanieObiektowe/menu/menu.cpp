/// @file

#include <iostream>
#include <cstdlib>

#include "menu.hpp"
#include "../tablica/tablica.hpp"
#include "../io/zapisOdczyt.hpp"
#include "../utility/utility.hpp"

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
    int rozmiarX, rozmiarY;
    int opcja{};
    int ** tablica = tworzArkusz(&rozmiarX, &rozmiarY);
    while(true){
        generujMenu();
        opcja = wprowadzZakres(1, 7);
        system("clear");
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
                        zapis(tablica, rozmiarX, rozmiarY);
                        break;
                    }
            case 6: {
                        wczytanie(&tablica, &rozmiarX, &rozmiarY);
                        break;
                    }
            case 7: {
                        exit(0);
                    }
        }
    }
}

void wczytanie(int*** tablica, int *rozmiarX, int *rozmiarY){
    czyscBufor();
    string plik;
    cout << "Podaj nazwę pliku z którego chcesz wczytać arkusz: ";
    getline(cin, plik);
    switch(wczytajPlik(tablica, rozmiarX, rozmiarY, plik)){
        case 1:{
                   cout << "Brak dostępu do pliku bądź niepoprawna nazwa!\n";
                   break;
               }
        case 2:{
                   cout << "Niepoprawny format wczytywanego pliku!\n";
                   break;
               }
        case 3:{
                   cout << "Niepoprawny rozmiar wczytywanego arkusza!\n";
                   break;
               }
    }
}


void zapis(int **tablica, int rozmiarX, int rozmiarY){
    czyscBufor(); 
    string plik;
    cout << "Podaj nazwę pliku do którego chcesz zapisać arkusz: ";
    getline(cin, plik);
    switch(zapisPliku(tablica, rozmiarX, rozmiarY, plik)){
        case 1:{
                   cout << "Wystąpił błąd zapisu!\n Brak dostępu do pliku bądź niepoprawna nazwa\n";
                   break;
               }
    }
}

int ** tworzArkusz(int * rozmiarX, int * rozmiarY ){
    cout << "Wprowadź ilość kolumn tablicy: ";
    *rozmiarX = wprowadzZakres();
    cout << "Wprowadź ilość wierszy tablicy: ";
    *rozmiarY = wprowadzZakres();

    return tworzTablica(rozmiarX, rozmiarY);
}

void rozszerzArkusz(int *** tablica, int * rozmiarX, int * rozmiarY){
    int nowyX, nowyY;
    cout << "Wprowadź ilość kolumn tablicy: ";
    nowyX = wprowadzZakres();
    cout << "Wprowadź ilość wierszy tablicy: ";
    nowyY = wprowadzZakres();

    rozszerzTablice(tablica, rozmiarX, rozmiarY, nowyX, nowyY);
}

