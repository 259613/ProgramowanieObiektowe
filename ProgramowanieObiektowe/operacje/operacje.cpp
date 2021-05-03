#include "operacje.hpp"

// regex zmiany tablica\[(\w*\d*)\]\[(\w*\d*)\] ->  zwrocWartosc($2, $1)

int maxWiersz(Arkusz arkusz, size_t wiersz){
    int max = arkusz.zwrocWartosc(0, wiersz);
    for(size_t i = 1; i < arkusz.rozmiarX(); i++){
        if(max < arkusz.zwrocWartosc(i, wiersz)){
            max = arkusz.zwrocWartosc(i, wiersz);
        }
        
    }
    return max;
}

int minWiersz(Arkusz arkusz, size_t wiersz){
    int min = arkusz.zwrocWartosc(0, wiersz);
    for(size_t i = 1; i < arkusz.rozmiarX(); i++){
        if(min > arkusz.zwrocWartosc(i, wiersz)){
            min = arkusz.zwrocWartosc(i, wiersz);
        }
    }
    return min;
}

int sumaWiersz(Arkusz arkusz, size_t wiersz){
    int sum = arkusz.zwrocWartosc(0, wiersz);
    for(size_t i = 1; i < arkusz.rozmiarX(); i++){
            sum += arkusz.zwrocWartosc(i, wiersz);
    }
    return sum;
}


int maxKolumna(Arkusz arkusz, size_t kolumna){
    int max = arkusz.zwrocWartosc(kolumna, 0);
    for(size_t i = 1; i < arkusz.rozmiarY(); i++){
        if(max < arkusz.zwrocWartosc(kolumna, i)){
            max = arkusz.zwrocWartosc(kolumna, i);
        }
    }
    return max;
}

int minKolumna(Arkusz arkusz, size_t kolumna){
    int min = arkusz.zwrocWartosc(kolumna, 0);
    for(size_t i = 1; i < arkusz.rozmiarY(); i++){
        if(min > arkusz.zwrocWartosc(kolumna, i)){
            min = arkusz.zwrocWartosc(kolumna, i);
        }
    }
    return min;
}

int sumaKolumna(Arkusz arkusz, size_t kolumna){
    int sum = arkusz.zwrocWartosc(kolumna, 0);
    for(size_t i = 1; i < arkusz.rozmiarY(); i++){
            sum += arkusz.zwrocWartosc(kolumna, i);
    }
    return sum;
}