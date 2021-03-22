/// @file

#include "tablica.h"
void rozszerzTablice(int *** tablica, int * rozmiarX, int * rozmiarY, int nowyX, int nowyY){
    if(*rozmiarX > nowyX){
        *rozmiarX = nowyX;
    }
    if(*rozmiarY > nowyY){
        *rozmiarY = nowyY;
    }

    int ** nowaTablica = tworzTablica(&nowyX, &nowyY);

    for(int y = 0; y < *rozmiarY; y++){
        for(int x = 0; x < *rozmiarX; x++){
            nowaTablica[y][x] = (*tablica)[y][x];
        }
        delete [] (*tablica)[y];
    }

    delete [](*tablica);

    *tablica = nowaTablica;
    *rozmiarX = nowyX;
    *rozmiarY = nowyY;

}

int ** tworzTablica(int * rozmiarX, int * rozmiarY){
    int ** tablica = new int*[*rozmiarY];

    int licznik = *rozmiarY;

    while(licznik){
        tablica[--licznik] = new int[*rozmiarX]();
    }

    return tablica;
}

void modyfikacjaWartosci(int ** tablica, int x, int y, int wart){
    tablica[y][x] = wart;
}
