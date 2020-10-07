//max.h
#ifndef _MAX_H_
#define _MAX_H_
#include<string>
#include<iostream>

template <typename T>
const T& max(const T& a, const T& b)//必须将实现放在头文件
{
	return a < b ? b : a;
}

//函数模板重载
template <typename T>
const T& max(const T& a, const T& b, const T& c)//必须将实现放在头文件
{
	return ::max(a, b) < c ? c : ::max(a, b);
}

//非模板函数重载一个同名的函数模板
const int& max(const int& a, const int& b)
{
	std::cout << "non template function:" << std::endl;
	return a < b ? b : a;
}

//函数模板特化
template<>
const char* const& max(const char* const& a, const char* const& b)
{
	return strcmp(a, b) < 0 ? b : a;//比较内容
}



#endif