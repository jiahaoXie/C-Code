//main.cpp
#include<iostream>
using namespace std;

#include"DebugNew.h"
#include"Node.h"
void main()
{
	//int* p = new int;//��ջ�����ĸ��ֽڵĿռ�
	//				 //delete p;

	//int* p2 = new int[5];
	////delete[] p2;

	//Node* pNode = new Node;
	//pNode����Ϊ��ָ��
	//��ָ�� ��װ��

	//pNode->Calc();
	NodePtr np(new Node);
	np->Calc();
	//ͨ������ָ�� ����� ���Է��������ָ��pNode�ķ���
	NodePtr np2(np);
	NodePtr np3;
	np3= np2;
	system("pause");
}
//ջչ���Ĺ�����ָ�벻���Զ��ͷ�
//Ӧ��RAII���� ����ָ��ת��Ϊ����ָ�루��һ���ࣩ
//��ָ��ת��Ϊ����
//��������������������ڽ��޵�ʱ����ȷ�������õ�