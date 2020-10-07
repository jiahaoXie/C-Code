#include <iostream>
#include <stdlib.h>
using namespace std;
typedef struct BiNode
{
	char data;
	BiNode *lchild, *rchild;

}BiNode, *BiTree;


BiTree CreatBiTree()//先序遍历创建二叉树
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
int Max = 0;//count记录每层的节点数,Max记录宽度

void getnum(BiTree T, int i)
{
	if (T != NULL)
	{
		::count[i]++;//第i层结点数+1	::表示全局变量count,因为std中有一个函数count,不加：：会出现指代不明
		if (::count[i]>Max)
			Max = ::count[i];
		getnum(T->lchild, i + 1);//T的左孩子，层数+1
		getnum(T->rchild, i + 1);//T的右孩子，层数+1
	}
}
int main()
{
	BiTree T;
	T = CreatBiTree();
	getnum(T, 1);
	cout <<"宽度=" <<Max<<endl;
	system("pause");
	return 0;
}