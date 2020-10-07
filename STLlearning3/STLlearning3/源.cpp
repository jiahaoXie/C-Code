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

void main()
{
	int a[] = { 2,3,4,6,1,5 };
	vector<int> v(a, a + 6);
	vector<int> v1(a,a+6);
	//v1(a, a + 6);
	//用数组来初始化变量v 将数组a中的数据加载到向量v中 
	//注意,vector中为[)		即包括first,不包括end
	//list<int> l(16);//列表初始化为0

	//vector<int>::const_iterator it;
	////注意:迭代器it相当于指针（输出数值为*it 物理位置（下标）为it）

	//for (it = v.begin(); it != v.end(); ++it)
	//	cout << *it << " ";
	//cout << endl;

	////还可以利用for_each方法来输出向量中的元素
	////print_element为函数
	//for_each(v.begin(), v.end(), print_element);
	//cout << endl;

	////每个元素值加3(取决于第三个参数 函数add（) 
	//for_each(v.begin(),v.end(),add);
	//for_each(v.begin(), v.end(), print_element);
	//cout << endl;

	//for_each(l.begin(), l.end(), print_element);
	//cout << endl;

	////将vector中的数据元素拷贝到list中	copy（）从头向后进行拷贝
	//copy(v.begin(),v.end(),l.begin());
	//for_each(l.begin(), l.end(), print_element);
	//cout << endl;

	////从后往前进行拷贝 用copy_backward（）
	//copy_backward(v.begin(),v.end(),l.end());
	//for_each(l.begin(), l.end(), print_element);
	//cout << endl;

	system("pause");
}