//Base * pb = new Child(1)， 首先创建子类对象，初始化为1；
//func1()不是虚函数，所以pb->func1()执行的是基类的func1函数，i = 10，然后调用func2()函数；
//这里的func2是虚函数，要往下派生类寻找，找到后执行派生类中的func2(), 此时，i = 12；
//最后执行pb->getValue(), 结果为12

#include<iostream>
using namespace std;

class Base {
public:
	Base(int j) :i(j) {}
	virtual ~Base() {}
	void func1()
	{
		i *= 10;
		func2();
	}
	int getValue()
	{
		return i;
	}
protected:
	virtual void func2()
	{
		i++;
	}
	int i;
};

class Child :public Base {
public:
	Child(int j) :Base(j) {}
	void func1()
	{
		i *= 100;
		func2();
	}
protected:
	void func2()
	{
		i += 2;
	}

};

int main()
{
	Base *pb = new Child(1);
	pb->func1();
	cout << pb->getValue() << endl;
	delete pb;
	system("pause");
	return 0;
}