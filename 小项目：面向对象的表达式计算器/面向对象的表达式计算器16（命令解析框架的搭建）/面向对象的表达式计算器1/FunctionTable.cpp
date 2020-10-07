#include "FunctionTable.h"
#include "SymbolTable.h"  

#include"DebugNew.h"
#include <cmath>  
#include <cassert>  
#include <iostream>  

struct FunctionEntry
{
	PtrFun pFun_;
	char* funName_;
};

//配置一张表格 用来存储常用的数学函数
FunctionEntry Entrys[] =
{
	log,    "log",
	log10,  "log10",
	exp,    "exp",
	sqrt,   "sqrt",
	sin,    "sin",
	cos,    "cos",
	tan,    "tan",
	sinh,   "sinh",
	cosh,   "cosh",
	tanh,   "tanh",
	asin,   "asin",
	acos,   "acos",
	atan,   "atan"
};

FunctionTable::FunctionTable(SymbolTable& tbl)
	: size_(sizeof(Entrys) / sizeof(Entrys[0]))//得到数组的个数
{
	Init(tbl);
}

void FunctionTable::Init(SymbolTable& tbl)
{
	std::cout << "function list:" << std::endl;
	pFuns_ = new PtrFun[size_];
	for (unsigned int i = 0; i<size_; ++i)
	{
		pFuns_[i] = Entrys[i].pFun_;
		unsigned int j = tbl.Add(Entrys[i].funName_);
		assert(i == j);
		std::cout << Entrys[i].funName_ << std::endl;
	}
}

FunctionTable::~FunctionTable()
{
	delete[] pFuns_;
}
