/// @file

#include "intCell.hpp"
#include "../../error.hpp"

IntCell::IntCell(int value)
{
	this->value = value;
}

std::string IntCell::getValue(){

	return std::to_string(value);
}

void IntCell::setValue(std::string value)
{
	try{
		this->value = std::stod(value);
	}
	catch(...) {
		throw NotNumericValue();
	}
}

double IntCell::getCalcValue(){
	return value;
}

