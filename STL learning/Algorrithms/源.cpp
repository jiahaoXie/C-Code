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
	//����������ʼ������v ������a�е����ݼ��ص�����v�� 
	//ע��,vector��Ϊ[)		������first,������end

	vector<int>::const_iterator it;
	//ע��:������it�൱��ָ�루�����ֵΪ*it ����λ�ã��±꣩Ϊit��

	for (it = v.begin(); it != v.end(); ++it)
		cout << *it << " ";
	cout << endl;

	//����������for_each��������������е�Ԫ��
	//print_elementΪ����
	for_each(v.begin(),v.end(),print_element);
	cout << endl;

	//��������е���Сֵ
	it = min_element(v.begin(),v.end());
	if (it != v.end())
		cout << "��Сֵ��"<<*it << endl;

	//��������е����ֵ
	it = max_element(v.begin(), v.end());
	if (it != v.end())
		cout << "���ֵ��"<<*it << endl;

	//find()����ĳ��Ԫ�����ڵ��±�
	it = find(v.begin(),v.end(),4);
	if (it != v.end())
		cout << it - v.begin() << endl;	//����ҵ��� ����Ԫ��֮���±�
	else
		cout << "NO FOUND" << endl;

	//find_if()����ĳ��Ԫ�����ڵ��±� ����������Ϊ������
	it = find_if(v.begin(), v.end(), morethan_3);
	if (it != v.end())
	{
		cout << "position:"<<it - v.begin() <<"	" ;	//����ҵ��� ����Ԫ��֮���±�
		cout <<"value:"<< *it << endl;
	}
	else
		cout << "NO FOUND" << endl;

	system("pause");
}