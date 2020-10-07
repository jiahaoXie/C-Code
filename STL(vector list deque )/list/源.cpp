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



	////顺序输出list中的元素（与使用迭代器的功能相同）
	//cout << "l1 =";
	//for (auto l : l1)
	//	cout << " " << l;
	//cout << endl;

	//l1.assign(l2.begin(), l2.end());	
	////assign()清除列表中的元素，并将一组新元素复制到目标列表。
	////这里是把list l1中的原来元素清除，把l2的元素复制过来
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