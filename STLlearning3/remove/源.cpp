#include<iostream>
#include<vector>
#include<algorithm>
#include<list>
using namespace std;

void print_element(int n)
{
	cout << n << "	";
}
void main()
{
	int a[] = {1,3,2,3,4,5};
	vector<int> v(a,a+6);
	for_each(v.begin(),v.end(),print_element);
	cout << endl;

	//remove(v.begin(),v.end(),3);
	//cout << "the remove result:\n";
	//for_each(v.begin(), v.end(), print_element);
	//cout << endl;
	////remove()只对元素进行逻辑上的移除 物理位置上并没有（也就是没有进行真正意义上的操作）
	//	//首先查找给定值第一个位置，然后遍历后面的元素，将非移除元素拷贝到前面，覆盖到前面的元素
	
	//做物理删除 用erase()
	v.erase(remove(v.begin(), v.end(), 3),v.end());
	for_each(v.begin(), v.end(), print_element);
	cout << endl;

	system("pause");
}