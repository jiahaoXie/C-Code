#include <iostream>
#include<vector>
#include"Stack.h"
using namespace std;
void main(void)
{
	//Stack<int> s;
	Stack<int, vector<int> > s;//ģ���൱�����������д���
		//���ﶨ������ʱ ��Ϊ���ڶ���ʱdequeΪ���� 
						//ֻҪ��������������push_back,pop_back�ȷ���ʱ�Կ���
	s.Push(1);
	s.Push(2);
	s.Push(3);

	while (!s.Empty())
	{
		cout << s.Top() << endl;
		s.Pop();
	}
	system("pause");
}