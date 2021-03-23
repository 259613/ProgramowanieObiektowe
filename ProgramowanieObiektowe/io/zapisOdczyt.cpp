/// @file

#include <fstream>

#include "../tablica/tablica.hpp"

using namespace std;

void zapisPliku(int ** tablica, int rozmiarX, int rozmiarY, string nazwa){
    ofstream plik(nazwa);
    if(plik.good()){
        plik << rozmiarY << endl;
        plik << rozmiarX << endl;

        for(int y = 0; y < rozmiarY; y++){
            for(int x = 0; x < rozmiarX; x++){
                plik << tablica[y][x] << (x<rozmiarX-1 ? ", " : "");
            }
            if(y < rozmiarY - 1){
                plik << endl;
            }
        }
    }
}

int ** wczytajPlik(int * rozmiarX, int * rozmiarY, string nazwa){
    ifstream plik(nazwa);
    int ** tablica = nullptr; 
    if(plik.good()){
        plik >> *rozmiarY;
        plik >> *rozmiarX;
        tablica = tworzTablica(rozmiarX, rozmiarY); 
        for(int y = 0; y < *rozmiarY; y++){
            for(int x = 0; x < (*rozmiarX) - 1; x++){
                string wartosc;
                getline(plik, wartosc, ',');
                tablica[y][x] = stoi(wartosc);
            }
            plik >> tablica[y][(*rozmiarX)-1];
        }
    }
    return tablica;
}
