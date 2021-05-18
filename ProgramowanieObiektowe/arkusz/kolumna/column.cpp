///@file
#include "column.hpp"
#include "../komorka/intCell.hpp"
#include "../komorka/stringCell.hpp"
#include <stdexcept>

Column::Column(size_t sizeY, bool textOnly): textOnly(textOnly){
	cells = genColumn(sizeY, textOnly);
}

Cell ** Column::genColumn(size_t sizeY, bool textOnly){
	Cell ** newCol = new Cell*[sizeY];
	for(size_t i = 0; i < sizeY; i++){
		if(textOnly){
			newCol[i] = new stringCell("x"); 
		}
		else{
			newCol[i] = new intCell(0);
		}
	}
	return newCol;
}

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

void Column::resizeColumn(std::size_t sizeY){
	if(sizeY <= 0){
		throw std::bad_array_new_length("", 0);
	}
	else if(sizeY < this->sizeY){
		this->sizeY = sizeY;
	}
	Cell ** newCellArr = new Cell*[sizeY];
	for(size_t i = 0; i < this->sizeY; i++){
		newCellArr[i] = cells[i]; 
	}
	
}