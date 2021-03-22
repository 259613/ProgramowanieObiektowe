/// @file

#include <iostream>
#include "tablica.hpp"

using namespace std;

void wyswietlTablica(int ** tablica, int rozX, int rozY){
	for(int y = 0; y < rozY; y++){
		for(int x = 0; x < rozX; x++){
			cout << tablica[y][x] << '\t';
		}
		cout << endl;
	}
}

void wprowadzWartosc(int ** tablica, int rozX, int rozY){
    int wspX, wspY, wart;
    cout << "Wprowadź której kolumny: ";
    cin >> wspX;
    cout << "Wprowadź który wiersz: ";
    cin >> wspY;
    cout << "Podaj wartość: ";
    cin >> wart; 
    modyfikacjaWartosci(tablica, wspX, wspY, wart);
    cout << "ZMODYFIKOWANO!\n";
}
