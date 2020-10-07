#include<iostream>
#include<vector>
#include<list>
#include<algorithm>
using namespace std;

void print_element(int n)
{
	cout << n << ",";
}

bool morethan_3(int n)
{
	return n > 3;
}
int add(int& n)
{
	return n += 3;
}
int func(int n)
{
	return 2 * n;
}

int func2(int a, int b)
{
	return a + b;
}
void main()
{
	int a[] = { 2,3,4,1,5 };
	vector<int> v(a, a + 6);
	//用数组来初始化变量v 将数组a中的数据加载到向量v中 
	//注意,vector中为[)		即包括first,不包括end
	list<int> l(6);//列表初始化为0
	list<int> l2(3);

	transform(v.begin(),v.end(),l.begin(),func);
	for_each(l.begin(), l.end(), print_element);
	cout << endl;

	transform(v.begin(),v.begin()+2,v.begin()+3,l2.begin(),func2);
	for_each(l2.begin(), l2.end(), print_element);
	cout << endl;
	

	system("pause");
}