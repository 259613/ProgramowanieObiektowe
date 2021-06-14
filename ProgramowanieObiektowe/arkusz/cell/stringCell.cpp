/// @file

#include "stringCell.hpp"
#include <typeinfo>
#include <typeinfo>
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


double StringCell::operator+(double rhs){
	return rhs;
}

bool StringCell::operator>(Cell& rhs)
{
	if(typeid(rhs) == typeid(StringCell)){
		return value > rhs.getValue();
	}
	return true;

}

bool StringCell::operator<(Cell& rhs)
{
	if(typeid(rhs) == typeid(StringCell)){
		return value < rhs.getValue();
	}
	return true;
}



