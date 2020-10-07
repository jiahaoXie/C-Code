//Па·ґКэ
#include<iostream>

using namespace std;

void main()
{
	int m, n,s=0;
	cin >> n;
	m = n;
	while (n)
	{
		s = s * 10 + n % 10;
		n = n / 10;
	}
	m += s;
	cout << m;
	system("pause");
}