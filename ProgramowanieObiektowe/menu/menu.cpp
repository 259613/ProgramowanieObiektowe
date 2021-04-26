/// @file

#include <iostream>
#include <cstdlib>

#include "menu.hpp"

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
    int opcja{};
    Arkusz arkusz = tworzArkusz();
    while(true){
        generujMenu();
        opcja = wprowadzZakres(1, 7);
        system("clear");
        switch(opcja){
            
            case 1:{
                       wyswietlTablica(arkusz);
                       break;
                   }
            case 2: {
                        wprowadzWartosc(&arkusz);
                        break;
                    }
            case 3: {
                        rozszerzArkusz(&arkusz);
                        break;
                    }
            case 4: {
                        arkusz = tworzArkusz();
                        break;
                    }
            case 5: {
                        zapis(arkusz);
                        break;
                    }
            case 6: {
                        wczytanie(&arkusz);
                        break;
                    }
            case 7: {
                        exit(0);
                    }
        }
    }
}

void wczytanie(Arkusz* arkusz){
    czyscBufor();
    string plik;
    cout << "Podaj nazwę pliku z którego chcesz wczytać arkusz: ";
    getline(cin, plik);
    switch(wczytajPlik(arkusz, plik)){
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


void zapis(Arkusz arkusz){
    czyscBufor(); 
    string plik;
    cout << "Podaj nazwę pliku do którego chcesz zapisać arkusz: ";
    getline(cin, plik);
    switch(zapisPliku(arkusz, plik)){
        case 1:{
                   cout << "Wystąpił błąd zapisu!\n Brak dostępu do pliku bądź niepoprawna nazwa\n";
                   break;
               }
    }
}

Arkusz tworzArkusz(){
    cout << "Wprowadź ilość kolumn tablicy: ";
    size_t rozmiarX = wprowadzZakres();
    cout << "Wprowadź ilość wierszy tablicy: ";
    size_t rozmiarY = wprowadzZakres();

    return tworzArkusz(rozmiarX, rozmiarY);
}

void rozszerzArkusz(Arkusz * arkusz){
    size_t nowyX, nowyY;
    cout << "Wprowadź ilość kolumn tablicy: ";
    nowyX = wprowadzZakres();
    cout << "Wprowadź ilość wierszy tablicy: ";
    nowyY = wprowadzZakres();

    rozszerzArkusz(arkusz, nowyX, nowyY);
}

