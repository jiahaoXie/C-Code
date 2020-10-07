//Storage类用于存储一些变量与常量的值

#ifndef _STORAGE_H_  
#define _STORAGE_H_  

#include <vector>  
#include "Serial.h"

class SymbolTable;

class Storage:public Serialiazble
{//公有继承类Serialiazble，目的是为了实现序列化
public:

	void Serialize(Serializer& out) const;
	void DeSerialize(DeSerializer& in);

	Storage(SymbolTable& tbl);
	void Clear();
	bool IsInit(unsigned int id) const;
	void AddConstants(SymbolTable& tbl);
	double GetValue(unsigned int id) const;
	void SetValue(unsigned int id, double val);
	void AddValue(unsigned int id, double val);

private:
	std::vector<double> cells_;
	std::vector<bool> inits_;
};

#endif // _STORAGE_H_  
