//�򵥵�ģʽƥ���㷨��BF�� ȱ����ʱ�临�Ӷ�Ϊo(n*m)
#include <stdio.h>    
#include <stdlib.h>  
#include<time.h>
#include<windows.h>
#include <iostream>  
using namespace std;

#pragma comment(lib, "winmm.lib ")

//�궨��      
#define TRUE   1      
#define FALSE   0      
#define OK    1      
#define ERROR   0    

#define  MAXSTRLEN 100  

typedef char    SString[MAXSTRLEN + 1];
/************************************************************************/
/*
�����Ӵ�T������S�е�posλ��֮���λ�ã��������ڣ�����0
*/
/************************************************************************/
int BFindex(SString S, SString T, int pos)
{
	if (pos <1 || pos > S[0]) exit(ERROR);
	int i = pos, j = 1;
	while (i <= S[0] && j <= T[0])
	{
		if (S[i] == T[j])
		{//����ַ���� ��������Ƚ�
			++i; ++j;
		}
		else {//������� ������s����һ���ַ��������¿�ʼ���Ӵ�T�ĵ�һ���Ӵ����±Ƚϣ�
			i = i - j + 2;	//�����ʽ���Ƶ���ͼƬΪ֤
			j = 1;
		}
	}
	if (j > T[0]) return i - T[0];
	return ERROR;
}

void main() {
	SString S = { 13,'a','b','a','b','c','a','b','c','a','c','b','a','b' };
	SString T = { 5,'a','b','c','a','c' };
	int pos;

	//���ù��� start end �����BF�㷨�ĳ�������ʱ�䣡
	//double dur;
	//clock_t start, end;
	//start = clock();
//����windows API ����õ��������е�ʱ��
	/*DWORD t1, t2;
	t1 = timeGetTime();
	pos = BFindex(S, T, 1);
	t2 = timeGetTime();*/


		LARGE_INTEGER t1, t2, tc;
		QueryPerformanceFrequency(&tc);
		QueryPerformanceCounter(&t1);
		pos = BFindex(S, T, 1);
		QueryPerformanceCounter(&t2);
		cout << "Pos:" << pos << endl;
		printf("Use Time:%f\n", (t2.QuadPart - t1.QuadPart)*1.0 / tc.QuadPart);

//	end = clock();
	//dur = double(start - end);
	//cout << "Pos:" << pos<<endl;
	//printf("use time:%f",(t2-t1)*1.0/1000);
	//cout << "use time:" << dur << endl;
	system("pause");
}