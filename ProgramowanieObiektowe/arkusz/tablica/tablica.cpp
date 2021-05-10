/// @file

#include "tablica.hpp"

#include <limits>

Arkusz::Arkusz(size_t kolumny, size_t wiersze){
    iloscWierszy = wiersze;
    iloscKolumn = kolumny;
    tablica = tworzTablica(kolumny, wiersze);
}

Wyjatki Arkusz::rozszerzArkusz(size_t nowyX, size_t nowyY){
    if(nowyX < 1 || nowyY < 1){
        return Wyjatki::TABLICA_SIZE;
    }

    if(iloscKolumn > nowyX){
        iloscKolumn = nowyX;
    }
    if(iloscWierszy > nowyY){
        iloscWierszy = nowyY;
    }

    Tablica nowaTablica = tworzTablica(nowyX, nowyY);

    for(size_t y = 0; y < iloscWierszy; y++){
        for(size_t x = 0; x < iloscKolumn; x++){
            nowaTablica[y][x] = tablica[y][x];
        }
        delete [] (tablica)[y];
    }

    delete [](tablica);
    iloscWierszy = nowyY;
    iloscKolumn = nowyX;
    tablica = nowaTablica;
    return Wyjatki::BRAK;
}

Tablica Arkusz::tworzTablica(size_t rozmiarX, size_t rozmiarY){
    Tablica tablica = new Komorka*[rozmiarY];

    int licznik = rozmiarY;

    while(licznik){
        tablica[--licznik] = new Komorka[rozmiarX]();
    }

    return tablica;
}

Wyjatki Arkusz::modyfikacjaWartosci(size_t x, size_t y, int wartosc){
    if(x > iloscKolumn || y > iloscWierszy){
        return Wyjatki::TABLICA_ZAKR;
    }

    tablica[y][x].setValue(wartosc);
    return Wyjatki::BRAK;
}

int Arkusz::zwrocWartosc(size_t x, size_t y){
    if(x > iloscKolumn || y > iloscWierszy){
        return std::numeric_limits<int>::min();
    }
    return tablica[y][x].getValue();
}

size_t Arkusz::rozmiarX(){
    return iloscKolumn;
}

size_t Arkusz::rozmiarY(){
    return iloscWierszy;
}