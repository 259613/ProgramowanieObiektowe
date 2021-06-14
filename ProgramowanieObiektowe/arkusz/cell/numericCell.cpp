/// @file
#include "numericCell.hpp"
double NumericCell::operator+(double rhs)
{
	return rhs + getCalcValue();
}


bool NumericCell::operator>(Cell& rhs)
{
	double rhsVal = rhs + 0;
	if(getCalcValue() > rhsVal)
	{
		return true;
	}
	else if(rhsVal == 0){
		return rhs < *this;
	}
	return false;
}

bool NumericCell::operator<(Cell& rhs)
{
	double rhsVal = rhs + 0;
	if(getCalcValue() < rhsVal)
	{
		return true;
	}
	else if(rhsVal == 0){
		return rhs > *this;
	}
	return false;
}
