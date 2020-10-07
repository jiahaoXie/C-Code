//max.h
#ifndef _MAX_H_
#define _MAX_H_
#include<string>
#include<iostream>

template <typename T>
const T& max(const T& a, const T& b)//���뽫ʵ�ַ���ͷ�ļ�
{
	return a < b ? b : a;
}

//����ģ������
template <typename T>
const T& max(const T& a, const T& b, const T& c)//���뽫ʵ�ַ���ͷ�ļ�
{
	return ::max(a, b) < c ? c : ::max(a, b);
}

//��ģ�庯������һ��ͬ���ĺ���ģ��
const int& max(const int& a, const int& b)
{
	std::cout << "non template function:" << std::endl;
	return a < b ? b : a;
}

//����ģ���ػ�
template<>
const char* const& max(const char* const& a, const char* const& b)
{
	return strcmp(a, b) < 0 ? b : a;//�Ƚ�����
}



#endif