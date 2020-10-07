#include<iostream>
#include<memory>
using namespace std;

class Noncopyable {
protected:
	Noncopyable() {}
	~Noncopyable() {}
private:
	Noncopyable(const Noncopyable&);
	const Noncopyable& operator=(const Noncopyable&);
};

class  Parent :private Noncopyable
{//子类私有继承父类
	//子类中若无构造函数 则会隐式调用父类的构造函数
public:
	Parent():Noncopyable() {}
	Parent(const Parent&):Noncopyable() {}
	~Parent() {}
	
};



void main()
{
	Parent p1;
	Parent p2(p1);
	//这一语句 程序执行失败，因为要调用拷贝构造函数。而在类中并未声明

	
	system("pause");
}
 