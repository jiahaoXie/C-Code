//在Calc中要增加新的成员变量FunctionTable    
//记得初始化的顺序，让符号表先初始化  然后再初始化函数表  最后初始化存储表

#ifndef _CALC_H_  
#define _CALC_H_  

#include "SymbolTable.h"  
#include "Storage.h"  
#include <string>  
#include "FunctionTable.h"
class Parser;

class Calc
{
	friend class Parser;//友元
public:
	Calc() : funTbl_(symTbl_),storage_(symTbl_) {}
private:
	Storage& GetStorage() 
	{
		return storage_;
	}
	PtrFun GetFunction(unsigned int id) const
	{
		return funTbl_.GetFunction(id);
	}
	bool IsFunction(unsigned int id) const
	{
		return id < funTbl_.Size();
	}
	unsigned int AddSymbol(const std::string& str);
	unsigned int FindSymbol(const std::string& str) const;
	SymbolTable symTbl_;
	//先构造函数表 再构造变量表

	FunctionTable funTbl_;
	Storage storage_;
};

#endif // _CALC_H_ 

