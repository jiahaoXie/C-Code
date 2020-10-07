//用stl解决八皇后问题

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void print_element(int n)
{
	cout << n << " ";
}
void main()
{
	int a[] = {1,2,3,4};
	vector<int> v(a,a+4);
	for_each(v.begin(),v.end(),print_element);
	cout << endl;
	//next_permutation()方法 可得到随机序列
	cout << "由next_permutation()方法得到：\n";
	while (next_permutation(v.begin(), v.end()))
	{
		for_each(v.begin(), v.end(), print_element);
		cout << endl;
	}
	system("pause");
}
