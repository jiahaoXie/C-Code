#include<iostream>
#include"BiTree.h"
BiTree::BiTree()
{
	root = NULL;
}
BiTree::~BiTree()
{
	deleteAllNode(root);
}
void BiTree::deleteAllNode(BiTreeNode *root)
{
	if (root == NULL) return;
	deleteAllNode(root->left);
	deleteAllNode(root->right);
	std::cout << root->data << ' '; //用来查看当前节点是不是被删除。
	delete root;
}
//手动建立一个二叉树用于测试
// 1
// / \
// 2 3
// \ /
// 4 5
void BiTree::CreateTree()
{
	if (root) return;
	root = new BiTreeNode;
	root->data = 1;
	root->left = new BiTreeNode;
	root->left->data = 2;
	root->right = new BiTreeNode;
	root->right->data = 3;
	BiTreeNode *p;
	p = root->left;
	p->left = NULL;
	p->right = new BiTreeNode;
	p->right->data = 4;
	p->right->left = p->right->right = NULL;
	p = root->right;
	p->left = new BiTreeNode;
	p->left->data = 5;
	p->left->left = p->left->right = NULL;
	p->right = NULL;
}
//用递归算法删除叶子
void BiTree::deleteLeaves(BiTreeNode *root)
{
	if (root == NULL) return;
	if (!root->left && !root->right) return; //表示是根节点(或者出错，跑到叶子节点了，这种情况应该不会)，不删除
	if (root->left) //当前节点有左子树
	{
		if (root->left->left || root->left->right) //左子树不是叶子
			deleteLeaves(root->left);
		else //当前节点的左子节点是叶子
		{
			delete root->left;
			root->left = NULL;
		}
	}
	if (root->right)
	{
		if (root->right->left || root->right->right)
			deleteLeaves(root->right);
		else //当前节点的右子节点是叶子
		{
			delete root->right;
			root->right = NULL;
		}
	}
}
int depth = 0; //一个用来存储深度的全局变量，虽然在实际编程中这样用不好
			   //但一切为了方便。
			   //节点p的深度,递归法
bool BiTree::DepthOfTheNode(BiTreeNode *currentNode, BiTreeNode *p, int depthOfFather)
{
	if (currentNode == NULL) return false;
	if (currentNode == p) //当前节点为要找的节点
	{
		depth = depthOfFather + 1;
		return true;
	}
	if (DepthOfTheNode(currentNode->left, p, depthOfFather + 1)) //找当前节点的左子树
		return true;
	else
		return DepthOfTheNode(currentNode->right, p, depthOfFather + 1);
}

//用递归找最大值，最大值存储在maxValue所指的内存 ,这里使用前序遍历
void BiTree::FindMaxValue(BiTreeNode *currentNode, int *maxValue)
{
	if (currentNode == NULL) return;
	*maxValue = *maxValue > currentNode->data ? *maxValue : currentNode->data;
	FindMaxValue(currentNode->left, maxValue); //遍历左子树
	FindMaxValue(currentNode->right, maxValue);
}

//交换左右，用前序遍历
void BiTree::ExchangeLeftAndRight(BiTreeNode *currentNode)
{
	if (currentNode == NULL) return;
	BiTreeNode *temp;
	temp = currentNode->left;
	currentNode->left = currentNode->right;
	currentNode->right = temp;
	ExchangeLeftAndRight(currentNode->left);
	ExchangeLeftAndRight(currentNode->right);
}

//以前序次序输出一棵二叉树所有结点的数据值及结点所在层次
void BiTree::OutputValueAndDepthByQIANXU(BiTreeNode *currentNode, int depthOfFather)
{
	if (currentNode == NULL) return;
	std::cout << "节点：" << currentNode->data;
	std::cout << "\t深度：" << depthOfFather + 1 << std::endl;
	OutputValueAndDepthByQIANXU(currentNode->left, depthOfFather + 1);
	OutputValueAndDepthByQIANXU(currentNode->right, depthOfFather + 1);
}