#include<iostream>
#include<vector>
#include<list>
#include<algorithm>
using namespace std;

void print_element(int n)
{
	cout << n << ",";
}
bool func(int a)
{
	return a < 10;
}

void main()
{
	int a[] = { 2,3,4,1,5,4 };
	vector<int> v(a, a + 6);
	//用数组来初始化变量v 将数组a中的数据加载到向量v中 
	//注意,vector中为[)		即包括first,不包括end
	list<int> l(6);

	replace(v.begin(),v.end(),4,14);
	for_each(v.begin(),v.end(),print_element);
	cout << endl;

	//replace_copy 在拷贝的过程当中发生替换（原区间不变，目标区间数值发生改变）
	replace_copy(v.begin(),v.end(),l.begin(),14,4);
	//输出原区间
	cout << "the original:";
	for_each(v.begin(), v.end(), print_element);
	cout << endl;
	//输出拷贝得到的目标区间
	cout << "the      new:";
	for_each(l.begin(), l.end(), print_element);
	cout << endl;

	//replace_copy_if（）配合自定义的func()函数 将小于10的元素赋值为100
	replace_copy_if(v.begin(),v.end(),l.begin(),func,100);
	for_each(l.begin(), l.end(), print_element);
	cout << endl;

	system("pause");
}