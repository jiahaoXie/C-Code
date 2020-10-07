//KMP算法（厉害 很强的算法）

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
//KMP算法的实现:
//第一步，先把模式T所有可能的失配点j所对应的next[j]计算出来；
//第二步：执行定位函数Index_kmp（与BF算法模块非常相似）

//不同之处在于当匹配过程失配时 指针i不变，指针j退到next[j]的位置 再重新进行比较
//并且当指针j为0时，指针j和i同时加1.
int KMPindex(SString S, SString T, int pos)
{//kmp算法实现
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

//（1）k值仅取决于模式串本身而与相匹配的主串无关。
//（2）k值为模式串从头向后及从j向前的两部分的最大相同子串的长度。
//（3）这里的两部分子串可以有部分重叠的字符，但不可以全部重叠。
//（4）next[j]函数表征着模式P中最大相同前缀子串和后缀子串（真子串）的长度。
//可见，模式中相似部分越多，则next[j]函数越大，它既表示模式T字符之间的相关度越高，也表示j位置以前与主串部分匹配的字符数越多。
//即：next[j]越大，模式串向右滑动得越远，与主串进行比较的次数越少，时间复杂度就越低（时间效率）。
void GetNext(SString T, int next[])
{//求子串T的最大前缀 用next[]保存
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