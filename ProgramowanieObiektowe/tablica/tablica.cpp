/// @file

#include "tablica.hpp"

void rozszerzArkusz(Arkusz * arkusz, size_t nowyX, size_t nowyY){
    if(arkusz->iloscKolumn > nowyX){
        arkusz->iloscKolumn = nowyX;
    }
    if(arkusz->iloscWierszy > nowyY){
        arkusz->iloscWierszy = nowyY;
    }

    Arkusz nowyArkusz = tworzArkusz(nowyX, nowyY);

    for(int y = 0; y < arkusz->iloscWierszy; y++){
        for(int x = 0; x < arkusz->iloscKolumn; x++){
            nowyArkusz.tablica[y][x] = (*arkusz).tablica[y][x];
        }
        delete [] (arkusz->tablica)[y];
    }

    delete [](arkusz->tablica);

    *arkusz = nowyArkusz;
}

Arkusz tworzArkusz(size_t rozmiarX, size_t rozmiarY){
    Tablica tablica = new int*[rozmiarY];

    int licznik = rozmiarY;

    while(licznik){
        tablica[--licznik] = new int[rozmiarX]();
    }

    return Arkusz{tablica, rozmiarX, rozmiarY};
}

int modyfikacjaWartosci(Arkusz * arkusz, int x, int y, int wart){
    if(x > arkusz->iloscKolumn || y > arkusz->iloscWierszy){
        return 5;
    }

    arkusz->tablica[y][x] = wart;
    return 0;
}
