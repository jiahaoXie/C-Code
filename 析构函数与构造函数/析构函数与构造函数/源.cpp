#include<iostream>
using namespace std;

class Q {
	int x, y;
public:
	Q(int a = 0, int b = 0)
	{
		cout << "调用了构造函数" << endl;
		x = a; y = b;
	}
	void P()
	{
		cout << x << "\t" << y << endl;
	}
	~Q()
	{
		cout << "调用了析构函数" << endl;
	}
};

void main()
{
	Q q(50, 100);
	q.P();
	cout << "退出主函数！" << endl;
	system("pause");
}