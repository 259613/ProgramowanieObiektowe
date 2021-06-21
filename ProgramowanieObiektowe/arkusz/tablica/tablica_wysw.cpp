/// @file

#include <iostream>
#include <iomanip>
#include "tablica_wysw.hpp"
#include "../../utility/utility.hpp"

void DisplaySheet(Sheet sheet){

	size_t width = sheet.getWidth();
	size_t* colSizes = new size_t[width];

	std::cout << "|";
	for(size_t i = 0; i < width; i++){
		colSizes[i] = sheet[i].columnWidth()+1;
		std::cout << std::setw(colSizes[i])
				  << static_cast<int>(sheet[i].getType())
				  << " |";
	}

	std::cout << std::endl << "+";

	for(size_t i = 0; i < width; i++){
		std::cout << std::string(colSizes[i]+1,'-')
				  << "+";
	}

	std::cout << std::endl;

	for(int i = 0; i < sheet.getHeight(); i++){
		std::cout << "|";
		for(int j = 0; j < width; j++){
			std::cout << std::setw(colSizes[j])
					  << sheet[j][i].getValue() << " |";
		}

		std::cout << std::endl <<  std::endl;
	}
	delete[] colSizes;
}

