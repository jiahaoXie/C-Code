//queuede 队列的使用
#include<iostream>
#include<stack>
#include<queue>
using namespace std;

void main()
{
	int a[] = {1,2,3,4,5};
	queue<int> q;

	for (int i = 0; i < 5; i++)
	{
		q.push(i);
	}
	while (!q.empty())
	{
		cout << q.front() << ' ';
		q.pop();
	}
	cout << endl;

	system("pause");
}