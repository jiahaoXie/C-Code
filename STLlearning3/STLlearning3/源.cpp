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
	//����������ʼ������v ������a�е����ݼ��ص�����v�� 
	//ע��,vector��Ϊ[)		������first,������end
	//list<int> l(16);//�б��ʼ��Ϊ0

	//vector<int>::const_iterator it;
	////ע��:������it�൱��ָ�루�����ֵΪ*it ����λ�ã��±꣩Ϊit��

	//for (it = v.begin(); it != v.end(); ++it)
	//	cout << *it << " ";
	//cout << endl;

	////����������for_each��������������е�Ԫ��
	////print_elementΪ����
	//for_each(v.begin(), v.end(), print_element);
	//cout << endl;

	////ÿ��Ԫ��ֵ��3(ȡ���ڵ��������� ����add��) 
	//for_each(v.begin(),v.end(),add);
	//for_each(v.begin(), v.end(), print_element);
	//cout << endl;

	//for_each(l.begin(), l.end(), print_element);
	//cout << endl;

	////��vector�е�����Ԫ�ؿ�����list��	copy������ͷ�����п���
	//copy(v.begin(),v.end(),l.begin());
	//for_each(l.begin(), l.end(), print_element);
	//cout << endl;

	////�Ӻ���ǰ���п��� ��copy_backward����
	//copy_backward(v.begin(),v.end(),l.end());
	//for_each(l.begin(), l.end(), print_element);
	//cout << endl;

	system("pause");
}