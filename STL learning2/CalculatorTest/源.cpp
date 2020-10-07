////main.cpp
//#include<iostream>
//#include<vector>
//#include<xmemory>
//using namespace std;
//
//#include"DebugNew.h"
//#include"Node.h"
//void main()
//{
//	//int* p = new int;//堆栈开辟四个字节的空间
//	//				 //delete p;
//
//	//int* p2 = new int[5];
//	////delete[] p2;
//
//	//Node* pNode = new Node;
//	//pNode这里为裸指针
//	//裸指针 包装器
//
//	//pNode->Calc();
//	NodePtr np(new Node);
//	np->Calc();
//	//通过重载指针 运算符 可以访问类对象指针pNode的方法
//	NodePtr np2(np);
//	NodePtr np3;
//	np3= np2;
//
//	/*std::auto_ptr<Node> node(new Node);
//	vector<std::auto_ptr<Node>> v;
//	v.push_back(node);*/
//	//STL容器要求存放在容器中的元素能够被拷贝，也就是要求类型是值语义对象
//	//auto_ptr就是值语义 实际是将对象语义转化为值语义
//	
//	//解决方法是采用其他类型的智能指针 比如ptr_vector指针容器（ptr_container的一种特例）
//	system("pause");
//}
////栈展开的过程中指针不会自动释放
////应用RAII技巧 将裸指针转换为智能指针（是一个类）
////将指针转换为对象
////对象的析构函数在生存期结束的时候是确定被调用的


//main.cpp
#include<iostream>
#include<memory>
#include<vector>
#include "ptr_vector.h"

using namespace std;

//#include"DebugNew.h"
//#include "Node.h"

class Test
{
public:
	Test()
	{
		cout << "Test ..." << endl;
	}
	Test(const Test& other)
	{
		cout << "Copy Test ..." << endl;
	}
	~Test()
	{
		cout << "~Test ..." << endl;
	}

};

int main(void)
{
	/*vector<Test*> v;
	Test* t1 = new Test;
	Test* t2 = new Test;
	Test* t3 = new Test;

	v.push_back(t1);
	v.push_back(t2);
	v.push_back(t3);*/

	ptr_vector<Test> v;
	Test* t1 = new Test;
	Test* t2 = new Test;
	Test* t3 = new Test;

	v.push_back(t1);
	v.push_back(t2);
	v.push_back(t3);

	system("pause");
	return 0;
}