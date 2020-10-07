//有关二叉树递归的算法
//设二叉树的存储结构为二叉链表，编写有关二叉树的递归算法：
//（1）从二叉树中删去所有叶节点。
//（2）计算二叉树中指定结点*p所在层次。
//（3）计算二叉树中各结点中的最大元素的值。
//（4）交换二叉树中每个结点的两个子女。
//（5）以前序次序输出一棵二叉树所有结点的数据值及结点所在层次。

#include<iostream> 
#include"BiTree.h"
using namespace std;
extern int depth;
void main()
{
	BiTree bt;
	bt.CreateTree();

	//求p的深度
	bt.DepthOfTheNode(bt.root, bt.root->left->right, 0);
	cout << "深度:" << depth << endl;

	//找最大值
	int maxValue;
	bt.FindMaxValue(bt.root, &maxValue);
	cout << "最大值为：" << maxValue << endl;

	//交换左右节点
	bt.ExchangeLeftAndRight(bt.root);

	//以前序次序输出一棵二叉树所有结点的数据值及结点所在层次
	bt.OutputValueAndDepthByQIANXU(bt.root, 0);

	//删除叶子节点
	bt.deleteLeaves(bt.root);
	system("pause");
}