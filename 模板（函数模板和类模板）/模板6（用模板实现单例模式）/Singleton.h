//Singleton.h
#ifndef _SINGLETON_H_
#define _SINGLETON_H_

#include <cstdlib>
#include <iostream>
using namespace std;

//��ľ�����ʽ��ʵ�ֵ���ģʽ
template <typename T>
class Singleton
{
public:
	static T& GetInstance()
	{
		Init();
		return *instance_;
	}

private:
	static void Init()
	{
		if (instance_ == 0)
		{
			instance_ = new T;
			atexit(Destroy);
				//����ģʽ��������� 
				//atexit()������#include <cstdlib>�е�ע�ắ�����������ٱ���
		}
	}
	static void Destroy()
	{
		delete instance_;
	}
	Singleton(const Singleton& other);//�������캯������Ϊ˽�У���ֹ����
	Singleton& operator=(const Singleton& other);//��ֹ��ֵ����
	Singleton();
	~Singleton();

	static T* instance_;        // ��ģ��ľ�̬��Ա
};

template <typename T>
T* Singleton<T>::instance_ = 0;//��̬��Ա�ں���������Ҫ����ʵ����

#endif//_SINGLETON_H_
