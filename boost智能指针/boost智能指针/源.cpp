//智能指针本质思想：
//将堆对象的生存期用栈对象来管理，当new一个堆对象的时候，立刻用智能指针来接管，
	//具体做法是在构造函数进行初始化（用一个指针指向堆对象），在析构函数中调用delete来释放堆对象。
//由于智能指针本身是一个栈对象，它的作用域结束的时候，自动调用析构函数，
	//从而调用了delete释放了堆对象。


//scoped_ptr<X>所有权不能转移，不能交换
#include<boost/scoped_ptr.hpp>
#include <iostream>

using namespace std;

class X
{
public:
	X()
	{
		cout << "X ..." << endl;
	}
	~X()
	{
		cout << "~X ..." << endl;
	}

};
int main(void)
{
	cout << "Entering main ..." << endl;
	{
		boost::scoped_ptr<X> p(new X);
		//scoped_ptr<X>可实例化一个对象，但不能调用拷贝构造函数
	}
	cout << "Exiting main ..." << endl;
	system("pause");

	return 0;
}