/// @file

#include "intCell.hpp"
#include <sstream>
intCell::intCell(int Val) : Cell(true), Value(Val) { 
    }

int intCell::getValue(){
    return Value;
}
std::string intCell::toString(){
    std::stringstream ss;
    ss << Value;
    return ss.str();
}

void intCell::setValue(int Val){
    Value = Val;
}