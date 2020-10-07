//// basic_string_substr.cpp
//// compile with: /EHsc
//#include <string>
//#include <iostream>
//
//int main()
//{
//	using namespace std;
//
//	string  str1("Heterological paradoxes are persistent.");
//	cout << "The original string str1 is: \n " << str1
//		<< endl;
//
//	basic_string <char> str2 = str1.substr(6, 7);
//	cout << "The substring str1 copied is: " << str2
//		<< endl << endl;
//
//	basic_string <char> str3 = str1.substr();
//	cout << "The default substring str3 is: \n " << str3
//		<< "\n which is the entire original string." << endl;
//	system("pause");
//}

#include<stdio.h>
void main()
{
	int i, sum = 0;
	for (i = 1; i <= 100; i++)
		sum += i;
	printf("sum=%d\n", sum);
	while (1) {};
}