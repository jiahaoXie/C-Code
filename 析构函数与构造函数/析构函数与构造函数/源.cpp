#include<iostream>
using namespace std;

class Q {
	int x, y;
public:
	Q(int a = 0, int b = 0)
	{
		cout << "�����˹��캯��" << endl;
		x = a; y = b;
	}
	void P()
	{
		cout << x << "\t" << y << endl;
	}
	~Q()
	{
		cout << "��������������" << endl;
	}
};

void main()
{
	Q q(50, 100);
	q.P();
	cout << "�˳���������" << endl;
	system("pause");
}