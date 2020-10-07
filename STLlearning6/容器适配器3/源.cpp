//实现优先级队列（priority queue）
#include<iostream>
#include<stack>
#include<queue>
#include<functional>
using namespace std;

void main()
{
	int a[] = {5,2,4,1,3};
	priority_queue<int> q(a,a+5);
	priority_queue<int,vector<int>,greater<int> > q2(a, a + 5);
	//当优先级队列中加入算法greater(greater中越小的数字优先级越高)后，需要带三个参数（因为priority_queue默认情况下为容器），
			//则按照从小到大进行弹出
	
	cout << "The Default Rusult:\n";
	while (!q.empty())
	{//优先级队列priority_queue默认情况按照值从大到小进行弹出
		cout << q.top() << ' ';
		q.pop();
	}
	cout << endl;

	cout << "greater result:\n";
	while (!q2.empty())
	{//优先级队列priority_queue默认情况按照值从大到小惊醒弹出
		cout << q2.top() << ' ';
		q2.pop();
	}
	cout << endl;

	system("pause");
}