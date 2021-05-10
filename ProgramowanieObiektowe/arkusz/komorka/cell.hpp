/// @file
#ifndef HEADER_GUARD_CELL_
#define HEADER_GUARD_CELL_
#include "../../error.hpp"
#include <string>
#include <sstream>

/** 
 * \brief Szablon klasy komórki
 * Klasa komórka przechowywująca pewną wartość określonego typu
 */
template <class T>
class Cell
{
    /** 
     * \brief Wartość komórki
     *  Pole wartości komórki  
     */
    T Value;
    public:

    Cell(){};
    /**
     *  \brief Konstruktor komórki
     * Konstruktor komórki nadający jej wartość początkową określonego typu
     * 
     * @param[in] val Wartość początkowa komórki  
     */
    Cell(T val);

    /**
     * \brief Metoda od pobierania wartości matematycznej
     * Zwraca wartość typu Int
     * @return Zwraca wartość typu int, jeśli komórka jest innego typu niż int zwraca 0.
     */
    int getValue();

    /**
     * \brief Metoda od pobierania wartości ciągu znaków
     * Zwraca wartość typu String - ciąg znaków do wykorzystywania przykładowo w wypisywaniu
     * Wartości innego typu niż string są przepuszczane przez stringstream celem "rzutowania" na String
     * @return Zwraca wartość typu string
     */
    std::string getString();

    /**
     * \brief Metoda od ustawienia wartości komórki
     * Metoda ustawia wartość komórki określonego typu
     * @param[in] val Nowa wartość komórki
     */
    void setValue(T val);

    /**
     * \brief Sprawdź czy komórka może posłużyć w obliczeniach
     * Metoda służy do sprawdzania czy typ komórki umożliwia jej branie udziału w funkcjach arytmetycznych
     * @return Zwraca wartość logiczną 'true' dla elementów które można obliczać a 'false' dla tych które nie mogą być obliczane.
     */
    bool Calculateable();
};


template <class T>
Cell<T>::Cell(T val): Value(val) {}

template <class T>
bool Cell<T>::Calculateable(){
    return false;
}

template <class T>
int Cell<T>::getValue(){
    return 0;
}

template <class T>
std::string Cell<T>::getString(){
    std::stringstream ss;
    ss << Value;
    return ss.str();
}

template <class T>
void Cell<T>::setValue(T val){
    Value = val;
}

// Specializations

template <>
bool Cell<int>::Calculateable();

template <>
int Cell<int>::getValue();

template <>
std::string Cell<std::string>::getString();

#endif