#include<iostream>  
#include<cstdio>  
#include<cstring> 
#include <fstream>
#include<string>
#include <stdlib.h> 
#include <time.h> 
using namespace std;  

#define N 500         // �������ַ��ĸ�����������Ҷ����������  
#define M (2*N-1)    // �����ܵĽ����Ŀ

class TreeNode
{
public:
	string data;
	int weight;     // �ַ���Ȩֵ  
	char code[N];   // �ַ��ı���
	TreeNode *lchild,*rchild;
};

void Init(string data[],int a[],int n)
{  
	// ��ʼ��������������ַ��ĸ���n�������е��ļ��ж���n���ַ���n��Ȩֵ 
	//���ȴ�ָ�����ı��ж���n���ַ���
	ifstream in("E:\\�о���ѧϰ\\�ؼ���1.txt");  
	string filename;  
	// string line[50];  
	int i=1,j=1,k;
	if(in) // �и��ļ�  
	{  
		while (getline (in, data[i++])) // line�в�����ÿ�еĻ��з�  
		{   
			//cout << hc[--i].data << '\t';; 
			j++;
			if(j>n)
				break;
		} 
		cout<<"\nһ����"<<j<<"����,";
	}  
	else // û�и��ļ�  
	{  
		cout <<"no such file" << endl;  
	}  

	//������ɶ�Ӧ��n��Ȩֵ
	srand((unsigned)time(NULL));  
	for( k = 1; k <= n;k++ ) 
	{
		a[k]=rand()%150;
		//cout << hc[k].weight<< '\t';  
		//cout << rand()/double(RAND_MAX) << '\t';
	}

	cout << "��"<<k<<"��Ȩֵ\n";


} 

void  FindLittle(int *x1,int *x2 ,TreeNode**pArr,int n)  //���ҳ�2��Ȩֵ��С�Ľڵ���±�  
{  
	int  k1,k2;  //����Ȩ��С�������ڵ��±�   
	k1=-1 ; //��ʾû���ҵ�����  
	for(int i=0;i<n;i++)    //�ҳ����е�ǰ����Ԫ�ز�ΪNULL���±�  
	{    
		if(pArr[i]!=NULL&&k1==-1)  
		{  
			k1=i ;     //��һ���±�  
			continue ;  
		}  
		if(pArr[i]!=NULL)   
		{  
			k2=i ;  
			break;//�ҵ��ڶ����±��˳�ѭ��  
		}  
	}  

	////// ��СȨ��2���±������ʵ��//////////      
	for(int i=k2;i<n;i++) //�������Ȼ�ȡk1  ���ȡk2����һ��ʼ һ���Ǵ�k2��ʼѭ����   
	{   
		if(pArr[i]!=NULL)  
		{  
			if(pArr[i]->data<pArr[k1]->data )  //����±�k1��Ȩ С�ڵ�ǰ�±��Ԫ�ص�Ȩ   
			{    
				k2=k1;  //��ʱ����k1<k2�������Ƿ��صĽ��  
				k1=i ;  
			}  
			else if(pArr[i]->data<pArr[k2]->data)  
			{  
				k2=i ;  
			}  

		}      
	}  
	*x1=k1  ;  
	*x2=k2  ;  
}  
TreeNode * CreateHuffmanTree(string data[],int a[],int n)   //����a��ʾȨ������  n�Ǹ���   
{       
	TreeNode**pArr=(TreeNode**)malloc(sizeof(TreeNode*)*n);  //��̬����ָ������  
	TreeNode*p =NULL;//���ڷ��ع��������ĸ��ڵ��ָ��   
	int k1,k2 ;  //k1������СȨ  k2�����СȨ    ������Ϊ FindLittle�Ĳ���������СȨ�±�  
	cout<<"�ؼ���\t"<<"Ȩֵ\n";
	for(int i=1;i<=n;i++)  
	{  
		pArr[i]=new TreeNode ;    //Ϊ�ڵ�ָ�����鶯̬����ָ��Ķ���  
		pArr[i]->data=data[i];
		pArr[i]->weight=a[i]  ;  
		pArr[i]->lchild=pArr[i]->rchild=NULL ;//��ʼ��ÿ���ڵ�����ҽڵ㶼�ǿ�      
		cout<<pArr[i]->data<<"\t"<<pArr[i]->weight<<endl;
	}  
		///��Ϊ����������ѭ���Ĵӽڵ��������ҳ�Ȩֵ��С�������ڵ������� ����������ɾ���������ڵ�,���Ѻϲ���Ľڵ���ӵ������С�  
		for(int i=0;i<n-1;i++) //��Ϊ���ʣ��һ���ڵ����Ծͻ���ѡn-1��   
		{  
			FindLittle(&k1,&k2,pArr,n) ; //����2����СȨ�ڵ��±�   
			p=new TreeNode;   //ѭ���������pָ��Ľڵ�������յ�pRoot   
			p->weight=pArr[k1]->weight+pArr[k2]->weight  ;  
			p->lchild=pArr[k1] ;  
			p->rchild=pArr[k2] ;    

			pArr[k1]=p    ;   //���ϲ�����½ڵ㸳ֵ��pArr��С���Ǹ��±�  
			pArr[k2]=NULL ;   // ���±�����NULL, k1��k2Ҳ���Է�����������������Լ���  

		}  
		free(pArr) ;//�ͷ�ָ������    
		return p;    
}  



int main()
{
	int i,m,n,w[N+1];  
	TreeNode tc[M+1];
	string data[M];
	int a[M];
	string d;//��ʾ�û���Ҫ���ҵĹؼ���

	printf("input n = ");  
	scanf("%d",&n);
	Init(data,a,n);
	TreeNode*p=::CreateHuffmanTree(data,a,sizeof(a)/sizeof(int)) ; //����huffman��
	
	system("pause");
}