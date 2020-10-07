#include <iostream>
#include <boost/shared_ptr.hpp>
#include <boost/weak_ptr.hpp>
#include<boost/scoped_array.hpp>
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
	void Fun()
	{
		cout << "Fun ..." << endl;
	}

};
void main(void)
{
	boost::weak_ptr<X> p;
	{
		boost::shared_ptr<X> p2(new X);
		cout << p2.use_count() << endl;
		p = p2;//强引用 引用计数并没有增加
		cout << p2.use_count() << endl;

		boost::shared_ptr<X> p3 = p.lock();
		if (!p3)
			cout << "object is destroyed" << endl;
		else
			p3->Fun();
	}
	//因为强引用 引用计数为1 出括号后智能指针被销毁
	boost::shared_ptr<X> p4 = p.lock();
	if (!p4)
		cout << "object is destroyed" << endl;
	else
		p4->Fun();

	boost::scoped_array<X> xx(new X[3]);
	//这里的智能指针会自动构造 和释放3次，说明其源代码中的析构函数delete是数组
	system("pause");
}