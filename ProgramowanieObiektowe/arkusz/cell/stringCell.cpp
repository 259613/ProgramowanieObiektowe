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


double StringCell::operator+(double rhs){
	return rhs;
}

bool StringCell::operator>(Cell& rhs)
{
	try{
		auto stringRhs = dynamic_cast<StringCell&>(rhs);
		return value > stringRhs.getValue();
	}
	catch(...){
		return true;
	}
}

bool StringCell::operator<(Cell& rhs)
{
	try{
		auto stringRhs = dynamic_cast<StringCell&>(rhs);
		return value < stringRhs.getValue();
	}
	catch(...){
		return true;
	}
}



