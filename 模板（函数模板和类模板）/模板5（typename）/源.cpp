#include <iostream>
using namespace std;

template <typename T>
class MyClass
{
private:
	typename T::SubType * ptr_;
	//关键字typename 这里作用是代表SubType是一个类型
public:


};
class Test {
public:
	typedef int SubType;
};
int main(void)
{
	MyClass<Test> mc;
	//这里类模板MyClass必须指定类型

	system("pause");
	return 0;
}