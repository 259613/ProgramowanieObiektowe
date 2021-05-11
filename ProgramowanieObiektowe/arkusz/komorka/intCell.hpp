/// @file
#ifndef HEADER_GUARD_INTCELL_
#define HEADER_GUARD_INTCELL_
#include "cell.hpp"

class Cell{
    bool calculate = false;
    public:
    virtual int getValue();
    virtual std::string  toString();
    virtual void setValue();
};

#endif