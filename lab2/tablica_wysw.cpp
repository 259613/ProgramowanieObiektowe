#include <iostream>
#include "tablica.h"
using namespace std;

void wyswietlTablica(int ** tablica, int rozX, int rozY){
	for(int i = 0; i < rozX; i++){
		for(int j = 0; j < rozY; j++){
			cout << tablica[j][i] << '\t';
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
