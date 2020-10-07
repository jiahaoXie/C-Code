//main.cpp
#include<iostream>
using namespace std;

#include"DebugNew.h"

int main(void)
{
	int* p = new int;//堆栈开辟四个字节的空间
	//delete p;

	int* p2 = new int[5];
	//delete[] p2;
	system("pause");
	return 0;
}