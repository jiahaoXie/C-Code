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
//		return message_.c_str();//�����쳣��Ϣ
//	}
//private:
//	string message_;
//};
//double Divide(double a, double b)
//{
//	if (b == 0.0)
//	{
//		//MyException e("division by zero");//�쳣����֮ǰ�����ľֲ��������٣���һ���̳�Ϊջչ��
//		//throw e;//throw�׳�һ����������ÿ������캯��
//		throw MyException("division by zero");//���ٵ��ÿ������캯����ֻ���ù��캯��
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
//	/*catch (...)//...�ɲ����κ��쳣
//	{
//	cout <<"catch a exception ..."<< endl;
//	}*/
//	system("pause");
//}

////�쳣���� try�����Ƕ��
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
//			throw MyException("test exception");//�׳��쳣
//		}
//		catch (int)
//		{
//			cout << "catch a int exception" << endl;
//		}
//		catch (MyException& e)//����ڲ㲶�񣬲��ٴ���������
//		{
//			cout << "Inner ..." << endl;
//			cout << e.what() << endl;
//			throw e;//�����׳��쳣���ɴ����ⲿ
//		}
//	}
//	catch (MyException& e)
//	{
//		cout << "Outer ..." << endl;
//		cout << e.what() << endl;
//	}
//	system("pause");
//}

//ջչ��
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
		throw 4;//�����������������׳��쳣
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
		throw MyException("test exception");//�����ڹ��캯�����׳��쳣���׳��쳣�󲻻������������
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
