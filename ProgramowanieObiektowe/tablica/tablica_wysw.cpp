/// @file

#include <iostream>
#include "tablica.hpp"
#include "../utility/utility.hpp"

using namespace std;

void wyswietlTablica(Arkusz arkusz){
    cout << "Tablica o rozmiarze " << arkusz.iloscKolumn << " : " << arkusz.iloscWierszy << endl;
    for(int y = 0; y < arkusz.iloscWierszy; y++){
		    for(int x = 0; x < arkusz.iloscKolumn; x++){
			      cout << arkusz.tablica[y][x] << '\t';
		    }
		    cout << endl;
	  }
}

void wprowadzWartosc(Arkusz * arkusz){
    int wspX, wspY, wart;
    cout << "Wprowadź której kolumny: ";
    wspX = wprowadzZakres(0, arkusz->iloscKolumn-1);
    cout << "Wprowadź który wiersz: ";
    wspY = wprowadzZakres(0, arkusz->iloscWierszy-1);
    cout << "Podaj wartość: ";
    wart = wprowadzInt(); 
    modyfikacjaWartosci(arkusz, wspX, wspY, wart);
}
