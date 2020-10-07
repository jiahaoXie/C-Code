//项目做到这里基本实现了算术表达式解析器！但是它的一个缺陷在于它的语法是右结合的。
//这意味着8-2+1被解析为8-(2+1)

#include <iostream>
#include<string>
#include"Scanner.h"
#include"Parser.h"
using namespace std;
void main()
{
	STATUS status_ = STATUS_OK;
	do
	{
		cout << ">";
		string buf;
		getline(cin, buf);
		//cout << buf << endl;
		Scanner scanner(buf);
		Parser parser(scanner);
		parser.Parse();
		cout << parser.Calculate() << endl;
	} while (status_ != STATUS_QUIT);
	system("pause");
}

