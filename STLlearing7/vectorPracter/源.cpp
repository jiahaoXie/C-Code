#include<iostream>
#include<vector>
using namespace std;
//ɾ��vector��ĳ��Ԫ�غ� �������ֵ
void main()
{
	int a[] = {3,2,5,3};
	vector<int> v(a,a+4);

	for (vector<int>::const_iterator it = v.begin(); it != v.end();)
	{
		if (*it == 3)
			it = v.erase(it);
		else
		{
			cout << *it << " ";
			++it;
		}
	}
	cout << endl;
	system("pause");
}