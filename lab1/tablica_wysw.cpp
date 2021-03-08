#include <iostream>
#include "tablica.h"
using namespace std;

void wyswietlTablica(int ** tablica, int rozX, int rozY){
	for(int i = 0; i < rozY; i++){
		for(int j = 0; j < rozX; j++){
			cout << tablica[i][j] << '\t';
		}
		cout << endl;
	}
}
