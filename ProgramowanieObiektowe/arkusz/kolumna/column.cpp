#include "column.hpp"
#include "../komorka/intCell.hpp"
#include "../komorka/stringCell.hpp"

Column::Column(size_t y, cellType type): sizeY(y), columnType(type){

};

cellType Column::getType(){
    return columnType;
}

Cell& Column::getElement(size_t y){
    if(y < sizeY && y > 0){
        return *cells[y];
    }
    else{
        return *(cells[0]);
    }
}

size_t Column::getSizeY(){
    return sizeY;
}

Wyjatki Column::modifyCell(size_t y, std::string wartosc)
{
	if (y > sizeY)
	{
		return Wyjatki::TABLICA_ZAKR;
	}

	static_cast<stringCell &>((*cells[y])).setValue(wartosc);
	return Wyjatki::BRAK;
}

Wyjatki Column::modifyCell(size_t y, int wartosc)
{
	if (y > sizeY)
	{
		return Wyjatki::TABLICA_ZAKR;
	}

	static_cast<intCell &>((*cells[y])).setValue(wartosc);
	return Wyjatki::BRAK;
}

Wyjatki Column::expandColumn(size_t newY)
{
	if (newY < 1)
	{
		return Wyjatki::TABLICA_SIZE;
	}

	if (sizeY > newY)
	{
		sizeY = newY;
	}

	Cell** newArray;
	cellType newTracker = columnType;

    newArray = createColumnArray(newY, columnType);

	for (size_t y = 0; y < sizeY; y++)
	{
			if (columnType == cellType::typeString)
			{
				static_cast<stringCell &>(*newArray[y]).setValue((*cells[y]).toString());
			}
			else
			{
				static_cast<intCell &>(*newArray[y]).setValue((*cells[y]).getValue());
			}
		
		delete[](cells)[y];
	}
    sizeY = newY;
    cells = newArray;
}
    Cell** Column::createColumnArray(size_t newY, cellType type){
        Cell** newColumn = new Cell*[newY];
        for(int i = 0; i < newY; i++){
            if(type==cellType::typeString){

                newColumn[i] = new stringCell(".");
            }
            else if(type == cellType::typeInt){
                newColumn[i] = new intCell(0);
            }
        }
    }