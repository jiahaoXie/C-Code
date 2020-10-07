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
	ifstream in("G:\\�о���ѧϰ ����\\�ؼ���1.txt");  
	//string filename;  
	//string line[100];  
	int i=0,j=1,k;
	if(in) // �и��ļ�  
	{  
		while (getline (in, HufArry[++i].Data)) // line�в�����ÿ�еĻ��з�  
		{   
			cout << HufArry[i].Data << '\t'; 
			j++;
			if(j>=n)
				break;
		} 
		cout<<"\nһ����"<<j<<"���ؼ���\n";
	}  
	else // û�и��ļ�  
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
		cout << "һ����"<<k<<"��Ȩֵ";
}
void HufTree::CreatHuf(int n)
{
	//cout<<"ÿ�β�ѯ������С����λ��:"<<endl;
	for(int i = n; i < 2*n - 1; i++)
	{
		int p1 = 0;
		int p2 = 0;
		SelectMin(i,p1,p2);           //�ҳ���ǰ����Ȩֵ��С�������� 
		cout<<p1<<"   < - >    "<<p2<<endl;
		HufArry[p1].Parent = i;   //����������С����˫��
		HufArry[p2].Parent = i;
		HufArry[i].Lchild = p1;   //�������3�ڵ�����ĸ���Ȩֵ�Լ�����
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
		idx=HufArry[position].Data.find(x);//��s1[]�в���s.
		if(idx != string::npos )//�����������
		{
			cout << "words found\t"<<HufArry[position].Data<<"\t"<<HufArry[position].Weight<<endl;
		}	 
	
		else
		{
			//cout<<"Ȩֵ:"<<HufArry[position].Weight<<" �˽ڵ���������,����Ҷ��"<<endl;
			PrintHuf(HufArry[position].Lchild,x);
			PrintHuf(HufArry[position].Rchild,x);
		}
	}
}
