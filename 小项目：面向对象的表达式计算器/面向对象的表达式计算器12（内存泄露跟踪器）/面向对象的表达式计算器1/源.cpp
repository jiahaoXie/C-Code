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
using namespace std;
void main()
{
	Calc calc;
	STATUS status= STATUS_OK;
	do
	{
		cout << ">";
		string buf;
		getline(cin, buf);
		//cout << buf << endl;
		Scanner scanner(buf);
		if (!scanner.IsEmpty())
		{
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
			catch (...)
			{
				status = STATUS_QUIT;

				cout << "Internl Error!" << endl;
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

