/// @file

#include "cellConverter.hpp"
intCell * toIntCell(stringCell convertedCell){
    int value{};
    try{
        value = std::stoi(convertedCell.toString());
    }
    catch(...){}
    return new intCell(value);
    
}

stringCell * toStringCell(intCell convertedCell){
    
    return new stringCell(convertedCell.toString());
}