#ifndef HEADER_GUARD_TABLICA_
#define HEADER_GUARD_TABLICA_


/// @file

#include <cstddef>
#include "../../error.hpp"
#include "../kolumna/column.hpp"

class Sheet{
	Column** array;
	size_t width;
	size_t height;
protected:
	static Column** createColumnArray(size_t width, size_t height, CellType* types);
public:
	Sheet(size_t width, size_t height, CellType* types);

	size_t getWidth();
	size_t getHeight();

	Column& getColumn(size_t x);
	Column& operator[](size_t x);

	void resize(size_t x, size_t y);
};

#endif
