#include<iostream>
#include<vector>
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
void main()
{
	int a[] = {2,3,4,6,1,5};
	vector<int> v(a,a+6);
	//用数组来初始化变量v 将数组a中的数据加载到向量v中 
	//注意,vector中为[)		即包括first,不包括end

	vector<int>::const_iterator it;
	//注意:迭代器it相当于指针（输出数值为*it 物理位置（下标）为it）

	for (it = v.begin(); it != v.end(); ++it)
		cout << *it << " ";
	cout << endl;

	//还可以利用for_each方法来输出向量中的元素
	//print_element为函数
	for_each(v.begin(),v.end(),print_element);
	cout << endl;

	//输出向量中的最小值
	it = min_element(v.begin(),v.end());
	if (it != v.end())
		cout << "最小值："<<*it << endl;

	//输出向量中的最大值
	it = max_element(v.begin(), v.end());
	if (it != v.end())
		cout << "最大值："<<*it << endl;

	//find()查找某个元素所在的下标
	it = find(v.begin(),v.end(),4);
	if (it != v.end())
		cout << it - v.begin() << endl;	//如果找到了 返回元素之的下标
	else
		cout << "NO FOUND" << endl;

	//find_if()查找某个元素所在的下标 第三个参数为函数名
	it = find_if(v.begin(), v.end(), morethan_3);
	if (it != v.end())
	{
		cout << "position:"<<it - v.begin() <<"	" ;	//如果找到了 返回元素之的下标
		cout <<"value:"<< *it << endl;
	}
	else
		cout << "NO FOUND" << endl;

	system("pause");
}