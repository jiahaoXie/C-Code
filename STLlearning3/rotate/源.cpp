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

	//rotate()������Ԫ�ؽ��з�ת
	rotate(v.begin(),v.begin()+2,v.end()-1);
	for_each(v.begin(), v.end(), print_element);
	cout << endl;

	//sort()Ĭ�����Ϊ�ӵ����������
	sort(v.begin(),v.end());
	for_each(v.begin(), v.end(), print_element);
	cout << endl;

	//���ü���������������Զ��庯��my_greater��
	sort(v.begin(),v.end(),my_greater);
	for_each(v.begin(), v.end(), print_element);
	cout << endl;

	system("pause");
}