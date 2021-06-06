/// @file

#include "tablica.hpp"
#include <limits>
#include <stdexcept>


Column** Sheet::createColumnArray(size_t width, size_t height, CellType* types)
{
	if(width <= 0){
		throw std::bad_array_new_length();
	}
	Column** newArray = new Column*[width];
	for(int i = 0; i < width; i++){
		newArray[i] = new Column(height, types[i]);
	}
	return newArray;
}

Sheet::Sheet(size_t width, size_t height, CellType* types) :
	width(width), height(height)
{
	array = createColumnArray(width,height,types);
}

size_t Sheet::getWidth()
{
	return width;
}

size_t Sheet::getHeight(){
	return height;
}

Column& Sheet::getColumn(size_t x)
{
	if(x < width){
		return *(array[x]);
	}
	throw std::out_of_range("Element poza zakresem tablicy");
}

Column& Sheet::operator[](size_t x){
	return getColumn(x);
}

//void Sheet::resize(size_t x, size_t y)
//{

//	if(x < width){
//		width = x;
//	}
//	auto types = new CellType[x];
//	for(int i = 0; i < x; i ++){
//		if(i < width){
//			types[i] = array[i]->getType();
//		}
//		else{
//			types[i] = CellType::IntCell;
//		}
//	}

//	auto newArray = createColumnArray(x,y,types);
//	delete[] types;
//	delete[] array;

//	array = newArray;
//}

void Sheet::resize(size_t x, size_t y){

	Column** newArray = new Column*[x];
	for(int i = 0; i < x; i++){
		if(i < width){
			newArray[i] = array[i];
			(*(newArray[i])).resize(y);
		}
		else{
			newArray[i] = new Column(y, CellType::IntCell);
		}
	}
	delete[] array;
	array = newArray;
	width = x;
	height = y;
}
