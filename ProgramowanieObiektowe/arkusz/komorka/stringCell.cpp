/// @file

#include "stringCell.hpp"

StringCell::StringCell(std::string value)
{
	this->value = value;
}

void* StringCell::getValue()
{
	return &value;
}

void StringCell::setValue(void* value){
	this->value = *((std::string*)value);
}

std::string StringCell::getStringValue(){
	return value;
}
