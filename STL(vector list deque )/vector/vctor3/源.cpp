#include<iostream>
#include<vector>
using namespace std;

int main()
{
	vector<int> v1;
	vector<int>::iterator it;

	for (int i = 0; i < 5; i++)
		v1.push_back(i*10);

	cout << "the original vector<int> :\n";
	for (it = v1.begin(); it != v1.end(); it++)
		cout << *it << " ";
	cout << endl;

	v1.insert(v1.begin()+1,100);	//��ָ��λ�� ����Ԫ��
	for (it = v1.begin(); it != v1.end(); it++)
		cout << *it << " ";
	cout << endl;

	v1.insert(v1.begin() + 2, 4, 99);//��ָ����Χ�ڲ���Ԫ��
	for (it = v1.begin(); it != v1.end(); it++)
		cout << *it << " ";
	cout << endl;

	system("pause");
	return 0;
}