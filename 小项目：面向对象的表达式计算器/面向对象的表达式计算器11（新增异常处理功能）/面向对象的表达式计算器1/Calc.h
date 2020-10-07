//��Calc��Ҫ�����µĳ�Ա����FunctionTable    
//�ǵó�ʼ����˳���÷��ű��ȳ�ʼ��  Ȼ���ٳ�ʼ��������  ����ʼ���洢��

#ifndef _CALC_H_  
#define _CALC_H_  

#include "SymbolTable.h"  
#include "Storage.h"  
#include <string>  
#include "FunctionTable.h"
class Parser;

class Calc
{
	friend class Parser;//��Ԫ
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
	//�ȹ��캯���� �ٹ��������

	FunctionTable funTbl_;
	Storage storage_;
};

#endif // _CALC_H_ 

