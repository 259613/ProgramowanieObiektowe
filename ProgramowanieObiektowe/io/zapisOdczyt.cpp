/// @file

#include <fstream>
#include "zapisOdczyt.hpp"
#include <stdexcept>
#include "../arkusz/komorka/intCell.hpp"
#include "../arkusz/komorka/stringCell.hpp"
using namespace std;



void saveFile(Sheet sheet, std::string fileName)
{
	ofstream file(fileName);
	if(file.good())
	{
		file << sheet.getWidth() << endl << sheet.getHeight() << endl;

		for(int i = 0; i < sheet.getWidth(); i++)
		{
			file << static_cast<int>(sheet[i].getType()) << "\t";
		}
		file << endl;
		for(int y = 0; y < sheet.getHeight(); y++)
		{
			for(int x = 0; x < sheet.getWidth(); x++)
			{
				string value{};
				switch(sheet[x].getType())
				{

					case CellType::StringCell:{
						try{
							value = dynamic_cast<StringCell&>(sheet[x][y])
									.getStringValue();
						}
						catch(...)
						{
							value = "?";
						}
						break;
					}

					case CellType::IntCell:{
						try{
							value = to_string(dynamic_cast<IntCell&>(sheet[x][y])
											  .getIntValue());
						}
						catch(...) {
							value = "0";
						}
						break;
					}
					default: {
						value = "0";
						break;
					}
				}
				file << value << (x < sheet.getWidth()-1 ? ", " : "");
			}
			if(y < sheet.getHeight() - 1){
				file << endl;
			}
		}
	}
	else{
		throw BadFileException();
	}
}

void loadFile(Sheet* sheet, std::string fileName)
{
	ifstream file(fileName);
	if(file.good()){

		size_t width, height;
		file >> width >> height;

		if(width <= 0){
			throw bad_array_new_length();
		}

		int tmp;
		CellType* types = new CellType[width];
		for(int i = 0; i < width; i++){
			file >> tmp;
			switch(tmp)
			{
				case 0:
				{
					types[i] = CellType::StringCell;
					break;
				}
				case 1:
				{
					types[i] = CellType::IntCell;
					break;
				}
				default:
				{
					break;
				}
			}
		}

		Sheet newSheet(width, height, types);

		string tmpText{};
		file.ignore(10,'\n');

		for(int y = 0; y < height; y++){
			for(int x = 0; x < width; x++){

				getline(file,tmpText,
						(x < width-1 ? ',' : '\n' ));

				if(types[x]==CellType::StringCell){
					newSheet[x][y].setValue(&tmpText);
				}

				else if(types[x]==CellType::IntCell){
					tmp = stoi(tmpText);
					newSheet[x][y].setValue(&tmp);
				}

			}

		}
		*sheet = newSheet;
	}

	else{
		throw BadFileException();
	}
}
