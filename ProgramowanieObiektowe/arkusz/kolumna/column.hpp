///@file
#ifndef HEADER_GUARD_COLUMN_
#define HEADER_GUARD_COLUMN_

#include "../../error.hpp"
#include "../komorka/cell.hpp"
#include "../komorka/cellType.hpp"
#include <cstddef>

class Sheet;


class Column{
	Cell** cellArray;
	size_t height;
	CellType type;
protected:
	static Cell** generateCellArray(size_t height, CellType type);
public:
	void resize(size_t newHeight);

	Column(size_t height, CellType type);

	std::size_t getHeight();
	CellType getType();


	Cell& getCell(size_t y);
	Cell& operator[](size_t y);



};

#endif
