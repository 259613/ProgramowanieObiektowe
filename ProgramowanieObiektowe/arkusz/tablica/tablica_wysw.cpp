/// @file

#include <iostream>
#include "tablica.hpp"
#include "tablica_wysw.hpp"
#include "../../utility/utility.hpp"

using namespace std;

void wyswietlTablica(Arkusz arkusz)
{
    cout << "Tablica o rozmiarze " << arkusz.rozmiarX() << " : " << arkusz.rozmiarY() << endl;
    for (size_t x = 0; x < arkusz.rozmiarX(); x++)
    {
        cout << ((char) arkusz.getColumnType(x)) << '\t';
    }
    cout << endl;
    for (size_t y = 0; y < arkusz.rozmiarY(); y++)
    {
        for (size_t x = 0; x < arkusz.rozmiarX(); x++)
        {
            cout << arkusz.zwrocWartosc(x, y).toString() << '\t';
             cout << arkusz.zwrocWartosc(x, y).getValue() << '\t';
        }
        cout << endl;
    }
}

void wprowadzWartosc(Arkusz *arkusz)
{
    size_t wspX, wspY;
    cout << "Wprowadź której kolumny: ";
    wspX = wprowadzZakres(0, arkusz->rozmiarX() - 1);
    cout << "Wprowadź który wiersz: ";
    wspY = wprowadzZakres(0, arkusz->rozmiarY() - 1);
    cout << "Podaj wartość ";
    if (arkusz->getColumnType(wspX)==cellType::typeString)
    {
        cout << "tekstową: ";
        string wart{};
        czyscBufor();
        getline(cin, wart);
        arkusz->modyfikacjaWartosci(wspX, wspY, wart);
    }
    else
    {
        cout << "int: ";
        int wart{};
        wart = wprowadzInt();
        arkusz->modyfikacjaWartosci(wspX, wspY, wart);
    }
}
