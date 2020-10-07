//让表达式计算器支持变量赋值

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

