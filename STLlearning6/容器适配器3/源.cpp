//ʵ�����ȼ����У�priority queue��
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
	//�����ȼ������м����㷨greater(greater��ԽС���������ȼ�Խ��)����Ҫ��������������Ϊpriority_queueĬ�������Ϊ��������
			//���մ�С������е���
	
	cout << "The Default Rusult:\n";
	while (!q.empty())
	{//���ȼ�����priority_queueĬ���������ֵ�Ӵ�С���е���
		cout << q.top() << ' ';
		q.pop();
	}
	cout << endl;

	cout << "greater result:\n";
	while (!q2.empty())
	{//���ȼ�����priority_queueĬ���������ֵ�Ӵ�С���ѵ���
		cout << q2.top() << ' ';
		q2.pop();
	}
	cout << endl;

	system("pause");
}