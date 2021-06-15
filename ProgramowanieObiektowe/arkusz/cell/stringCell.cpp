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


bool StringCell::operator>(StringCell& rhs)
{

	return value > rhs.getValue();
}

bool StringCell::operator<(StringCell& rhs)
{
	return value < rhs.getValue();
}

bool StringCell::operator>(Cell& rhs)
{
	return true;
}

bool StringCell::operator<(Cell& rhs)
{
	return true;
}



