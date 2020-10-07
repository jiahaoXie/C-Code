//#include<stdio.h>
//#include<malloc.h>
//#include<cstring>
//void GetMemory(char *p)
//{
//	p = (char *)malloc(100);
//}
//
//int main()
//{
//	char* str = NULL;
//	GetMemory(str);
//	strcpy(str, "Thunder");
//	strcat(str, "123456");
//	printf("%s\n", str);
//	while (1)
//	{
//
//	}
//	return 0;
//}

//#include<iostream>
//using namespace std;
//class A {
//public:
//	A()
//	{
//		printf("1");
//	}
//	A(A& a)
//	{
//		printf("2");
//	}
//	A &operator=(const A &a)
//	{
//		printf("3");
//		return *this;
//	}
//};

//int main()
//{
//	A a;		//默认构造函数 输出为1 
//	A b = a;	//这里调用的是拷贝构造函数 输出为2
//
//	A c;	//默认构造函数 输出为1
//	c = a;	//这里调用的是运算符重载函数 输出为3
//
//	printf("\n");
//
//	system("pause");
//	return 0;
//}

#include<iostream>
//#include<sstream>
#include<string>
using namespace std;
int main()
{
	
	string line;
	getline(cin,line,'#');
	cout << "line:" << line << endl;
	cout << " Hello World...." << endl;
	system("pause");
	return 0;
}