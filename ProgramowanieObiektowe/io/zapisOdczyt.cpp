/// @file

#include <fstream>

#include "../io/zapisOdczyt.hpp"

using namespace std;

int zapisPliku(Arkusz arkusz, string nazwa){
    ofstream plik(nazwa);
    
    if(plik.good()){
        plik << arkusz.iloscWierszy << endl;
        plik << arkusz.iloscKolumn << endl;
        for(int y = 0; y < arkusz.iloscWierszy; y++){
            for(int x = 0; x < arkusz.iloscKolumn; x++){
                plik << (arkusz).tablica[y][x] << (x<arkusz.iloscKolumn-1 ? ", " : "");
            }
            if(y < arkusz.iloscWierszy - 1){
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

int wczytajPlik(Arkusz * arkusz, string nazwa){
    ifstream plik(nazwa);
    if(plik.good()){
        size_t rozmiarWczytY{}, rozmiarWczytX{};
        plik >> rozmiarWczytY;
        plik >> rozmiarWczytX;
        
        if(rozmiarWczytX < 1 || rozmiarWczytY < 1){
            return 3;
        }

        *arkusz = tworzArkusz(rozmiarWczytX, rozmiarWczytY); 
        for(int y = 0; y < rozmiarWczytY; y++){
            for(int x = 0; x < (rozmiarWczytX) - 1; x++){
                string wartosc;
                getline(plik, wartosc, ',');
                (*arkusz).tablica[y][x] = stoi(wartosc);
            }
            plik >> (*arkusz).tablica[y][(rozmiarWczytX)-1];
        }
    }
    
    else{
        return 1;
    }
    
    plik.close();
    return 0;
}
