/// @file
#ifndef HEADER_GUARD_CELL_
#define HEADER_GUARD_CELL_
#include "../../error.hpp"
#include <string>

class Cell{
    
    bool calculate = false;

    public:

    virtual int getValue();

    virtual std::string  toString();

    virtual void setValue();

};

#endif