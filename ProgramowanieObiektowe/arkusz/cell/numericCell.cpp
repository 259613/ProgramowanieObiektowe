/// @file
#include "numericCell.hpp"
double NumericCell::operator+(double rhs)
{
	return rhs + getCalcValue();
}


bool NumericCell::operator>(Cell& rhs)
{
	try{
		auto &realRhs = dynamic_cast<NumericCell&>(rhs);
		return getCalcValue() > realRhs.getCalcValue();

	}
	catch(...){
		return false;
	}
}

bool NumericCell::operator<(Cell& rhs)
{
	try{
		auto &realRhs = dynamic_cast<NumericCell&>(rhs);
		return getCalcValue() < realRhs.getCalcValue();
	}
	catch(...){
		return false;
	}
}
