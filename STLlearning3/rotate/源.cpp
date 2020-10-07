#include<iostream>
#include<vector>
#include<algorithm>
#include<list>
using namespace std;

void print_element(int n)
{
	cout << n << "	";
}

bool my_greater(int a,int b)
{
	return a > b;
}
void main()
{
	int a[] = { 1,2,3,4,5,6 };
	vector<int> v(a, a + 6);
	for_each(v.begin(), v.end(), print_element);
	cout << endl;

	//rotate()方法对元素进行翻转
	rotate(v.begin(),v.begin()+2,v.end()-1);
	for_each(v.begin(), v.end(), print_element);
	cout << endl;

	//sort()默认情况为从到大进行排序
	sort(v.begin(),v.end());
	for_each(v.begin(), v.end(), print_element);
	cout << endl;

	//利用加入第三个参数（自定义函数my_greater）
	sort(v.begin(),v.end(),my_greater);
	for_each(v.begin(), v.end(), print_element);
	cout << endl;

	system("pause");
}