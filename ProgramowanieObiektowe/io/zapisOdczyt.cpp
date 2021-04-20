/// @file

#include <fstream>

#include "../tablica/tablica.hpp"

using namespace std;

int zapisPliku(int ** tablica, int rozmiarX, int rozmiarY, string nazwa){
    ofstream plik(nazwa);
    
    if(plik.good()){
        plik << rozmiarY << endl;
        plik << rozmiarX << endl;
        for(int y = 0; y < rozmiarY; y++){
            for(int x = 0; x < rozmiarX; x++){
                plik << (tablica)[y][x] << (x<rozmiarX-1 ? ", " : "");
            }
            if(y < rozmiarY - 1){
                plik << endl;
            }
        }
    }

    else{
        return 1;
    }
    
    plik.close();
    return 0;
}

int wczytajPlik(int*** tablica, int * rozmiarX, int * rozmiarY, string nazwa){
    ifstream plik(nazwa);
    if(plik.good()){
        plik >> *rozmiarY;
        plik >> *rozmiarX;
        *tablica = tworzTablica(rozmiarX, rozmiarY); 
        for(int y = 0; y < *rozmiarY; y++){
            for(int x = 0; x < (*rozmiarX) - 1; x++){
                string wartosc;
                getline(plik, wartosc, ',');
                (*tablica)[y][x] = stoi(wartosc);
            }
            plik >> (*tablica)[y][(*rozmiarX)-1];
        }
    }
    
    else{
        return 1;
    }
    
    plik.close();
    return 0;
}
