#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;

void print_element(int n)
{
	cout << n << "	";
}

bool my_greater(int a, int b)
{
	return a > b;
}

int multi(int a, int b)
{
	return a*b;
}
void main()
{
	int a[] = { 1,2,3,4,5 };
	vector<int> v(a, a + 5);
	for_each(v.begin(), v.end(), print_element);
	cout << endl;

	//accumulate（）实现累加
	cout<<accumulate(v.begin(),v.end(),0)<<endl;

	//实现累乘
	cout << accumulate(v.begin(), v.end(), 1, multi) << endl;

	system("pause");
}