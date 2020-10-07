//shared_ptr<>内部需要一个引用计数器来判断此指针需不需要被释放

#include <boost/shared_ptr.hpp>
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
void  main(void)
{
	cout << "Entering main ..." << endl;
	boost::shared_ptr<X> p1(new X);
	cout << p1.use_count() << endl;
	boost::shared_ptr<X> p2 = p1;
	//shared_ptr<> 能够进行拷贝
	cout << p2.use_count() << endl;
	p1.reset();
	cout << p2.use_count() << endl;
	p2.reset();
	cout << "Exiting main ..." << endl;

	system("pause");
}