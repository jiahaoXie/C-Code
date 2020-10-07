//œÚ«∞≤Â»Î
//front_insert_iterator		front_insert
#include<iostream>
#include<vector>
#include<list>
#include<iterator>
#include<algorithm>
using namespace std;

void ShowList(const list<int>& v)
{
	for (list<int>::const_iterator it = v.begin(); it != v.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;
}
void main()
{
	int a[] = { 1,2,3,4,5 };
	list<int> l(a,a+5);
	list<int> l2;
	front_insert_iterator<list<int> > f1(l);
	ShowList(l);

	f1 = 0;
	ShowList(l);

	copy(l.begin(),l.end(),front_inserter(l2));
	ShowList(l2);

	system("pause");
}
