#include<iostream>
#include<functional>
#include<set>

using namespace std;

void main()
{
	set<int> s;
	s.insert(2);
	s.insert(1);
	s.insert(3);
	//setĬ������� Ҳ�Ǵӵ�����������
	for (set<int>::const_iterator it = s.begin(); it != s.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;

	//���greater ֮��Ϊ�Ӵ�С����
	set<int,greater<int> > s2;
	s2.insert(2);
	s2.insert(1);
	s2.insert(3);
	//setĬ������� Ҳ�Ǵӵ�����������
	for (set<int>::const_iterator it = s2.begin(); it != s2.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;

	system("pause");
}