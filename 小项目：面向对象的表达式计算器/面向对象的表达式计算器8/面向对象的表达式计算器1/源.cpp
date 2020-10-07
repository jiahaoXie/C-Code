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
	STATUS status_ = STATUS_OK;
	do
	{
		cout << ">";
		string buf;
		getline(cin, buf);
		//cout << buf << endl;
		Scanner scanner(buf);
		Parser parser(scanner,calc);
		parser.Parse();
		cout << parser.Calculate() << endl;
	} while (status_ != STATUS_QUIT);
	system("pause");
}

