#include<iostream>
using namespace std;

//class MyClass
//{
//public:
//
//	virtual void Draw() = 0;
//private:
//};
//class Circle :public MyClass
//{
//public:
//	void Draw()
//	{
//		cout << "Circle... " << endl;
//	}
//};
//class Second :public MyClass
//{
//public:
//	void Draw()
//	{
//		cout << "Second.." << endl;
//	}
//};
//
//void main()
//{
//	MyClass* m;
//	Circle c;
//	m = &c;//����Ķ���ָ�� ����ָ���������
//	m->Draw();//�������Ա����
//	if (dynamic_cast<Circle*>(m))
//	{
//		cout << " m is point to a Circle odject" << endl;
//		Circle *cc = dynamic_cast<Circle*>(m);//��ȫ����ת��
//		cc->Draw();
//	}
//	else if (dynamic_cast<Second*>(m))
//		cout << " m is point to a Second odject" << endl;
//	else
//		cout << " m is point to other odject" << endl;
//
//	cout << typeid(*m).name() << endl;//��������ָ��m�����ͣ�����ʶ��
//	cout << typeid(Circle).name() << endl;
//
//
//	system("pause");
//}

class CCTest {
public:
	void setNumber(int);
	void printNumber() const;
private:
	int number;
};

void CCTest::setNumber(int num) { number = num; }

void CCTest::printNumber() const {
	cout << "\nBefore: " << number;
	const_cast< CCTest * >(this)->number--;
	//this ָ�����������Ϊ const CCTest *��
	// const_cast ������Ὣ this ָ����������͸���Ϊ CCTest *���������޸ĳ�Ա number��
	// ǿ��ת�����������ڵ�����е����ಿ�ֳ�����
	cout << "\nAfter: " << number;
}

int main() {
	CCTest X;
	X.setNumber(8);
	X.printNumber();
	system("pause");
}