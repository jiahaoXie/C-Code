//之前说过auto_ptr<T>不能放置vector中
//但shared_ptr<T>可以放置vector中

#include <boost/shared_ptr.hpp>
#include <iostream>
#include <memory>
#include <vector>

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
void main(void)
{
	//vector<auto_ptr<X> > v;//auto_ptr<t>不能放置vector中
	//auto_ptr<X> p(new X);//auto_ptr<>调用可以实现构造函数和析构函数
	//	//因为auto_ptr<>中常量参数没有经过指针处理 数据无法改变
		//auto_ptr<>重载的等号运算符不是const 与vetor的类型不匹配

	vector<boost::shared_ptr<X> >v;//shared_ptr<t>可以放置vector中
	boost::shared_ptr<X> p(new X);//因为shared_ptr<>重载的等号运算符是const 与vector相匹配
	v.push_back(p);
	cout << p.use_count() << endl;

	system("pause");
}