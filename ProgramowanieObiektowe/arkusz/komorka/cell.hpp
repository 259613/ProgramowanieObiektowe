/// @file

#ifndef HEADER_GUARD_CELL_
#define HEADER_GUARD_CELL_

class Cell{
public:
	/**
	 * @brief getValue
	 * @return
	 */
	virtual void* getValue()=0;

	/**
	 * @brief setValue
	 * @param[in] value
	 */
	virtual void setValue(void* value) = 0;


};

#endif
