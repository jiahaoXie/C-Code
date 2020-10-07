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
	//����������ʼ������v ������a�е����ݼ��ص�����v�� 
	//ע��,vector��Ϊ[)		������first,������end
	list<int> l(6);

	replace(v.begin(),v.end(),4,14);
	for_each(v.begin(),v.end(),print_element);
	cout << endl;

	//replace_copy �ڿ����Ĺ��̵��з����滻��ԭ���䲻�䣬Ŀ��������ֵ�����ı䣩
	replace_copy(v.begin(),v.end(),l.begin(),14,4);
	//���ԭ����
	cout << "the original:";
	for_each(v.begin(), v.end(), print_element);
	cout << endl;
	//��������õ���Ŀ������
	cout << "the      new:";
	for_each(l.begin(), l.end(), print_element);
	cout << endl;

	//replace_copy_if��������Զ����func()���� ��С��10��Ԫ�ظ�ֵΪ100
	replace_copy_if(v.begin(),v.end(),l.begin(),func,100);
	for_each(l.begin(), l.end(), print_element);
	cout << endl;

	system("pause");
}