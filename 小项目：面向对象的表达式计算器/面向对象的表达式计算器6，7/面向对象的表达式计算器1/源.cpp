

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

