/// @file

#ifndef HEADER_GUARD_ADAPTER_
#define HEADER_GUARD_ADAPTER_
#include "intCell.hpp"
#include "stringCell.hpp"

//class IntCellToStringCellAdapter: public StringCell{

//	IntCell* adapted;

//public:
//	IntCellToStringCellAdapter(IntCell* adapted){
//		this->adapted = adapted;
//	}

//	void setValue(void* value) override{
//		int val{};
//		try{
//			std::string element= *((string*)newValue);
//			int val = stoi(element);
//			newValue = element;
//		}
//		catch(...){
//			newValue = to_string(0);
//		}
//		adapted->setValue(&val);

//	}

//	void* getValue() override{
//		return &newValue;
//	}

//	std::string getStringValue() override{
//		return to_string(adapted->getIntValue());
//	}
//};

#endif
