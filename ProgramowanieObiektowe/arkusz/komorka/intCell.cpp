/// @file

#include "intCell.hpp"
#include <sstream>

IntCell::IntCell(int value)
{
	this->value = value;
}

void* IntCell::getValue(){

	return &value;
}

void IntCell::setValue(void* value)
{
	this->value = *((int*)value);
}

int IntCell::getIntValue(){
	return value;
}
