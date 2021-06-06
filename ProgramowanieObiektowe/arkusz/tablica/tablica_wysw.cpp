/// @file

#include <iostream>
#include "tablica_wysw.hpp"
#include "../komorka/intCell.hpp"
#include "../komorka/stringCell.hpp"
#include "../../utility/utility.hpp"

void DisplaySheet(Sheet sheet){
	for(int i = 0; i < sheet.getHeight(); i++){
		for(int j = 0; j < sheet.getWidth(); j++){
			switch(sheet[j].getType()){
				case CellType::StringCell:{
					std::cout << dynamic_cast<StringCell&>(sheet[j][i])
								 .getStringValue()
							  << "\t";
					break;
				}
				case CellType::IntCell:{
					std::cout << dynamic_cast<IntCell&>(sheet[j][i])
								 .getIntValue()
							  << "\t";
					break;
				}
				default:
				{
					break;
				}
			}
		}
		std::cout << std::endl;
	}
}
