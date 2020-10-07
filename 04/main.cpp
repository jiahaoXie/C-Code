//Base * pb = new Child(1)�� ���ȴ���������󣬳�ʼ��Ϊ1��
//func1()�����麯��������pb->func1()ִ�е��ǻ����func1������i = 10��Ȼ�����func2()������
//�����func2���麯����Ҫ����������Ѱ�ң��ҵ���ִ���������е�func2(), ��ʱ��i = 12��
//���ִ��pb->getValue(), ���Ϊ12

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