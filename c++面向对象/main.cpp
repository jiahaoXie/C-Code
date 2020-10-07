//#include<iostream>
//using namespace std;
//
//class A {
//public:
//	long a;
//};
//class B : public A {
//public:
//	long b;
//};
//
////两个seta函数 因为类B 继承 类A，所以两个步长不一样
////void seta(A* data, int idx) {
////	data[idx].a = 2;
////}
//void seta(B* data, int idx) {
//	data[idx].a = 2;
//}
//
//int main(int argc, char *argv[]) {
//	B data[4];
//	for (int i = 0; i<4; ++i) {
//		data[i].a = 1;
//		data[i].b = 1;
//		seta(data, i);
//	}
//	for (int i = 0; i<4; ++i) {
//		std::cout << data[i].a << data[i].b;
//	}
//	system("pause");
//	return 0;
//}


#include<iostream>
using namespace std;

class R {
public:
	R(int r1, int r2)
	{
		R1 = r1;
		R2 = r2;
	}
	void print();
	void print() const;
private:
	int R1, R2;
};

void R::print()
{
	cout << "output print()" << endl;
	cout << R1 << ' ' << R2 << endl;
}
void R::print() const
{
	cout << "output print() const" << endl;
	cout << R1<<' '<<R2 << endl;
}

void main()
{
	R a(4,5);
	a.print();
	const R b(10, 18);

	//R const b(10, 18);
	b.print();

	system("pause");
}

//
//#include<iostream>
//using namespace std;
//class B1 {
//public:
//	B1(int i)
//	{
//		cout << "COnstrucing B1" << i << endl;
//	}
//	~B1()
//	{
//		cout << "Destructing B1" << endl;
//	}
//};
//
//class B2 {
//public:
//	B2(int j)
//	{
//		cout << "COnstrucing B2" << j << endl;
//	}
//	~B2()
//	{
//		cout << "destructing B2" << endl;
//	}
//};
//
//class B3 {
//public:
//	B3()
//	{
//		cout << "COnstrucing B3" << "*" << endl;
//	}
//	~B3()
//	{
//		cout << "destructing B3" << endl;
//	}
//};
//
//class C :public B2, public B1, public B3 {
//public:
//	C(int a, int b, int c, int d)
//		:B1(a), memberB2(d), memberB1(c), B2(d) {}
//private:
//	B1 memberB1;
//	B2 memberB2;
//	B3 memberB3;
//
//};
//
//void main()
//{
//	C c(1,2,3,4);
//	system("pause");
//}