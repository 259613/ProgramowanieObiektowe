/// @file

#include <iostream>
#include "tablica_wysw.hpp"
#include "../komorka/intCell.hpp"
#include "../komorka/stringCell.hpp"
#include "../../utility/utility.hpp"

void DisplaySheet(Sheet sheet){
	for(int i = 0; i < sheet.getHeight(); i++){
		for(int j = 0; j < sheet.getWidth(); j++){
			std::cout << sheet[j][i].getValue() << "\t";
		}
		std::cout << std::endl;
	}
}
