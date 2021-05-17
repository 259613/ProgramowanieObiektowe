/// @file

#include "cell.hpp"
int Cell::getValue(){
    return 0;
}

bool Cell::isCalcualteable(){
    return calculate;
}

std::string Cell::toString(){
    return "";
}

int Cell::operator+(Cell c1){
    return getValue() + c1.getValue(); 
}

int Cell::operator+(int wart){
    return getValue()+wart;
}