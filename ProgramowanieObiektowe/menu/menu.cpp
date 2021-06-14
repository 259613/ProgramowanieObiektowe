/// @file

#include <iostream>
#include <cstdlib>
#include <sstream>

#include "menu.hpp"

#include "../io/fileOperations.hpp"
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
	Sheet arkusz= sheetCreator();
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
				inputValue(&arkusz);
				break;
			}
			case 3: {
				expandSheet(&arkusz);
				break;
			}
			case 4: {
				arkusz = sheetCreator();
				break;
			}
			case 5: {
				saveSheet(arkusz);
				break;
			}
			case 6: {
				loadSheet(&arkusz);
				break;
			}
			case 7: {
				sheetParameters(arkusz);
				break;
			}
			case 8: {
				changeType(&arkusz);

				break;
			}
			case 9: {
				sort(&arkusz);
				break;
			}
			case 10: {
				exit(0);
				break;
			}
		}
	}
}

void loadSheet(Sheet* arkusz){

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


void saveSheet(Sheet arkusz){

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

Sheet sheetCreator(){
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

void expandSheet(Sheet * arkusz){
	size_t nowyX, nowyY;
	cout << "Wprowadź ilość kolumn tablicy: ";
	nowyX = wprowadzZakres();
	cout << "Wprowadź ilość wierszy tablicy: ";
	nowyY = wprowadzZakres();

	arkusz->resize(nowyX, nowyY);
}

void inputValue(Sheet * arkusz){
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


void sheetParameters(Sheet arkusz){
	cout << "Podaj względem czego chcesz obliczać parametry: " << endl
		 << "0. Kolumny" << endl << "1. Wiersze" << endl;
	int opcja = wprowadzZakres(0,1);

	string wynik{};

	if(opcja){
		cout << "Podaj wiersz względem którego mają zostać podane parametry: ";
		wynik = rowParameters(arkusz, wprowadzZakres(0,arkusz.getHeight()-1));
	}
	else{
		cout << "Podaj kolumnę względem którego mają zostać podane parametry: ";
		wynik = columnParameters(arkusz, wprowadzZakres(0,arkusz.getWidth()-1));
	}
	cout << wynik;
}

string rowParameters(Sheet arkusz, int wiersz){
	stringstream ss;
	int liczbaKolumnObliczalnych = countCalculateableColumns(arkusz);
	if(liczbaKolumnObliczalnych > 0){
		ss << "Wartość maksymalna wiersza: " << maxRow(arkusz, wiersz) << endl;
		ss << "Wartość minimalna wiersza: " << minRow(arkusz, wiersz) << endl;
		int suma = sumRow(arkusz, wiersz);
		ss << "Suma elementów wiersza: " << suma << endl;
		ss << "Średnia elementów wiersza: " << (static_cast<double>(suma)/liczbaKolumnObliczalnych) << endl;
	}
	else{
		ss << "Brak kolumn obliczalnych do liczenia parametrów!";
	}
	return ss.str();
}

string columnParameters(Sheet arkusz, int kolumna){
	stringstream ss;

	if(arkusz[kolumna].getType()!=CellType::StringCell){

		ss << "Wartość maksymalna kolumny: " << maxColumn(arkusz[kolumna]) << endl;
		ss << "Wartość minimalna kolumny: " << minColumn(arkusz[kolumna]) << endl;
		int suma = sumColumn(arkusz[kolumna]);
		ss << "Suma elementów kolumny: " << suma << endl;
		ss << "Średnia elementów kolumny: " << (static_cast<double>(suma)/arkusz.getHeight()) << endl;
	}

	else{
		ss << "Kolumna jest tekstowa!" << endl
		   << "Nie można obliczać parametrów kolumn tekstowych" << endl;
	}

	return ss.str();
}

void changeType(Sheet* arkusz){
	cout << "Wprowadź kolumne którą chcesz zmienić: " << endl;
	size_t kol = wprowadzZakres(0, arkusz->getWidth()-1);

	cout << "Wprowadź typ na który chcesz zmienić: \n 0 - String\n 1 - Int" << endl;
	int wart = wprowadzZakres(0,1);

	(*arkusz)[kol].changeType(static_cast<CellType>(wart));
}

void sort(Sheet* arkusz){
	cout << "Wprowadź kolumnę do posortowania" << endl;
	int x = wprowadzZakres(0, arkusz->getWidth()-1);
	cout << "Jak ma kolumna być posortowana \n 0. Rosnąco \n 1. Malejąco " << endl;
	bool desc = (wprowadzZakres(0,1)?true:false);
	sortColumn(&(*arkusz)[x],desc);
}
