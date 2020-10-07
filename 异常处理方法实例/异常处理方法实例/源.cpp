#include<iostream>
using namespace std;

void usage()
{
	char* str = "1 抛出整形异常\n2 抛出浮点型异常\n3 抛出字符串形异常\n4 抛出自定义异常\n";
	cout << str << endl;
}
class MyClass
{
public:
	void output()
	{
		cout << "自定义异常类！" << endl;
	}
};
void fun(bool flag)
{
	if (flag)
		throw MyClass();
}
void main()
{
	usage();
	bool flag = true;
	while (flag)
	{
		int n;
		cout << "please input a number:";
		cin >> n;
		try
		{
			if(0 == n) flag = false;
			else if (1 == n) throw 11;
			else if (2 == n) throw 2.0;
			else if (3 == n) throw "abc";
			else if (4 == n) fun(flag);
		}
		catch (int n)//这里的n为throw传递过来的参数
		{
			cout << "捕捉到整形异常：" << n << endl;

		}
		catch (double n)
		{
			cout << "捕捉到浮点形异常：" << n << endl;

		}
		catch (char* n)
		{
			cout << "捕捉到字符串异常：" << n << endl;

		}
		catch (MyClass& n)
		{
			cout << "捕捉到自定义类类异常：" ;
			n.output();

		}
		
	}
	system("pause");
}