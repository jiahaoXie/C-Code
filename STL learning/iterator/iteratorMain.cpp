#include<vector>
#include<iostream>
using namespace std;

void main()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);

	vector<int>::iterator it;	//���������
	for (it = v.begin(); it != v.end(); ++it)
	{
		cout << *it << ' ';
	}
	cout << endl;

	//Ԫ�ط������(���÷��������)
	vector<int>::reverse_iterator ri;
	for (ri = v.rbegin(); ri != v.rend(); ++ri)
		cout << *ri << '!';
	cout << endl;

	system("pause");
}