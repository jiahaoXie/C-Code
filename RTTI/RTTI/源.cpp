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
//	m = &c;//基类的对象指针 可以指向子类对象
//	m->Draw();//访问类成员函数
//	if (dynamic_cast<Circle*>(m))
//	{
//		cout << " m is point to a Circle odject" << endl;
//		Circle *cc = dynamic_cast<Circle*>(m);//安全向下转型
//		cc->Draw();
//	}
//	else if (dynamic_cast<Second*>(m))
//		cout << " m is point to a Second odject" << endl;
//	else
//		cout << " m is point to other odject" << endl;
//
//	cout << typeid(*m).name() << endl;//输出类对象指针m的类型（类型识别）
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
	//this 指针的数据类型为 const CCTest *。
	// const_cast 运算符会将 this 指针的数据类型更改为 CCTest *，以允许修改成员 number。
	// 强制转换仅对其所在的语句中的其余部分持续。
	cout << "\nAfter: " << number;
}

int main() {
	CCTest X;
	X.setNumber(8);
	X.printNumber();
	system("pause");
}