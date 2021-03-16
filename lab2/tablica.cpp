#include "tablica.h"
void rozszerzTablice(int *** tablica, int * rozmiarX, int * rozmiarY, int nowyX, int nowyY){
    if(*rozmiarX > nowyX){
        *rozmiarX = nowyX;
    }	
    if(*rozmiarY > nowyY){
        *rozmiarY = nowyY;
    }

    int ** nowaTablica = tworzTablica(&nowyX, &nowyY);
    
    for(int i = 0; i < *rozmiarY; i++){
        for(int j = 0; j < *rozmiarX; j++){
            nowaTablica[i][j] = (*tablica)[j][i];
        }
    }

    *tablica = nowaTablica;
    *rozmiarX = nowyX;
    *rozmiarY = nowyY;

}

int ** tworzTablica(int * rozmiarX, int * rozmiarY){
    int ** tablica = new int*[*rozmiarY];
    
    int licznik = *rozmiarY;

    while(licznik){
        tablica[--licznik] = new int[*rozmiarX];
    }

    return tablica;
}

void modyfikacjaWartosci(int ** tablica, int x, int y, int wart){
    tablica[x][y] = wart;
}
