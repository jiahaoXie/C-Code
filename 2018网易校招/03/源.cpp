//×Ö·û´® ËéÆ¬
#include<iostream>
#include<string>
#include<stdio.h>
using namespace std;

int main()
{
	string s;
	cin >> s;
	char c = s[0];
	int n = 1;
	float ave;

	for (int i = 1; i < s.size(); i++)
	{
		if (c != s[i])
		{
			c = s[i];
			n++;
		}
	}
	ave = (float)s.size() / n;
	printf("%.2f", ave);


	return 0;

}