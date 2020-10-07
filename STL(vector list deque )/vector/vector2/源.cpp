#include<iostream>
#include<vector>
using namespace std;

int main()
{
	vector<int> v1;
	
	for (int i = 1; i <= 5; i++)
	{
		v1.push_back(5*i);//����ĩ�˲���Ԫ��
	}

	int& i = v1.at(0);	//at()�������ض�ʸ����ָ��λ�õ�Ԫ�ص����á�
	int& j = v1.at(1);
	cout << "The first element is " << i << endl;
	cout << "The second element is " << j << endl;

	int& k = v1.back();	//back()����ֵ���������һ��Ԫ�ء� �������Ϊ�գ��򷵻�ֵ��ȷ����
	cout << "The last integer of v1 is " << k << endl;

	vector<int>::iterator it1;	//���������
	for (it1 = v1.begin(); it1 != v1.end(); it1++)
	{
		cout << *it1<<"  ";
	}
	cout << endl;

	vector<int>::reverse_iterator it2;	//���������
	for (it2 = v1.rbegin(); it2 != v1.rend(); it2++)
		cout << *it2 << "  ";
	cout << endl;

	vector<int>::pointer v1_ptr;
	vector<int>::const_pointer v1_cPtr;

	cout << "The vector v1  contains elements:";
	v1_cPtr = v1.data();
	for (size_t n = v1.size(); 0 < n; --n, v1_cPtr++)
	{
		cout << " " << *v1_cPtr;
	}
	cout << endl;

	cout << "The vector v1 now contains elements:";
	v1_ptr = v1.data();
	*v1_ptr = 20;
	for (size_t n = v1.size(); 0 < n; --n, v1_ptr++)
	{
		cout << " " << *v1_ptr;
	}
	cout << endl;

	system("pause");
	return 0;
}