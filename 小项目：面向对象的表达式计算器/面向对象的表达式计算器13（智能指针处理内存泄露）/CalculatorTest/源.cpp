//main.cpp
#include<iostream>
using namespace std;

#include"DebugNew.h"
#include"Node.h"
void main()
{
	//int* p = new int;//堆栈开辟四个字节的空间
	//				 //delete p;

	//int* p2 = new int[5];
	////delete[] p2;

	//Node* pNode = new Node;
	//pNode这里为裸指针
	//裸指针 包装器

	//pNode->Calc();
	NodePtr np(new Node);
	np->Calc();
	//通过重载指针 运算符 可以访问类对象指针pNode的方法
	NodePtr np2(np);
	NodePtr np3;
	np3= np2;
	system("pause");
}
//栈展开的过程中指针不会自动释放
//应用RAII技巧 将裸指针转换为智能指针（是一个类）
//将指针转换为对象
//对象的析构函数在生存期借宿的时候是确定被调用的