//lower_bound	搜索第一个“大于等于给定值”的元素
//				如果要插入给定值，保持区间有序性，返回第一个可插入的位置
//upper_bound	搜索第一个“大于给定值”的元素
//				如果要插入给定值，保持区间有序性，返回第一个可插入的位置


#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void print_element(int n)
{
	cout << n << "	";
}

bool my_greater(int a, int b)
{
	return a > b;
}
void main()
{
	int a[] = { 1,10,10,14,15,16 };
	vector<int> v(a, a + 6);
	for_each(v.begin(), v.end(), print_element);
	cout << endl;

	vector<int>::iterator it;
	it = lower_bound(v.begin(),v.end(),10);
	if (it != v.end())
		cout << "position:" << it - v.begin() << " value:" << *it << endl;
	
	it = upper_bound(v.begin(), v.end(), 10);
	if (it != v.end())
		cout << "position:" << it - v.begin() << " value:" << *it << endl;
	system("pause");
}