/// @file
#include "cell.hpp"





template <>
bool Cell<int>::Calculateable(){
    return true;
}




template <>
int Cell<int>::getValue(){
    return Value;
}



template <>
std::string Cell<std::string>::getString(){
    return Value;
}


