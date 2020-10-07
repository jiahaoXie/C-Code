#include<iostream>
using namespace std;
void main()
{
	//int n1 = 100, n2 = 150;
	//cout << "n1=" << n1 << "  n2=" << n2 << endl;

	//cout.put('h');
	//cout.put('n');
	//cout.put('\t').put('H').put('  ').put('N');
	//cout << endl;

	//char buf[] = "china!!!!!!!!";
	//cout.write(buf,5);//write(a,b)输出a的b字节位
	//cout << endl;

	//int n;
	//char ch;
	//cin >> n >> ch;
	//cout << "n=" << n << "\t" << "ch=" << ch << endl;

	//char buf[10] = {0};
	//////cin >> buf;
	////	//>>输入时遇到空格符结束
	//cin.getline(buf, 10);
	//	//getline为输入一整行字符（包括空格字符）
	//cout <<buf << endl;

	/*char buf[10] = {0};
	cin.read(buf, 5);
	cout<<buf<<endl;*/

	char c[10], c2, c3;

	c2 = cin.get();
	c3 = cin.get();
	cin.putback(c2);
	//将指定字符到流中。
	cin.getline(&c[0], 9);
	cout << c << endl;

	system("pause");

}