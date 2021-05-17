/// @file

#include "stringCell.hpp"

stringCell::stringCell(std::string Val) : Value(Val) {}

std::string stringCell::toString(){
    return Value;
}

void stringCell::setValue(std::string Val){
    Value = Val;
}