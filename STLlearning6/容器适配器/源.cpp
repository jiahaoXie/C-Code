//stack的使用
#include<iostream>
#include<stack>
#include<vector>
#include<list>
using namespace std;

void main()
{
	stack<int> s;
	stack<int, list<int> > s2;
	stack<int, vector<int> > s3;
	//利用现有的容器去实现stack(容器适配器)
	for (int i = 0; i < 5; i++)
	{
		s.push(i);

	}
	while (!s.empty())
	{
		cout << s.top() << ' ';
		s.pop();
	}
	cout << endl;
	/*for (size_t i = 0; i<s.size();i++)
	{
		cout << s.top() << ' ';
		s.pop();
	}
	cout << endl;*/

	for (int i = 10; i < 15; i++)
	{
		s2.push(i);

	}
	while (!s2.empty())
	{
		cout << s2.top() << ' ';
		s2.pop();
	}
	cout << endl;

	for (int i = 20; i <25; i++)
	{
		s3.push(i);

	}
	while (!s3.empty())
	{
		cout << s3.top() << ' ';
		s3.pop();
	}
	cout << endl;

	system("pause");
}