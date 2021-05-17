/// @file

#ifndef HEADER_GUARD_STRINGCELL_
#define HEADER_GUARD_STRINGCELL_
#include "cell.hpp"

/**
 * @brief Klasa komórki tekstowej
 * 
 * Klasa komórki posiadającej wartość typu string
 * 
 */
class stringCell : public Cell{
    /**
     * @brief Wartość komórki
     * Wartość string komórki
     */
    std::string Value;

    public:

    /**
     * @brief Konstruktor komórki tekstowej
     * Konstruktor komórki z wartością początkową 
     * @param[in] Val Wartość początkowa komórki
     */
    stringCell(std::string Val);
    
    std::string  toString();
    
    /**
     * @brief setter wartości komórki
     * Setter umożliwiający ustawienie wartości tekstowej w komórce
     * @param[in] Val umożliwia modyfikacje wartości komórki
     */
    void setValue(std::string Val);
};
#endif