//��ģ�壺���ඨ���е��������Ͳ�����
//��ģ��ʵ�����Ǻ���ģ����ƹ㡣
//��ģ���ʵ�������þ�������������滻ģ��Ĳ����Եõ�������ࣨģ���ࣩ
//ģ����Ҳ����ʵ����Ϊ����
//�����з�ʽ������ģ���ʵ����
//����<����ʵ�α�>�������ƣ�

//main.cpp
#include <iostream>
#include"Stack.h"
#include"Stack2.h"
using namespace std;
void main(void)
{
	//Stack2<int, 10> s;
	Stack<int> s(10);
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
