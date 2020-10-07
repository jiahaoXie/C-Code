#include <iostream>
#include <stdlib.h>
using namespace std;
typedef struct BiNode
{
	char data;
	BiNode *lchild, *rchild;

}BiNode, *BiTree;


BiTree CreatBiTree()//�����������������
{
	BiTree T;
	char ch;
	cin >> ch;
	if (ch == '#')
		T = NULL;
	else
	{
		T = (BiTree)malloc(sizeof(BiNode));
		T->data = ch;
		T->lchild = CreatBiTree();
		T->rchild = CreatBiTree();
	}
	return T;
}
int count[1000] = { 0 };
int Max = 0;//count��¼ÿ��Ľڵ���,Max��¼���

void getnum(BiTree T, int i)
{
	if (T != NULL)
	{
		::count[i]++;//��i������+1	::��ʾȫ�ֱ���count,��Ϊstd����һ������count,���ӣ��������ָ������
		if (::count[i]>Max)
			Max = ::count[i];
		getnum(T->lchild, i + 1);//T�����ӣ�����+1
		getnum(T->rchild, i + 1);//T���Һ��ӣ�����+1
	}
}
int main()
{
	BiTree T;
	T = CreatBiTree();
	getnum(T, 1);
	cout <<"���=" <<Max<<endl;
	system("pause");
	return 0;
}