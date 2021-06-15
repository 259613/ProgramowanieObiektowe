/// @file

#include <iostream>
#include <iomanip>
#include "tablica_wysw.hpp"
#include "../../utility/utility.hpp"

void DisplaySheet(Sheet sheet){
	size_t* colSizes = new size_t[sheet.getWidth()];
	std::cout << "|";
	for(size_t i = 0; i < sheet.getWidth(); i++){
		colSizes[i] = columnWidth(sheet[i]);
		std::cout << std::setw(colSizes[i]) << static_cast<int>(sheet[i].getType()) << " |";
	}

	std::cout << std::endl;

	for(int i = 0; i < sheet.getHeight(); i++){
		std::cout << "|";
		for(int j = 0; j < sheet.getWidth(); j++){
			std::cout << std::setw(colSizes[j]) << sheet[j][i].getValue() << " |";
		}
		std::cout << std::endl;
	}
	delete[] colSizes;
}

size_t columnWidth(Column column){
	size_t i {};
	for(auto x: column){
		if(i < x->getValue().size()){
			i = x->getValue().size();
		}
	}
	return i+1;
}
