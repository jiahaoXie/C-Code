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
	////remove()ֻ��Ԫ�ؽ����߼��ϵ��Ƴ� ����λ���ϲ�û�У�Ҳ����û�н������������ϵĲ�����
	//	//���Ȳ��Ҹ���ֵ��һ��λ�ã�Ȼ����������Ԫ�أ������Ƴ�Ԫ�ؿ�����ǰ�棬���ǵ�ǰ���Ԫ��
	
	//������ɾ�� ��erase()
	v.erase(remove(v.begin(), v.end(), 3),v.end());
	for_each(v.begin(), v.end(), print_element);
	cout << endl;

	system("pause");
}