//#include <iostream>
//#include <string>
//using namespace std;
//
//class MyException
//{
//public:
//	MyException(const char* message)
//		:message_(message)
//	{
//		cout << "MyException ..." << endl;
//	}
//	MyException(const MyException& other) : message_(other.message_)
//	{
//		cout << "Copy MyException ..." << endl;
//	}
//	~MyException()
//	{
//		cout << "~MyException" << endl;
//	}
//	const char* what() const
//	{
//		return message_.c_str();//返回异常信息
//	}
//private:
//	string message_;
//};
//double Divide(double a, double b)
//{
//	if (b == 0.0)
//	{
//		//MyException e("division by zero");//异常发生之前创建的局部对象被销毁，这一过程称为栈展开
//		//throw e;//throw抛出一个类对象会调用拷贝构造函数
//		throw MyException("division by zero");//不再调用拷贝构造函数，只调用构造函数
//	}
//	else
//		return a / b;
//}
//int main(void)
//{
//	try
//	{
//		cout << Divide(5.0, 0.0) << endl;
//	}
//	catch (MyException& e)
//	{
//		cout << e.what() << endl;
//	}
//	/*catch (...)//...可捕获任何异常
//	{
//	cout <<"catch a exception ..."<< endl;
//	}*/
//	system("pause");
//}

////异常传播 try块可以嵌套
//#include<iostream>
//#include<string>
//using namespace std;
//
//class MyException
//{
//public:
//	MyException(const char* message)
//		:message_(message)
//	{
//		cout << "MyException ..." << endl;
//	}
//	MyException(const MyException& other) : message_(other.message_)
//	{
//		cout << "Copy MyException ..." << endl;
//	}
//	~MyException()
//	{
//		cout << "~MyException" << endl;
//	}
//	const char* what() const
//	{
//		return message_.c_str();
//	}
//private:
//	string message_;
//};
//
//int main(void)
//{
//
//	try
//	{
//		try
//		{
//			throw MyException("test exception");//抛出异常
//		}
//		catch (int)
//		{
//			cout << "catch a int exception" << endl;
//		}
//		catch (MyException& e)//如果内层捕获，不再传播到外面
//		{
//			cout << "Inner ..." << endl;
//			cout << e.what() << endl;
//			throw e;//重新抛出异常，可传到外部
//		}
//	}
//	catch (MyException& e)
//	{
//		cout << "Outer ..." << endl;
//		cout << e.what() << endl;
//	}
//	system("pause");
//}

//栈展开
#include<iostream>
#include<string>
using namespace std;

class MyException
{
public:
	MyException(const char* message)
		:message_(message)
	{
		cout << "MyException ..." << endl;
	}
	MyException(const MyException& other) : message_(other.message_)
	{
		cout << "Copy MyException ..." << endl;
	}
	~MyException()
	{
		cout << "~MyException" << endl;
	}
	const char* what() const
	{
		return message_.c_str();
	}
private:
	string message_;
};

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
class Test3
{
public:
	Test3()
	{
		cout << "Test3 ..." << endl;
	}
	Test3(const Test3& other)
	{
		cout << "Copy Test3 ..." << endl;
	}
	~Test3()
	{
		cout << "~Test3 ..." << endl;
		throw 4;//不能在析构函数中抛出异常
	}
};

class Obj
{
public:
	Obj()
	{
		cout << "Obj ..." << endl;
	}
	Obj(const Obj& other)
	{
		cout << "Copy Obj ..." << endl;
	}
	~Obj()
	{
		cout << "~Obj ..." << endl;
	}
};
class Test2
{
public:
	Test2()
	{
		obj_ = new Obj;
		cout << "Test2 ..." << endl;
		throw MyException("test exception");//可以在构造函数中抛出异常，抛出异常后不会调用析构函数
	}
	Test2(const Test2& other)
	{
		cout << "Copy Test2 ..." << endl;
	}
	~Test2()
	{
		delete obj_;
		cout << "~Test2 ..." << endl;
	}
private:
	Obj* obj_;
};


int main(void)
{
	try
	{
		/*Test t;
		throw MyException("test exception");*/

		//Test2 t2;
		Test3 t3;
		throw MyException("Test exception3");
	}
	catch (MyException& e)
	{
		cout << e.what() << endl;
	}
	catch (int)
	{
		cout << "catch a int esception" << endl;
	}
}
