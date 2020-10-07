//动态创建对象（简单理解为通过一个字符串得到一个类） 有点类似于Java的反射技术
//运行时动态获取类型信息（方法与属性）
//
//动态创建对象
//动态调用对象的方法
//动态操作对象的属性
//
//需要给每个类添加元数据
//
//动态创建对象
//对原有的类不做任何更改，只需要增加一个宏就能实现动态创建
//注：就是为了消除if else
//可以在初始化静态成员变量前面加上__declspec(selectany) ，
		//这样编译器会自动剔除对该静态成员的重复定义。

#include "Shape.h"  
#include "DynBase.h"  
#include <iostream>  
#include <vector>  
#include <string>  
using namespace std;



void DrawAllShapes(const vector<Shape*>& v)
{
	vector<Shape*>::const_iterator it;
	for (it = v.begin(); it != v.end(); ++it)
	{
		(*it)->Draw();
	}
}

void DeleteAllShapes(const vector<Shape*>& v)
{
	vector<Shape*>::const_iterator it;
	for (it = v.begin(); it != v.end(); ++it)
	{
		delete(*it);
	}
}


int main(void)
{
	vector<Shape*> v;

	Shape* ps;
	ps = static_cast<Shape*>(DynObjectFactory::CreateObject("Circle"));
	v.push_back(ps);
	ps = static_cast<Shape*>(DynObjectFactory::CreateObject("Square"));
	v.push_back(ps);
	ps = static_cast<Shape*>(DynObjectFactory::CreateObject("Rectangle"));
	v.push_back(ps);

	DrawAllShapes(v);
	DeleteAllShapes(v);

	system("pause");
	return 0;
}