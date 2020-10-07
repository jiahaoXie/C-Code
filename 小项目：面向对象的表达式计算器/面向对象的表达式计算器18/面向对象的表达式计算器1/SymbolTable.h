//SymbolTable实现
//接下来的任务是让表达式支持变量与函数。
//如a = 100
//a + 5 + log(0)
//这里变量名与函数都算是符号，所以要有一个表存储这些符号SymbolTable

#ifndef  _SYMBOL_TABLE_H_  
#define  _SYMBOL_TABLE_H_  

#include <map>  
#include <string>  
#include"Serial.h"
//实现SymbolTable类的序列化
class SymbolTable:public Serialiazble
{	//公有继承类Serialiazble，目的是为了实现序列化
public:
	enum { IDNOTFOUND = 0xffffffff };
	SymbolTable() :curId_(0) {};

	void Serialize(Serializer& out) const ;
	void DeSerialize(DeSerializer& in) ;

	unsigned int Add(const std::string& str);
	unsigned int Find(const std::string& str)const;
	void Clear();
	std::string GetSymbolName(unsigned int id)const;
	~SymbolTable(void);
	unsigned int GetCurId() const
	{
		return curId_;
	}

private:
	std::map<const std::string, unsigned int> dictionary_;
	unsigned int curId_;
};

#endif  
