///@file
#include "operacje.hpp"
#include "../arkusz/komorka/intCell.hpp"
#include <algorithm>
int maxWiersz(Sheet sheet, size_t row)
{
	bool flag{};
	int result{};
	for(int x = 0; x < sheet.getWidth(); x++){
		try{
			auto currentCell = dynamic_cast<IntCell&>(sheet[x][row]);
			auto currentValue = currentCell.getIntValue();
			if(currentValue > result || !flag)
			{
				result = currentValue;
				flag = true;
			}
		}
		catch(...){}
	}
	return result;
}


int minWiersz(Sheet sheet, size_t row)
{
	bool flag{};
	int result{};
	for(int x = 0; x < sheet.getWidth(); x++){
		try{
			auto currentCell = dynamic_cast<IntCell&>(sheet[x][row]);
			auto currentValue = currentCell.getIntValue();
			if(currentValue < result || !flag)
			{
				result = currentValue;
				flag = true;
			}
		}
		catch(...){}
	}
	return result;
}


int sumaWiersz(Sheet sheet, size_t row)
{
	int result{};
	for(int x = 0; x < sheet.getWidth(); x++){
		try{
			auto currentCell = dynamic_cast<IntCell&>(sheet[x][row]);
			auto currentValue = currentCell.getIntValue();
			if(currentValue > result)
			{
				result += currentValue;
			}
		}
		catch(...){}
	}
	return result;
}

int maxKolumna(Column column)
{
	bool flag{};
	int result{};
	for(auto element : column)
	{

		auto currentCell = dynamic_cast<IntCell*>(element);
		auto currentValue = currentCell->getIntValue();
		if(currentValue > result || !flag)
		{
			result = currentValue;
			flag = true;
		}
	}
	return result;
}

int minKolumna(Column column)
{
	bool flag{};
	int result{};
	for(auto element : column)
	{

		auto currentCell = dynamic_cast<IntCell*>(element);
		auto currentValue = currentCell->getIntValue();
		if(currentValue < result || !flag)
		{
			result = currentValue;
			flag = true;
		}
	}
	return result;
}

int sumaKolumna(Column column)
{
	bool flag{};
	int result{};
	for(auto element : column)
	{
		auto currentCell = dynamic_cast<IntCell*>(element);
		auto currentValue = currentCell->getIntValue();
		if(currentValue > result || !flag)
		{
			result = currentValue;
			flag = true;
		}
	}
	return result;
}


void sortKolumna(Column *column, bool descending){

		std::sort((*column).begin(),(*column).end(),[descending](Cell* x, Cell* y) ->
				bool{return((x->getValue()))
							> (y->getValue()) ^ !descending; } );

}

int countCalculateableColumns(Sheet sheet)
{
	int count{};
	for(int i = 0; i < sheet.getWidth(); i++){
		count += (sheet[i].getType()!=CellType::StringCell?1:0);
	}
	return count;
}
