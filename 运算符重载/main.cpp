//前面这个程序为运算符重载为类成员函数；后面为运算符重载为友元函数
//一。
//#include<iostream>
//using namespace std;
//
//class Complex {
//public:
//	Complex(double r = 0.0, double i = 0.0)
//	{
//		rear = r;
//		image = i;
//	}
//	void GetRear()
//	{
//		cin >> rear;
//	}
//	void GetImage()
//	{
//		cin >> image;
//	}
//	//+ -运算符重载为类成员函数
//	Complex operator+(Complex c2);
//	Complex operator-(Complex c2);
//	void display()
//	{
//		cout << "(" << rear << "," << image<<")" << endl;
//	}
//private:
//	double rear, image;
//
//};
//
// Complex Complex::operator+(Complex c2)
//{
//	return Complex(rear + c2.rear, image + c2.image);
//}
//
// Complex  Complex::operator-(Complex c2)
//{
//	return Complex(rear -c2.rear, image - c2.image);
//}
//
//void main()
//{
//	/*Complex c1(5, 4), c2(2, 10),c3;
//	cout << "c1 = ";
//	c1.display();
//	cout << "c2 = ";
//	c2.display();*/
//
//	//还可以进行控制台动态输入对象c1 c2的值！！
//	Complex c1, c2, c3;
//	cout << "pleae input c1 values: ";
//	c1.GetRear();
//	c1.GetImage();
//	cout << "pleae input c2 values: ";
//	c2.GetRear();
//	c2.GetImage();
//
//	cout << "c1+c2 =";
//	c3 = c1 + c2;
//	c3.display();
//	
//	cout << "c1-c2 =";
//	c3 = c1 -c2;
//	c3.display();
//
//	system("pause");
//}

//二。
#include<iostream>
using namespace std;

class Complex {
public:
	Complex(double r = 0.0, double i = 0.0)
	{
		rear = r;
		image = i;
	}
	void GetRear()
	{
		cin >> rear;
	}
	void GetImage()
	{
		cin >> image;
	}
	
	friend Complex operator+(Complex c1,Complex c2);
	friend Complex operator-(Complex c1,Complex c2);
	void display()
	{
		cout << "(" << rear << "," << image<<")" << endl;
	}
private:
	double rear, image;
	
};

Complex operator+(Complex c1,Complex c2)
{
	return Complex(c1.rear+c2.rear,c1.image+c2.image);
}
Complex operator-(Complex c1,Complex c2)
{
	return Complex(c1.rear - c2.rear, c1.image - c2.image);
}

void main()
{
	/*Complex c1(5, 4), c2(2, 10),c3;
	cout << "c1 = ";
	c1.display();
	cout << "c2 = ";
	c2.display();*/

	//还可以进行控制台动态输入对象c1 c2的值！！
	Complex c1, c2, c3;
	cout << "pleae input c1 values: ";
	c1.GetRear();
	c1.GetImage();
	cout << "pleae input c2 values: ";
	c2.GetRear();
	c2.GetImage();

	cout << "c1+c2 =";
	c3 = c1 + c2;
	c3.display();
	
	cout << "c1-c2 =";
	c3 = c1 -c2;
	c3.display();

	system("pause");
}