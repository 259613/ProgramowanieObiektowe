/// @file

#include <iostream>
#include <cstdlib>
#include <sstream>

#include "menu.hpp"

#include "../io/zapisOdczyt.hpp"
#include "../arkusz/tablica/tablica_wysw.hpp"
#include "../utility/utility.hpp"
#include "../operacje/operacje.hpp"


using namespace std;

void generujMenu(){
	string elementy[] = { "Wypisz arkusz", "Modyfikuj element", "Zmień rozmiar",
						  "Utwórz nowy arkusz", "Zapisz arkusz", "Wczytaj arkusz",
						  "Wyświetl parametry", "Zmień typ kolumny", "Wyjdź z programu"};
    int i{};
    for(auto x: elementy){
        cout << ++i << ". " << x << endl;
    }
    cout << "Wprowadź wybór: ";
}

void obslugaMenu(){
    int opcja{};
	Sheet arkusz= tworzArkusz();
    while(true){
        generujMenu();
		opcja = wprowadzZakres(1, 9);
        system("clear");
        switch(opcja){
            
            case 1:{
					   DisplaySheet(arkusz);
                       break;
                   }
            case 2: {
						wprowadzWartosc(&arkusz);
                        break;
                    }
            case 3: {
						rozszerzArkusz(&arkusz);
                        break;
                    }
            case 4: {
						arkusz = tworzArkusz();
                        break;
                    }
            case 5: {
						zapis(arkusz);
                        break;
                    }
            case 6: {
						wczytanie(&arkusz);
                        break;
                    }
            case 7: {
                        //parametry(arkusz);
                        break;
                    }
			case 8: {
						//zmienTyp(&arkusz);
						break;
					}
			case 9: {
                        exit(0);
                        break;
                    }
        }
    }
}

 void wczytanie(Sheet* arkusz){

	czyscBufor();
	string plik;
	cout << "Podaj nazwę pliku z którego chcesz wczytać arkusz: ";
	getline(cin, plik);

	try{
		loadFile(arkusz, plik);
		cout << "Sukces!\n";
	}
	catch(exception e){
		cout << e.what() << endl;
	}
}


void zapis(Sheet arkusz){

	czyscBufor();
	string plik;
	cout << "Podaj nazwę pliku do którego chcesz zapisać arkusz: ";
	getline(cin, plik);

	try{
		saveFile(arkusz, plik);
		cout << "Sukces!\n";
	}
	catch(exception e){
		cout << e.what() <<endl;
	}
}

Sheet tworzArkusz(){
	while(true){

		try{
			cout << "Wprowadź ilość kolumn tablicy: ";
			size_t rozmiarX = wprowadzZakres();
			cout << "Wprowadź ilość wierszy tablicy: ";
			size_t rozmiarY = wprowadzZakres();

			CellType* typy = new CellType[rozmiarX];
			cout << "Wprowadź typy kolumn \n 0 - String \n 1 - Int\n";
			int typ = 0;
			for(int i = 0; i < rozmiarX; i++){
				cout << "Wprowadź typ " << i << " kolumny: ";
				typ = wprowadzZakres(0,1);
				if(typ == 1){
					typy[i] = CellType::IntCell;
				}
				else{
					typy[i] = CellType::StringCell;
				}
			}

			return Sheet(rozmiarX, rozmiarY, typy);

		}
		catch(...){}
	}
}

void rozszerzArkusz(Sheet * arkusz){
	size_t nowyX, nowyY;
	cout << "Wprowadź ilość kolumn tablicy: ";
	nowyX = wprowadzZakres();
	cout << "Wprowadź ilość wierszy tablicy: ";
	nowyY = wprowadzZakres();

	arkusz->resize(nowyX, nowyY);
}

void wprowadzWartosc(Sheet * arkusz){
	size_t wspX, wspY;
	cout << "Wprowadź kolumnę: ";
	wspX = wprowadzZakres(0, arkusz->getWidth()-1);
	cout << "Wprowadź wiersz: ";
	wspY = wprowadzZakres(0, arkusz->getHeight()-1);

	switch(arkusz->getColumn(wspX).getType()){
		case CellType::IntCell:{
			cout << "Wprowadź wartość liczbową: ";
			int x = wprowadzInt();
			(*arkusz)[wspX][wspY].setValue(&x);
			break;
		}
		case CellType::StringCell:{
			cout << "Wprowadź wartość tekstową: ";

			string txt{};
			czyscBufor();
			getline(cin,txt);

			(*arkusz)[wspX][wspY].setValue(&txt);
			break;
		}
		default:{
			break;
		}
	}

}


// void parametry(Arkusz arkusz){
//     cout << "Podaj względem czego chcesz obliczać parametry: " << endl
//     << "0. Kolumny" << endl << "1. Wiersze" << endl;
//     int opcja = wprowadzZakres(0,1);

//     string wynik{};
    
//     if(opcja){
//         cout << "Podaj wiersz względem którego mają zostać podane parametry: ";
//         wynik = parametryWiersza(arkusz, wprowadzZakres(0,arkusz.rozmiarY()-1));
//     }
//     else{
//         cout << "Podaj kolumnę względem którego mają zostać podane parametry: ";
//         wynik = parametryKolumny(arkusz, wprowadzZakres(0,arkusz.rozmiarX()-1));
//     }
//     cout << wynik;
//}

// string parametryWiersza(Arkusz arkusz, int wiersz){
//     stringstream ss;

//     ss << "Wartość maksymalna wiersza: " << maxWiersz(arkusz, wiersz) << endl;
//     ss << "Wartość minimalna wiersza: " << minWiersz(arkusz, wiersz) << endl;
//     int suma = sumaWiersz(arkusz, wiersz);
//     ss << "Suma elementów wiersza: " << suma << endl;
//     ss << "Średnia elementów wiersza: " << (static_cast<double>(suma)/arkusz.rozmiarX()) << endl;

//     return ss.str();
// }

// string parametryKolumny(Arkusz arkusz, int kolumna){
//     stringstream ss;

//     ss << "Wartość maksymalna kolumny: " << maxKolumna(arkusz, kolumna) << endl;
//     ss << "Wartość minimalna kolumny: " << minKolumna(arkusz, kolumna) << endl;
//     int suma = sumaKolumna(arkusz, kolumna);
//     ss << "Suma elementów kolumny: " << suma << endl;
//     ss << "Średnia elementów kolumny: " << (static_cast<double>(suma)/arkusz.rozmiarY()) << endl;

//     return ss.str();
// }

// void obslugaBledow(Wyjatki wyjatek){
//     switch(wyjatek){
//         case Wyjatki::BRAK:{
//             break;
//         }
//         case Wyjatki::PLIK_ACCESS:{
//             cout << "Brak dostępu do pliku bądź niepoprawna nazwa!\n";
//             break;
//         }
//         case Wyjatki::PLIK_FORMAT:{
//             cout << "Niepoprawny format wczytywanego pliku!\n";
//             break;
//         }
//         case Wyjatki::PLIK_ROZMIAR:{
//             cout << "Niepoprawny rozmiar wczytywanego arkusza!\n";
//             break;
//         }
//         case Wyjatki::TABLICA_SIZE:{
//             cout << "Niepoprawny rozmiar tworzonego arkusza!\n";
//             break;
//         }
//         case Wyjatki::TABLICA_ZAKR:{
//             cout << "Niepoprawny dostęp do tablicy arkusza!\nIndeks spoza zakresu!\n";
//             break;
//         }
//     }
// }
