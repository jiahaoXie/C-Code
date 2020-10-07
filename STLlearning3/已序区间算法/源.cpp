//lower_bound	������һ�������ڵ��ڸ���ֵ����Ԫ��
//				���Ҫ�������ֵ���������������ԣ����ص�һ���ɲ����λ��
//upper_bound	������һ�������ڸ���ֵ����Ԫ��
//				���Ҫ�������ֵ���������������ԣ����ص�һ���ɲ����λ��


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