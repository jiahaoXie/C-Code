#include<iostream>
#include<algorithm>
#include<functional>
#include<vector>
#include<string>
using namespace std;

bool check(int n)
{
	return n < 3;
}
void main()
{
	//char* a[] = {"","bbbbb","cccc"};
	//vector<char*> v(a,a+2);
	//vector<char*>::iterator it;
	//it = find_if(v.begin(),v.end(),bind2nd(ptr_fun(strcmp),""));
	////蒋字符串比较函数strcmp 用于函数适配器
	//if (it != v.end())
	//	cout << *it << endl;

	int a[] = {1,2,3,4,5};
	vector<int> v(a,a+5);
	vector<int>::iterator it;
	it = find_if(v.begin(),v.end(),not1(ptr_fun(check)));
	if (it != v.end())
		cout << *it << endl;

	system("pause");
}