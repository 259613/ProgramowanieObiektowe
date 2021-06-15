///@file
#include "operacje.hpp"
#include <algorithm>
double maxRow(Sheet sheet, size_t row)
{
	Cell* max = &sheet[0][row];

	for(int x = 1; x < sheet.getWidth(); x++){
		if(*max < sheet[x][row]){
			max = &sheet[x][row];
		}
	}
	return *max + 0;
}


double minRow(Sheet sheet, size_t row)
{
	Cell* min = &sheet[0][row];

	for(int x = 1; x < sheet.getWidth(); x++){
		if(*min > sheet[x][row]){
			min = &sheet[x][row];
		}
	}
	return *min + 0;
}


double sumRow(Sheet sheet, size_t row)
{
	double result{};
	for(int x = 0; x < sheet.getWidth(); x++){
		result = sheet[x][row] + result;
	}
	return result;
}




void sortColumn(Column *column, bool descending){

		std::sort((*column).begin(),
				  (*column).end(),
				  [descending](Cell* x, Cell* y) -> bool{return(*x < *y) ^ descending; } );

}

int countCalculateableColumns(Sheet sheet)
{
	int count{};
	for(int i = 0; i < sheet.getWidth(); i++){
		count += (sheet[i].getType()!=CellType::StringCell?1:0);
	}
	return count;
}
