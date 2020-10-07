#include<iostream>
#include"max.h"
using namespace std;

//定义一个函数模板
//template <typename T>
//const T& max(const T& a, const T& b)//模板。不是函数，不能被调用
//{
//	return a < b ? b : a;
//}

void main()
{
	//函数模板是参数化的多态工具
	//函数模板不是函数，不能被执行。
	//只有在系统编译时实例化解析为模板函数（真正的函数），才能被执行
	cout << ::max(5.5, 15.15) << endl;		//自动推导为max(const int& a,const int& b)
	cout << ::max('a', 'c') << endl;		////自动推导为max(const char& a,const char& b)
	
	const char* str1 = "aaa";
	const char* str2 = "zzz";
	cout << ::max(str1, str2) << endl;
	cout << ::max(1, 5, 3) << endl;

	cout << ::max('a', 66) << endl;
	//由非模板函数const int& max(const int& a, const int& b)得到 因为char型可以隐式转换为iny型

	cout << ::max<>(97, 100) << endl;//模板函数自动推导 max(const int&,const int&)
	cout << ::max<int>(97, 100) << endl;//显示指定模板函数 max(const int&,const int&)

	system("pause");
}