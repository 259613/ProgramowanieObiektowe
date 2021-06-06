///@file

#include "column.hpp"
#include "../komorka/intCell.hpp"
#include "../komorka/stringCell.hpp"
#include <stdexcept>

Cell** Column::generateCellArray(size_t height, CellType type)
{

	if(height <= 0){
		throw std::bad_array_new_length();
	}

	Cell** newColumn = new Cell*[height];
	for(size_t i = 0; i < height; i++){
		Cell* newCell;
		switch(type){
			case CellType::StringCell:{
				newCell = new StringCell();
				break;
			}
			case CellType::IntCell:{
				newCell = new IntCell();
				break;
			}
			default:{
				newCell = new IntCell();
				break;
			}
		}
		newColumn[i] = newCell;
	}

	return newColumn;

}


Column::Column(size_t height, CellType type)
{
	cellArray = generateCellArray(height, type);
	this->type = type;
	this->height = height;
}


size_t Column::getHeight()
{
	return height;
}

CellType Column::getType()
{
	return type;
}

void Column::resize(size_t newHeight)
{
	if(newHeight== height){
		return;
	}
	auto newColumn = generateCellArray(newHeight, type);
	if(height > newHeight){
		height = newHeight;
	}
	for(int i = 0; i < height; i++)
	{
		auto oldVal = (*(cellArray[i])).getValue();
		(*(newColumn[i])).setValue(oldVal);
	}
	height = newHeight;
	delete[] cellArray;
	cellArray = newColumn;
}

Cell& Column::getCell(size_t y){
	if(y < height){
		return *(cellArray[y]);
	}
	throw std::out_of_range("Poza zakresem kolumny!");
}

Cell& Column::operator[](size_t y){
	return getCell(y);
}
