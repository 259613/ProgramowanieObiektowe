/// @file

#include "stringCell.hpp"

StringCell::StringCell(std::string value)
{
	this->value = value;
}

std::string StringCell::getValue()
{
	return value;
}

void StringCell::setValue(std::string value){
	this->value = value;
}

