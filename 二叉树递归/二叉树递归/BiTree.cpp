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
	std::cout << root->data << ' '; //�����鿴��ǰ�ڵ��ǲ��Ǳ�ɾ����
	delete root;
}
//�ֶ�����һ�����������ڲ���
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
//�õݹ��㷨ɾ��Ҷ��
void BiTree::deleteLeaves(BiTreeNode *root)
{
	if (root == NULL) return;
	if (!root->left && !root->right) return; //��ʾ�Ǹ��ڵ�(���߳����ܵ�Ҷ�ӽڵ��ˣ��������Ӧ�ò���)����ɾ��
	if (root->left) //��ǰ�ڵ���������
	{
		if (root->left->left || root->left->right) //����������Ҷ��
			deleteLeaves(root->left);
		else //��ǰ�ڵ�����ӽڵ���Ҷ��
		{
			delete root->left;
			root->left = NULL;
		}
	}
	if (root->right)
	{
		if (root->right->left || root->right->right)
			deleteLeaves(root->right);
		else //��ǰ�ڵ�����ӽڵ���Ҷ��
		{
			delete root->right;
			root->right = NULL;
		}
	}
}
int depth = 0; //һ�������洢��ȵ�ȫ�ֱ�������Ȼ��ʵ�ʱ���������ò���
			   //��һ��Ϊ�˷��㡣
			   //�ڵ�p�����,�ݹ鷨
bool BiTree::DepthOfTheNode(BiTreeNode *currentNode, BiTreeNode *p, int depthOfFather)
{
	if (currentNode == NULL) return false;
	if (currentNode == p) //��ǰ�ڵ�ΪҪ�ҵĽڵ�
	{
		depth = depthOfFather + 1;
		return true;
	}
	if (DepthOfTheNode(currentNode->left, p, depthOfFather + 1)) //�ҵ�ǰ�ڵ��������
		return true;
	else
		return DepthOfTheNode(currentNode->right, p, depthOfFather + 1);
}

//�õݹ������ֵ�����ֵ�洢��maxValue��ָ���ڴ� ,����ʹ��ǰ�����
void BiTree::FindMaxValue(BiTreeNode *currentNode, int *maxValue)
{
	if (currentNode == NULL) return;
	*maxValue = *maxValue > currentNode->data ? *maxValue : currentNode->data;
	FindMaxValue(currentNode->left, maxValue); //����������
	FindMaxValue(currentNode->right, maxValue);
}

//�������ң���ǰ�����
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

//��ǰ��������һ�ö��������н�������ֵ��������ڲ��
void BiTree::OutputValueAndDepthByQIANXU(BiTreeNode *currentNode, int depthOfFather)
{
	if (currentNode == NULL) return;
	std::cout << "�ڵ㣺" << currentNode->data;
	std::cout << "\t��ȣ�" << depthOfFather + 1 << std::endl;
	OutputValueAndDepthByQIANXU(currentNode->left, depthOfFather + 1);
	OutputValueAndDepthByQIANXU(currentNode->right, depthOfFather + 1);
}