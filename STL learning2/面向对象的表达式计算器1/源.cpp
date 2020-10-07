///*********************************************************************
///本次面向对象表达式计算器完整小项目的主要功能是实现 
//1.能够计算普通表达式
//2.支持变量
//3.支持函数
//4.支持保存变量和函数
//**********************************************************************/




////表达式计算器11新增功能：  增加异常处理功能


//让表达式计算器支持变量赋值
//FunctionTable实现
//让表达式计算器支持函数运算
//对于一个好的科学计算器，内置函数是必需的。计算器必须能计算平方根、对数、三角函数等等。
//因而我们要让解析器识别这些函数, 并调用适当的数学库函数。
//FunctionTable实现

#include <iostream>
#include<string>
#include"Scanner.h"
#include"Parser.h"
#include"Calc.h"
#include "Exception.h"
#include"CommandParser.h"
using namespace std;
void main()
{
	Calc calc;
	STATUS status= STATUS_OK;
	do
	{
		cout << ">";
		//string buf;
		//getline(cin, buf);//1、从控制台上获取一行数据给buf
		//		//cout << buf << endl;
		//Scanner scanner(buf);//2、将获得的这串数据传递到scanner类中去
		Scanner scanner(std::cin);//这条语句是将上述1 2两个操作封装到scanner中 相应的Scanner类中的构造函数也要发生改变
		//扫描器扫描字符
		if (!scanner.IsEmpty())
		{
			if (scanner.IsCommand())
			{//如果当前扫描到感叹号，则表示为命令解析
				CommandParser parser(scanner,calc);
				status = parser.Execute();//执行命令解析

			}
			else
			{//否则为表达式
				Parser parser(scanner, calc);
				try
				{
					status = parser.Parse();//解析可会出现异常
											//因为这里status赋值 
											//但是后面若程序运行出现异常（继而进行异常处理）可能会出现最后do..while()循环出错。
											//所以status需要在mian函数中赋初值 STATUS status = STATUS_OK;

					if (status == STATUS_OK)
					{
						std::cout << parser.Calculate() << std::endl;
					}

				}
				catch (SyntaxError& se)//捕获语法异常
				{
					status = STATUS_QUIT;

					cout << se.what() << endl;
				}
				catch (Exception& e)//捕获其他类型的异常 用基类的成员函数来捕获
				{
					status = STATUS_QUIT;

					cout << e.what() << endl;
				}
				catch (std::bad_alloc& c)
				{//内存分配失败
					status = STATUS_QUIT;
					cout << "Internal error" << endl;
				}
				catch (...)
				{
					status = STATUS_QUIT;

					cout << "Internl Error!" << endl;
				}
			}
		}
			
		else
		{
			status = STATUS_QUIT;
			std::cout << "Expression is empty!" << std::endl;
		}
	} while (status!= STATUS_QUIT);
	system("pause");
}

