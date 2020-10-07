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

	//���������ĸ��� �� �ڶ��ַ������ú�����������
	//�����bind2nd����Ԫ��������modulusת��һԪ��������
	//bind2nd(op,value)(param)�൱��op(param,value)
	cout << count_if(v.begin(), v.end(), bind2nd(modulus<int>(), 2)) << endl;

	//bind1st(op,value)(param)�൱��op(value,param)
	cout << count_if(v.begin(), v.end(), bind1st(less<int>(), 4)) << endl;
	//����ʵ�ֵĺ�������Ϊ����n�ĸ���
	system("pause");
}
