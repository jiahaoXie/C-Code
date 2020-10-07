//C++primer源码

#include<iostream>
#include<string>
using namespace std;

int main()
{
	string one("ABCDEFG");
	cout << "one "<<one << endl;

	string two(20, 's');
	cout << "two "<<two << endl;

	string three(one);
	cout << "three "<<three << endl;

	one += "abcd";	//重载运算符 +=(自带)
	cout << "one "<<one << endl;

	two = "Sorry! That was ";
	three[0] = 'p';

	string four;
	four = two + three;		//重载运算符 （+ =）
	cout <<"four "<< four << endl;

	char alls[] = "All's well that ends well";
	string five(alls, 20);
	cout <<"five "<< five << endl;
	
	string six(alls + 6, alls + 10);
	cout << "six "<<six << endl;

	string seven(&five[6], &five[10]);
	cout <<"seven "<< seven << "...." << endl;

	string eight(four,7,16);
	cout << "eight:" << eight << " in motion!" << endl;

	system("pause");
	return 0;
}