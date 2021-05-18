///@file
#include "column.hpp"
#include <stdexcept>
Cell Column::getElement(int y){
	if(y >= sizeY || y < 0){
		throw std::out_of_range("Poza zakresem");
	}
	return (*cells[y]);
}

Cell& Column::operator[](int y){
	if(y >= sizeY || y < 0){
		throw std::out_of_range("Poza zakresem");
	}
	return (*cells[y]);
}

std::size_t Column::getSize(){
	return sizeY;
}