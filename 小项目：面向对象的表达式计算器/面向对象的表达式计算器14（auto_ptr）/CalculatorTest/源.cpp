//main.cpp
#include<iostream>
#include<vector>
#include<xmemory>
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

	/*std::auto_ptr<Node> node(new Node);
	vector<std::auto_ptr<Node>> v;
	v.push_back(node);*/
	//STL����Ҫ�����������е�Ԫ���ܹ���������Ҳ����Ҫ��������ֵ�������
	//auto_ptr����ֵ���� ʵ���ǽ���������ת��Ϊֵ����
	
	//��������ǲ����������͵�����ָ�� ����ptr_vectorָ��������ptr_container��һ��������
	system("pause");
}
//ջչ���Ĺ�����ָ�벻���Զ��ͷ�
//Ӧ��RAII���� ����ָ��ת��Ϊ����ָ�루��һ���ࣩ
//��ָ��ת��Ϊ����
//��������������������ڽ�����ʱ����ȷ�������õ�