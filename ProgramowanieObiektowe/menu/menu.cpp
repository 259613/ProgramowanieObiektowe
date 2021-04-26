/// @file

#include <iostream>
#include <cstdlib>
#include <sstream>

#include "menu.hpp"

#include "../io/zapisOdczyt.hpp"
#include "../utility/utility.hpp"
#include "../operacje/operacje.hpp"

using namespace std;

void generujMenu(){
    string elementy[] = { "Wypisz arkusz", "Modyfikuj element", "Zmień rozmiar", "Utwórz nowy arkusz", "Zapisz arkusz", "Wczytaj arkusz", "Wyświetl parametry","Wyjdź z programu"};
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
        opcja = wprowadzZakres(1, 8);
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
                        parametry(arkusz);
                        break;
                    }
            case 8: {
                        exit(0);
                        break;
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

void parametry(Arkusz arkusz){
    cout << "Podaj względem czego chcesz obliczać parametry: " << endl
    << "0. Kolumny" << endl << "1. Wiersze" << endl;
    int opcja = wprowadzZakres(0,1);

    string wynik{};
    
    if(opcja){
        cout << "Podaj wiersz względem którego mają zostać podane parametry: ";
        wynik = parametryWiersza(arkusz, wprowadzZakres(0,arkusz.iloscWierszy-1));
    }
    else{
        cout << "Podaj kolumnę względem którego mają zostać podane parametry: ";
        wynik = parametryKolumny(arkusz, wprowadzZakres(0,arkusz.iloscKolumn-1));
    }
    cout << wynik;
}

string parametryWiersza(Arkusz arkusz, int wiersz){
    stringstream ss;

    ss << "Wartość maksymalna wiersza: " << maxWiersz(arkusz, wiersz) << endl;
    ss << "Wartość minimalna wiersza: " << minWiersz(arkusz, wiersz) << endl;
    int suma = sumaWiersz(arkusz, wiersz);
    ss << "Suma elementów wiersza: " << suma << endl;
    ss << "Średnia elementów wiersza: " << (static_cast<double>(suma)/arkusz.iloscKolumn) << endl;

    return ss.str();
}

string parametryKolumny(Arkusz arkusz, int kolumna){
    stringstream ss;

    ss << "Wartość maksymalna kolumny: " << maxKolumna(arkusz, kolumna) << endl;
    ss << "Wartość minimalna kolumny: " << minKolumna(arkusz, kolumna) << endl;
    int suma = sumaKolumna(arkusz, kolumna);
    ss << "Suma elementów kolumny: " << suma << endl;
    ss << "Średnia elementów kolumny: " << (static_cast<double>(suma)/arkusz.iloscWierszy) << endl;

    return ss.str();
}