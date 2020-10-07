//Singleton.h
#ifndef _SINGLETON_H_
#define _SINGLETON_H_

#include <cstdlib>
#include <iostream>
using namespace std;

//用木板的形式来实现单例模式
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
				//单例模式对象的销毁 
				//atexit()函数是#include <cstdlib>中的注册函数，用于销毁变量
		}
	}
	static void Destroy()
	{
		delete instance_;
	}
	Singleton(const Singleton& other);//拷贝构造函数声明为私有，禁止拷贝
	Singleton& operator=(const Singleton& other);//禁止赋值操作
	Singleton();
	~Singleton();

	static T* instance_;        // 类模板的静态成员
};

template <typename T>
T* Singleton<T>::instance_ = 0;//静态成员在函数外面需要进行实例化

#endif//_SINGLETON_H_
