#include<iostream>
using namespace std;

//用函数模板 解决重载函数问题
template<typename T>
T add(const T x, const T y)
{
	return x + y;
}

void main()
{
	int i1 = 10, i2 = 9;
	float f1 = 12.5, f2 = 13.7;
	
	cout << add(i1, i2) << endl;
	cout << add(f1, f2) << endl;
	
	system("pause");
}




