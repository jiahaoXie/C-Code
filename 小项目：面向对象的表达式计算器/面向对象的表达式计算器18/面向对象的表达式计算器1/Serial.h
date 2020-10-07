#ifndef _SERIAL_H
#define _SERIAL_H
#include<fstream>
#include<string>
//写入文件
class Serializer
{
public:
	Serializer(const std::string& fileName);
	Serializer& put(int x);
	Serializer& put(unsigned int x);
	Serializer& put(long x);
	Serializer& put(double x);
	Serializer& put(unsigned long x);
	Serializer& put(const std::string x);
	Serializer& put(bool x);

	//operator<< 插入运算符
	Serializer& operator<<(int x);
	Serializer& operator<<(unsigned int x);
	Serializer& operator<<(long x);
	Serializer& operator<<(double x);
	Serializer& operator<<(unsigned long x);
	Serializer& operator<<(const std::string x);
	Serializer& operator<<(bool x);

private:
	std::ofstream stream_;
};


//文件读取
class DeSerializer
{
public:
	DeSerializer(const std::string& fileName);
	DeSerializer& get(int& x);
	DeSerializer& get(unsigned int& x);
	DeSerializer& get(long& x);
	DeSerializer& get(double& x);
	DeSerializer& get(unsigned long& x);
	DeSerializer& get( std::string& x);
	DeSerializer& get(bool& x);

	//operator>> 输出运算符
	DeSerializer& operator>>(int& x);
	DeSerializer& operator>>(unsigned int& x);
	DeSerializer& operator>>(long& x);
	DeSerializer& operator>>(double& x);
	DeSerializer& operator>>(unsigned long& x);
	DeSerializer& operator>>(std::string& x);
	DeSerializer& operator>>(bool& x);

private:
	std::ifstream stream_;
};

class Serialiazble {
public:
	virtual void Serialize(Serializer& out) const = 0;
	virtual void DeSerialize(DeSerializer& in) = 0;
};

#endif//_SERIAL_H