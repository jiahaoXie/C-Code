#include<iostream>
#include<string>
using namespace std;

class FucObj 
{
public:
	void operator()()
	{//operator()���أ�������� 
		cout << "hello " << endl;
	}
	void operator()(string  n)
	{//operator()���أ�������� 
		cout << "hello "<<n << endl;
	}
};

int main()
{
	FucObj fo;
	fo();	//������ֱ����Ϊ������ʹ�ã���֮Ϊ��������
	fo("China");

	FucObj()();
	FucObj()("China");

	system("pause");
}
