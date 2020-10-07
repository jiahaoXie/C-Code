//KMP�㷨������ ��ǿ���㷨��

#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define MAXSTRLEN 100

typedef char SString[MAXSTRLEN + 1];



int KMPindex(SString S, SString T, int pos);
void GetNext(SString T, int next[]);


void main() 
{
	SString S = {13,'a','b','a','b','c','a','b',
					'c','a','c','b','a','b'};
	SString T = { 5,'a','b','c','a','c' };
	int pos;
	pos = KMPindex(S,T,1);
	cout << "pos=" << pos << endl;
	system("pause");
}
//KMP�㷨��ʵ��:
//��һ�����Ȱ�ģʽT���п��ܵ�ʧ���j����Ӧ��next[j]���������
//�ڶ�����ִ�ж�λ����Index_kmp����BF�㷨ģ��ǳ����ƣ�

//��֮ͬ�����ڵ�ƥ�����ʧ��ʱ ָ��i���䣬ָ��j�˵�next[j]��λ�� �����½��бȽ�
//���ҵ�ָ��jΪ0ʱ��ָ��j��iͬʱ��1.
int KMPindex(SString S, SString T, int pos)
{//kmp�㷨ʵ��
	if (pos<1 || pos>S[0]) exit(ERROR);
	int i = pos, j = 1;
	int next[MAXSTRLEN];
	GetNext(T, next);
	while (i <= S[0] && j <= T[0])
	{
		if (S[i] == T[j]) {
			++i; ++j;
		}
		else
		{
			j = next[j];
		}
	}//while
	if (j > T[0]) return i - T[0];
	return ERROR;
}

//��1��kֵ��ȡ����ģʽ�����������ƥ��������޹ء�
//��2��kֵΪģʽ����ͷ��󼰴�j��ǰ�������ֵ������ͬ�Ӵ��ĳ��ȡ�
//��3��������������Ӵ������в����ص����ַ�����������ȫ���ص���
//��4��next[j]����������ģʽP�������ͬǰ׺�Ӵ��ͺ�׺�Ӵ������Ӵ����ĳ��ȡ�
//�ɼ���ģʽ�����Ʋ���Խ�࣬��next[j]����Խ�����ȱ�ʾģʽT�ַ�֮�����ض�Խ�ߣ�Ҳ��ʾjλ����ǰ����������ƥ����ַ���Խ�ࡣ
//����next[j]Խ��ģʽ�����һ�����ԽԶ�����������бȽϵĴ���Խ�٣�ʱ�临�ӶȾ�Խ�ͣ�ʱ��Ч�ʣ���
void GetNext(SString T, int next[])
{//���Ӵ�T�����ǰ׺ ��next[]����
	int j = 1, k = 0;
	next[1] = 0;
	while (j < T[0]) {
		if (k == 0 || T[j] == T[k]) {
			++j; ++k;
			next[j] = k;
		}
		else
		{
			k = next[k];
		}
	}
}