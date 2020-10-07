#include"hcf.h"

#include<cstdio>  
#include<cstring> 
#include <fstream>
#include<string>
#include <stdlib.h> 
#include <time.h> 
/*void HufTree::SetHuf(int i,double wei,char ch)
{
HufArry[i].Data = ch;
HufArry[i].Weight = wei;
}*/
void HufTree::SetHuf(int n)
{
	ifstream in("G:\\研究生学习 代码\\关键字1.txt");  
	//string filename;  
	//string line[100];  
	int i=0,j=1,k;
	if(in) // 有该文件  
	{  
		while (getline (in, HufArry[++i].Data)) // line中不包括每行的换行符  
		{   
			cout << HufArry[i].Data << '\t'; 
			j++;
			if(j>=n)
				break;
		} 
		cout<<"\n一共有"<<j<<"个关键字\n";
	}  
	else // 没有该文件  
	{  
		cout <<"no such file" << endl;  
	}  

	srand((unsigned)time(NULL));  
	for( k = 0; k < n;k++ )  
	{
		HufArry[k].Weight=rand()%150;
		cout<<HufArry[k].Weight<<"\t";
	}
		//	cout << rand()%150 << '\t';  
		//cout << rand()/double(RAND_MAX) << '\t';	
		cout << "一共有"<<k<<"个权值";
}
void HufTree::CreatHuf(int n)
{
	//cout<<"每次查询两个最小树的位置:"<<endl;
	for(int i = n; i < 2*n - 1; i++)
	{
		int p1 = 0;
		int p2 = 0;
		SelectMin(i,p1,p2);           //找出当前树种权值最小的两颗树 
		cout<<p1<<"   < - >    "<<p2<<endl;
		HufArry[p1].Parent = i;   //设置两颗最小树的双亲
		HufArry[p2].Parent = i;
		HufArry[i].Lchild = p1;   //设置这棵3节点的树的根的权值以及孩子
		HufArry[i].Rchild = p2;   
		HufArry[i].Weight = HufArry[p1].Weight + HufArry[p2].Weight;
	}
	cout<<"************************"<<endl;
}
void HufTree::SelectMin(int i,int &p1,int &p2)
{
	int least1 = MAXWEIGHT;
	int least2 = MAXWEIGHT;
	for(int j = 0; j < i; j++)
	{
		if(HufArry[j].Parent == -1)
		{

			if(HufArry[j].Weight < least1)
			{
				least2 = least1;
				least1 = HufArry[j].Weight;
				p2 = p1;
				p1 = j;
			}
			else
			{
				if(HufArry[j].Weight < least2)
				{
					least2 = HufArry[j].Weight;
					p2 = j;
				}
			}
		}
	}
}
void HufTree::Find_Root_and_Print(int n)
{
	int root;
	string x;
	for(int i = 0; i < 2*n - 1; i++)
	{
		if(HufArry[i].Parent == -1)
		{
			root = i;
			break;
		}
	}
	cout<<"please input the words:";
	cin>>x;
	PrintHuf(root,x);
}
void HufTree::PrintHuf( unsigned int position,string x)
{
	string::size_type idx;
	if(NodeNum == LEAFNUM)
	{

		return;
	}
	else
	{
		NodeNum+=1;
		idx=HufArry[position].Data.find(x);//在s1[]中查找s.
		if(idx != string::npos )//存在则输出。
		{
			cout << "words found\t"<<HufArry[position].Data<<"\t"<<HufArry[position].Weight<<endl;
		}	 
	
		else
		{
			//cout<<"权值:"<<HufArry[position].Weight<<" 此节点无数据域,不是叶子"<<endl;
			PrintHuf(HufArry[position].Lchild,x);
			PrintHuf(HufArry[position].Rchild,x);
		}
	}
}
