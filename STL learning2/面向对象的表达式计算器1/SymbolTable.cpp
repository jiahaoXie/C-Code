#include "SymbolTable.h"
#include "Exception.h"

#include <algorithm>  

void SymbolTable::Serialize(Serializer& out) const
{//��������
	out << dictionary_.size();//��д���ĳ���
	//Ȼ��д��map�������������(д���������õ�������)
	std::map<const std::string, unsigned int> ::const_iterator it;
	for (it = dictionary_.begin(); it != dictionary_.end(); ++it)
		out << it->first << it->second;
	out << curId_;

}
void SymbolTable::DeSerialize(DeSerializer& in)
{//���ļ��м�������
	dictionary_.clear();//�Ƚ�ԭ�е��������
	unsigned int size;
	in >> size;
	for (unsigned int i = 0; i < size; i++)
	{
		std::string str;
		unsigned int id;
		in >> str >> id;
		dictionary_[str] = id;
	}
	in >> curId_;

}
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

//����������÷�  function object  functor(�º���)  
//��һ�������ʹ��������һ������  ������������()�����  
//stl�������֮һ  
//����  �㷨 ������ ������ ��������  �ڴ����������  
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
	if (it == dictionary_.end())
	{
		throw Exception("Internal Error:missing entry in symbol table");
	}
	return it->first;
}
