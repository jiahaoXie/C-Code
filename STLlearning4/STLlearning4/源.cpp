//��stl����˻ʺ�����

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void print_element(int n)
{
	cout << n << " ";
}
void main()
{
	int a[] = {1,2,3,4};
	vector<int> v(a,a+4);
	for_each(v.begin(),v.end(),print_element);
	cout << endl;
	//next_permutation()���� �ɵõ��������
	cout << "��next_permutation()�����õ���\n";
	while (next_permutation(v.begin(), v.end()))
	{
		for_each(v.begin(), v.end(), print_element);
		cout << endl;
	}
	system("pause");
}
