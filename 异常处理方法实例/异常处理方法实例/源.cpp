#include<iostream>
using namespace std;

void usage()
{
	char* str = "1 �׳������쳣\n2 �׳��������쳣\n3 �׳��ַ������쳣\n4 �׳��Զ����쳣\n";
	cout << str << endl;
}
class MyClass
{
public:
	void output()
	{
		cout << "�Զ����쳣�࣡" << endl;
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
		catch (int n)//�����nΪthrow���ݹ����Ĳ���
		{
			cout << "��׽�������쳣��" << n << endl;

		}
		catch (double n)
		{
			cout << "��׽���������쳣��" << n << endl;

		}
		catch (char* n)
		{
			cout << "��׽���ַ����쳣��" << n << endl;

		}
		catch (MyClass& n)
		{
			cout << "��׽���Զ��������쳣��" ;
			n.output();

		}
		
	}
	system("pause");
}