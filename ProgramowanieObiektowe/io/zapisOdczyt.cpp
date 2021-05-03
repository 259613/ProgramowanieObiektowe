/// @file

#include <fstream>

#include "../io/zapisOdczyt.hpp"

using namespace std;

int zapisPliku(Arkusz arkusz, string nazwa){
    ofstream plik(nazwa);
    size_t iloscKolumn = arkusz.rozmiarX();
    size_t iloscWierszy= arkusz.rozmiarY();
    if(plik.good()){
        plik << iloscWierszy << endl;
        plik << iloscKolumn << endl;
        for(size_t y = 0; y < iloscWierszy; y++){
            for(size_t x = 0; x < iloscKolumn; x++){
                plik << arkusz.zwrocWartosc(x,y) << (x<iloscKolumn-1 ? ", " : "");
            }
            if(y < iloscWierszy - 1){
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

        *arkusz = Arkusz(rozmiarWczytX, rozmiarWczytY); 
        for(size_t y = 0; y < rozmiarWczytY; y++){
            for(size_t x = 0; x < (rozmiarWczytX) - 1; x++){
                string wartosc;
                getline(plik, wartosc, ',');
                (*arkusz).modyfikacjaWartosci(x,y, stoi(wartosc));
            }
            Komorka wart;
            plik >> wart;
            (*arkusz).modyfikacjaWartosci((rozmiarWczytX)-1,y,wart);
        }
    }
    
    else{
        return 1;
    }
    
    plik.close();
    return 0;
}
