//�йض������ݹ���㷨
//��������Ĵ洢�ṹΪ����������д�йض������ĵݹ��㷨��
//��1���Ӷ�������ɾȥ����Ҷ�ڵ㡣
//��2�������������ָ�����*p���ڲ�Ρ�
//��3������������и�����е����Ԫ�ص�ֵ��
//��4��������������ÿ������������Ů��
//��5����ǰ��������һ�ö��������н�������ֵ��������ڲ�Ρ�

#include<iostream> 
#include"BiTree.h"
using namespace std;
extern int depth;
void main()
{
	BiTree bt;
	bt.CreateTree();

	//��p�����
	bt.DepthOfTheNode(bt.root, bt.root->left->right, 0);
	cout << "���:" << depth << endl;

	//�����ֵ
	int maxValue;
	bt.FindMaxValue(bt.root, &maxValue);
	cout << "���ֵΪ��" << maxValue << endl;

	//�������ҽڵ�
	bt.ExchangeLeftAndRight(bt.root);

	//��ǰ��������һ�ö��������н�������ֵ��������ڲ��
	bt.OutputValueAndDepthByQIANXU(bt.root, 0);

	//ɾ��Ҷ�ӽڵ�
	bt.deleteLeaves(bt.root);
	system("pause");
}