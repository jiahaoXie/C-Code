#include "SymbolTable.h"

#include <algorithm>  

SymbolTable::~SymbolTable(void)
{
}


unsigned int SymbolTable::Add(const std::string& str)
{
	dictionary_[str] = curId_;
	return curId_++;
}
unsigned int SymbolTable::Find(const std::string& str)const
{
	std::map<const std::string, unsigned int>::const_iterator it;
	it = dictionary_.find(str);

	if (it != dictionary_.end())
	{
		return it->second;
	}
	return IDNOTFOUND;
}
void SymbolTable::Clear()
{
	dictionary_.clear();
	curId_ = 0;
}

//函数对象的用法  function object  functor(仿函数)  
//让一个类对象使用起来像一个函数  本质上是重载()运算符  
//stl六大组件之一  
//容器  算法 迭代器 适配器 函数对象  内存分配器对象  
class IsEqualId
{
public:
	explicit IsEqualId(unsigned int id) :id_(id) {}
	bool operator()(const std::pair<const std::string, unsigned int> &it)const
	{
		return it.second == id_;
	}
private:
	unsigned int id_;
};

std::string SymbolTable::GetSymbolName(unsigned int id)const
{
	std::map<const std::string, unsigned int>::const_iterator it;
	it = std::find_if(dictionary_.begin(), dictionary_.end(), IsEqualId(id));

	return it->first;
}
