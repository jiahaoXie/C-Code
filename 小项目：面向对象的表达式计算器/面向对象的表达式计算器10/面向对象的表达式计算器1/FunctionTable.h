//FunctionTable实现
//让表达式计算器支持函数运算
//对于一个好的科学计算器，内置函数是必需的。计算器必须能计算平方根、对数、三角函数等等。
//因而我们要让解析器识别这些函数, 并调用适当的数学库函数。
//FunctionTable实现

#ifndef _FUNCTION_TABLE_H_  
#define _FUNCTION_TABLE_H_  

class SymbolTable;

typedef double(*PtrFun)(double);

class FunctionTable
{
public:
	FunctionTable(SymbolTable& tbl);
	~FunctionTable();

	void Init(SymbolTable& tbl);
	unsigned int Size() const
	{
		return size_;
	}

	PtrFun GetFunction(unsigned int id) const
	{
		return pFuns_[id];
	}

private:
	PtrFun* pFuns_;//数学函数的入口指针
	unsigned int size_;
};

#endif // _FUNCTION_TABLE_H_ 
