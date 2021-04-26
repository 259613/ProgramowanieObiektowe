#include "operacje.hpp"

int maxWiersz(Arkusz arkusz, size_t wiersz){
    int max = arkusz.tablica[wiersz][0];
    for(int i = 1; i < arkusz.iloscKolumn; i++){
        if(max < arkusz.tablica[wiersz][i]){
            max = arkusz.tablica[wiersz][i];
        }
    }
    return max;
}

int minWiersz(Arkusz arkusz, size_t wiersz){
    int min = arkusz.tablica[wiersz][0];
    for(int i = 1; i < arkusz.iloscKolumn; i++){
        if(min > arkusz.tablica[wiersz][i]){
            min = arkusz.tablica[wiersz][i];
        }
    }
    return min;
}

int sumaWiersz(Arkusz arkusz, size_t wiersz){
    int sum = arkusz.tablica[wiersz][0];
    for(int i = 1; i < arkusz.iloscKolumn; i++){
            sum += arkusz.tablica[wiersz][i];
    }
    return sum;
}


int maxKolumna(Arkusz arkusz, size_t kolumna){
    int max = arkusz.tablica[0][kolumna];
    for(int i = 1; i < arkusz.iloscWierszy; i++){
        if(max < arkusz.tablica[i][kolumna]){
            max = arkusz.tablica[i][kolumna];
        }
    }
    return max;
}

int minKolumna(Arkusz arkusz, size_t kolumna){
    int min = arkusz.tablica[0][kolumna];
    for(int i = 1; i < arkusz.iloscWierszy; i++){
        if(min > arkusz.tablica[i][kolumna]){
            min = arkusz.tablica[i][kolumna];
        }
    }
    return min;
}

int sumaKolumna(Arkusz arkusz, size_t kolumna){
    int sum = arkusz.tablica[0][kolumna];
    for(int i = 1; i < arkusz.iloscWierszy; i++){
            sum += arkusz.tablica[i][kolumna];
    }
    return sum;
}