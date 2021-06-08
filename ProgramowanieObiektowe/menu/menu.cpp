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
						  "Wyświetl parametry", "Zmień typ kolumny", "Sortuj", "Wyjdź z programu"};
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
		opcja = wprowadzZakres(1, 10);
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
				parametry(arkusz);
				break;
			}
			case 8: {
				zmienTyp(&arkusz);

				break;
			}
			case 9: {
				sortowanie(&arkusz);
				break;
			}
			case 10: {
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

	string txt{};
	czyscBufor();
	while(true){
		try{
			cout << "Wprowadź wartość: ";
			getline(cin,txt);

			(*arkusz)[wspX][wspY].setValue(txt);
			break;
		}
		catch(...){
			cout << "Wymagana jest wartość liczbowa." << endl;
		}
	}
}


void parametry(Sheet arkusz){
	cout << "Podaj względem czego chcesz obliczać parametry: " << endl
		 << "0. Kolumny" << endl << "1. Wiersze" << endl;
	int opcja = wprowadzZakres(0,1);

	string wynik{};

	if(opcja){
		cout << "Podaj wiersz względem którego mają zostać podane parametry: ";
		wynik = parametryWiersza(arkusz, wprowadzZakres(0,arkusz.getHeight()-1));
	}
	else{
		cout << "Podaj kolumnę względem którego mają zostać podane parametry: ";
		wynik = parametryKolumny(arkusz, wprowadzZakres(0,arkusz.getWidth()-1));
	}
	cout << wynik;
}

string parametryWiersza(Sheet arkusz, int wiersz){
	stringstream ss;
	int liczbaKolumnObliczalnych = countCalculateableColumns(arkusz);
	if(liczbaKolumnObliczalnych > 0){
		ss << "Wartość maksymalna wiersza: " << maxWiersz(arkusz, wiersz) << endl;
		ss << "Wartość minimalna wiersza: " << minWiersz(arkusz, wiersz) << endl;
		int suma = sumaWiersz(arkusz, wiersz);
		ss << "Suma elementów wiersza: " << suma << endl;
		ss << "Średnia elementów wiersza: " << (static_cast<double>(suma)/liczbaKolumnObliczalnych) << endl;
	}
	else{
		ss << "Brak kolumn obliczalnych do liczenia parametrów!";
	}
	return ss.str();
}

string parametryKolumny(Sheet arkusz, int kolumna){
	stringstream ss;

	if(arkusz[kolumna].getType()!=CellType::StringCell){

		ss << "Wartość maksymalna kolumny: " << maxKolumna(arkusz[kolumna]) << endl;
		ss << "Wartość minimalna kolumny: " << minKolumna(arkusz[kolumna]) << endl;
		int suma = sumaKolumna(arkusz[kolumna]);
		ss << "Suma elementów kolumny: " << suma << endl;
		ss << "Średnia elementów kolumny: " << (static_cast<double>(suma)/arkusz.getHeight()) << endl;
	}

	else{
		ss << "Kolumna jest tekstowa!" << endl
		   << "Nie można obliczać parametrów kolumn tekstowych" << endl;
	}

	return ss.str();
}

void zmienTyp(Sheet* arkusz){
	cout << "Wprowadź kolumne którą chcesz zmienić: " << endl;
	size_t kol = wprowadzZakres(0, arkusz->getWidth()-1);

	cout << "Wprowadź typ na który chcesz zmienić: \n 0 - String\n 1 - Int" << endl;
	int wart = wprowadzZakres(0,1);

	(*arkusz)[kol].changeType(static_cast<CellType>(wart));
}

void sortowanie(Sheet* arkusz){
	cout << "Wprowadź kolumnę do posortowania" << endl;
	int x = wprowadzZakres(0, arkusz->getWidth()-1);
	cout << "Jak ma kolumna być posortowana \n 0. rosnąco \n 1. Malejąco " << endl;
	bool desc = (wprowadzZakres(0,1)?true:false);
	sortKolumna(&(*arkusz)[x],desc);
}
