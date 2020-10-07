////c语言中 利用setjump longjump进行长跳转（全局跳转）
////错误的抛出点与错误处理处距离可以相隔比较远的地方
//
//#include <stdio.h>
//#include <setjmp.h>
//#include<iostream>
//jmp_buf buf;//保存一个栈环境
//
//double Divide(double a, double b)
//{
//	if (b == 0.0)
//	{
//		longjmp(buf, 1); //throw longjmp进行长跳转到 ret = setjmp(buf)，并把返回值1赋给ret
//	}
//	else
//		return  a / b;
//}
//
//void main()
//{
//	int ret;
//	ret = setjmp(buf);//保存程序的运行环境到buf缓冲区中，有异常时，调转到此返回值为longjmp(buf,1)中的1
//	if (ret == 0)    //try
//	{
//		printf("divisiong....");
//		printf("a/b = %f\n", Divide(5.0, 0.0));
//	}
//	else if (ret == 1) //catch 
//	{
//		printf("divisiong by zero\n");
//	}
//	
//	system("pause");
//	
//}


//C++异常处理 利用try..catch..finally
#include <iostream>
using namespace std;

double Divide(double a, double b)
{
	if (b == 0.0)
	{
		throw 1;
	}
	else
		return  a / b;
}

void main(void)
{
	try
	{
		cout << "division ..." << endl;
		
		cout << Divide(5.0, 1.0) << endl;
		cout << Divide(5.0, 0.0) << endl;
		cout << Divide(5.0, 2.0) << endl;
				//try...catch..语句中 只要捕获到一条错误语句 函数就会执行停止后面的语句执行，转去异常处理
	}
	catch (int)//捕获整形异常
	{
		cout << "divisiong by zero\n" << endl;
	}
	system("pause");
}