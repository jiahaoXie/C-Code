//��Calc��Ҫ�����µĳ�Ա����FunctionTable    
//�ǵó�ʼ����˳���÷��ű��ȳ�ʼ��  Ȼ���ٳ�ʼ��������  ����ʼ���洢��

#ifndef _CALC_H_  
#define _CALC_H_  

#include "SymbolTable.h"  
#include "Storage.h"  
#include <string>  
#include "FunctionTable.h"
#include "Serial.h"

class Parser;

class Calc:public Serialiazble
{//���м̳���Serialiazble��Ŀ����Ϊ��ʵ�����л�
	
	friend class Parser;//��Ԫ
public:
	void Serialize(Serializer& out) const;
	void DeSerialize(DeSerializer& in);

	Calc() :funTbl_(symTbl_), storage_(symTbl_) {}
	void ListFun() const;
	void ListVar() const;
private:
	bool GetVariableValue(unsigned int id,double& val)const;
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

