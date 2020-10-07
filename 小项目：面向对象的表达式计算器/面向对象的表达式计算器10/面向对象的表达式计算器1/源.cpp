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

using namespace std;
void main()
{
	Calc calc;
	STATUS status;
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
			status = parser.Parse();
			if (status == STATUS_OK)
			{
				std::cout << parser.Calculate() << std::endl;
			}
			else
				std::cout << "Syntax Error." << std::endl;
		
		}
		else
		{

			std::cout << "Expression is empty!" << std::endl;
		}
	} while (status!= STATUS_QUIT);
	system("pause");
}

