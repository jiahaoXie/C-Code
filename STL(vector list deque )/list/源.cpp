#include<iostream>
#include<list>
#include<vector>
using namespace std;

int main()
{
	
	list<int> l1,l2;
	vector<int>v1;
	list<int>::iterator it;
	for (int i = 0; i < 5; i++)
	{
		l1.push_back(5 * i);
		l2.push_back(10 * i);
	}

	cout << "l1:";
	for (it = l1.begin(); it != l1.end(); it++)
		cout << *it << " ";
	cout << endl;

	cout << "l2:";
	for (it = l2.begin(); it != l2.end(); it++)
		cout << *it << " ";
	cout << endl;



	////˳�����list�е�Ԫ�أ���ʹ�õ������Ĺ�����ͬ��
	//cout << "l1 =";
	//for (auto l : l1)
	//	cout << " " << l;
	//cout << endl;

	//l1.assign(l2.begin(), l2.end());	
	////assign()����б��е�Ԫ�أ�����һ����Ԫ�ظ��Ƶ�Ŀ���б�
	////�����ǰ�list l1�е�ԭ��Ԫ���������l2��Ԫ�ظ��ƹ���
	//cout << "l1 =";
	//for (auto c : l1)
	//	cout << " " << c;
	//cout << endl;
	//l1.assign({9,9,9,9});
	//cout << "c1 =";
	//for (auto c : l1)
	//	cout << " " << c;
	//cout << endl;


	system("pause");
	return 0;
}