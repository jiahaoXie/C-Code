#include<iostream>
#include<string>
using namespace std;

class FucObj 
{
public:
	void operator()()
	{//operator()重载（）运算符 
		cout << "hello " << endl;
	}
	void operator()(string  n)
	{//operator()重载（）运算符 
		cout << "hello "<<n << endl;
	}
};

int main()
{
	FucObj fo;
	fo();	//类对象可直接作为函数来使用（称之为函数对象）
	fo("China");

	FucObj()();
	FucObj()("China");

	system("pause");
}
