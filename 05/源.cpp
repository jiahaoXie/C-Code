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
//	A a;		//Ĭ�Ϲ��캯�� ���Ϊ1 
//	A b = a;	//������õ��ǿ������캯�� ���Ϊ2
//
//	A c;	//Ĭ�Ϲ��캯�� ���Ϊ1
//	c = a;	//������õ�����������غ��� ���Ϊ3
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