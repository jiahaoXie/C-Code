//简单的模式匹配算法（BF） 缺点是时间复杂度为o(n*m)
#include <stdio.h>    
#include <stdlib.h>  
#include<time.h>
#include<windows.h>
#include <iostream>  
using namespace std;

#pragma comment(lib, "winmm.lib ")

//宏定义      
#define TRUE   1      
#define FALSE   0      
#define OK    1      
#define ERROR   0    

#define  MAXSTRLEN 100  

typedef char    SString[MAXSTRLEN + 1];
/************************************************************************/
/*
返回子串T在主串S中第pos位置之后的位置，若不存在，返回0
*/
/************************************************************************/
int BFindex(SString S, SString T, int pos)
{
	if (pos <1 || pos > S[0]) exit(ERROR);
	int i = pos, j = 1;
	while (i <= S[0] && j <= T[0])
	{
		if (S[i] == T[j])
		{//如果字符相等 则继续向后比较
			++i; ++j;
		}
		else {//如果不等 则主串s的下一个字符串起重新开始和子串T的第一个子串重新比较，
			i = i - j + 2;	//这个公式的推导有图片为证
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

	//利用挂钟 start end 计算出BF算法的程序运行时间！
	//double dur;
	//clock_t start, end;
	//start = clock();
//利用windows API 计算得到函数运行的时间
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