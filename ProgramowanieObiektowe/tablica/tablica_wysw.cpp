/// @file

#include <iostream>
#include "tablica.hpp"
#include "../utility/utility.hpp"

using namespace std;

void wyswietlTablica(int ** tablica, int rozX, int rozY){
    cout << "Tablica o rozmiarze " << rozX << " : " << rozY << endl;
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
    wspX = wprowadzZakres(0, rozX-1);
    cout << "Wprowadź który wiersz: ";
    wspY = wprowadzZakres(0, rozY-1);
    cout << "Podaj wartość: ";
    wart = wprowadzInt(); 
    modyfikacjaWartosci(tablica, wspX, wspY, wart);
}
