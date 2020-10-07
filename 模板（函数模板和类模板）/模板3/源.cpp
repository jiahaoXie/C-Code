#include <iostream>
#include<vector>
#include"Stack.h"
using namespace std;
void main(void)
{
	//Stack<int> s;
	Stack<int, vector<int> > s;//模板类当做参数来进行传递
		//这里定义声明时 因为类在定义时deque为容器 
						//只要声明的容器含有push_back,pop_back等方法时皆可用
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