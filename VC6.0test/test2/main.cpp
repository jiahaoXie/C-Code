/*
#include<iostream>
using namespace std;
class B1 {
public:
	B1(int i)
	{
		cout << "COnstrucing B1" << i << endl;
	}
	~B1()
	{
		cout << "Destructing B1" << endl;
	}
};

class B2 {
public:
	B2(int j)
	{
		cout << "COnstrucing B2" << j << endl;
	}
	~B2()
	{
		cout << "destructing B2" << endl;
	}
};

class B3 {
public:
	B3()
	{
		cout << "COnstrucing B3" << "*" << endl;
	}
	~B3()
	{
		cout << "destructing B3" << endl;
	}
};

class C :public B2, public B1, public B3 {
public:
	C(int a, int b, int c, int d)
		:B1(a), memberB2(d), memberB1(c), B2(d) {}
private:
	B1 memberB1;
	B2 memberB2;
	B3 memberB3;

};

void main()
{
	C c(1,2,3,4);
	system("pause");
}
*/
/*
#include<stdio.h>
#include<malloc.h>
#include<cstring>

void GetMemory(char* &p)
//这里函数名如果写为void GetMemory(char* p) 程序会崩溃
{
	p = (char *)malloc(100);
}

int main()
{
	char* str = NULL;
	GetMemory(str);
	//char* str=(char*)malloc(100);
	strcpy(str, "Thunder");
	strcat(str+7, "123456");
	printf("%s\n", str);
	//free str;
	return 0;
}
*/

#include<s>