//#include<iostream>
//using namespace std;
//class Base {
//public:
//	virtual void func(int x)
//	{
//		cout << "In BaseClass: (int) " << x << endl;
//	}
//};
//class SubClass :public Base {
//public:
//	virtual void func(float x)
//	{
//		cout << "In SubClass: (float) " << x << endl;
//	}
//};
//
//void test(Base &b)
//{
//	int i = 1;
//	b.func(i);
//	float f = 2.0;
//	b.func(f);
//}
//void main()
//{
//	Base bc;
//	SubClass sc;
//	cout << "calling  test(bc) " << endl;;
//	test(bc);
//	cout << "calling test(sc) "<<endl;
//	test(sc);
//
//	system("pause");
//}