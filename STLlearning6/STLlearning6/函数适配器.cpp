#include<iostream>
#include<algorithm>
#include<functional>
#include<vector>

using namespace std;

bool is_odd(int n)
{
	return n % 2==1;
}
void main()
{
	int a[] = {1,2,3,4,5};
	vector<int> v(a,a+5);

	cout << count_if(v.begin(), v.end(), is_odd) << endl;

	//计算奇数的个数 （ 第二种方法采用函数适配器）
	//这里的bind2nd将二元函数对象modulus转换一元函数对象
	//bind2nd(op,value)(param)相当于op(param,value)
	cout << count_if(v.begin(), v.end(), bind2nd(modulus<int>(), 2)) << endl;

	//bind1st(op,value)(param)相当于op(value,param)
	cout << count_if(v.begin(), v.end(), bind1st(less<int>(), 4)) << endl;
	//这里实现的函数功能为大于n的个数
	system("pause");
}
