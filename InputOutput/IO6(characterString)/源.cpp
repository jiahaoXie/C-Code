//字符串流
#include<iostream>
#include<sstream>
#include<string>
using namespace std;

string doubleToString(double value)
{
	ostringstream oss;
	oss << value;
	//利用ostringstream字符串输出流对象oss 将浮点型析构数据转换为字符型数据

	return oss.str();
}

double stringToDouble(const string& str)
{
	istringstream iss(str);
	double value;
	iss >> value;
	//利用istringstream字符串输入流对象iss 将浮点型转换为浮点型数据
	return value;
}
void main()
{	
	//字符串输入流对象使用
	//string line;
	//string word;
	//while (getline(cin, line))
	//{//首先从标准输入中获取一行数据给line

	//	istringstream iss(line);
	//	//利用字符串输入流对象iss 得到line 中的数据
	//	while (iss>>word)
	//	{//将iss中的数据提取到word当中
	//		cout << word << "#";
	//	}
	//	cout << endl;
	//}
	////这里在控制台 windows系统以ctr+z结束

	double value = 66.6666;
	string  str = doubleToString(value);
	cout << str << endl;

	str = "2333.3333";
	value = stringToDouble(str);
	cout << value << endl;


	system("pause");
}