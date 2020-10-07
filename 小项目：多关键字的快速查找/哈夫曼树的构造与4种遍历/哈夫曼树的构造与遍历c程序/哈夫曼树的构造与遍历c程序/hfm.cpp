/* 
����Huffman���Ĺ���ԭ����й���  ...  
���������ڱ���ѹ���������кܺõ�Ӧ��,����Huffman���б�����Ա�֤���ݴ��� 
���޶����� �� 
����Ҫע����� ���ڳ���Ƶ�ʴ����������Ӧ�þ�����������ڵ���ĵط����б��� , 
����Ƶ��С���������ǿ��Է��ھ�����ڵ�С�ĵط��� 
��������������ݵĴ���Ч�� �� 
*/  
#include "stdio.h"  
#include "malloc.h"  
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

///�ڵ�����  
typedef struct  node{  
	node *lChild ;  
	node *rChild ;  
	int data ;//Ȩֵ 
	string words;
}TreeNode ;   
class Point
{
public:
	string words;
	int data;
};

TreeNode * CreateHuffmanTree(int a[],int n)  ; //����a��ʾȨ������  n�Ǹ���   
void  FindLittle(int *x1,int *x2 ,TreeNode**pArr,int n)  ; //���ҳ�2��Ȩֵ��С�Ľڵ���±�   


TreeNode * CreateHuffmanTree(string words[],int a[],int n)   //����a��ʾȨ������  n�Ǹ���   
{       
	TreeNode**pArr=(TreeNode**)malloc(sizeof(TreeNode*)*n);  //��̬����ָ������  
	TreeNode*p =NULL;//���ڷ��ع��������ĸ��ڵ��ָ��   
	int k1,k2 ;  //k1������СȨ  k2�����СȨ    ������Ϊ FindLittle�Ĳ���������СȨ�±� 
	
	for(int i=0;i<n;i++)  
	{  
		pArr[i]=new TreeNode ;    //Ϊ�ڵ�ָ�����鶯̬����ָ��Ķ���  
		pArr[i]->words=words[i];
		pArr[i]->data=a[i]  ;  
		pArr[i]->lChild=pArr[i]->rChild=NULL ;//��ʼ��ÿ���ڵ�����ҽڵ㶼�ǿ�      
		cout<<pArr[i]->words<<"--"<<pArr[i]->data<<"\t";
	}  

	///��Ϊ����������ѭ���Ĵӽڵ��������ҳ�Ȩֵ��С�������ڵ������� ����������ɾ���������ڵ�,���Ѻϲ���Ľڵ���ӵ������С�  
	for(int i=0;i<n-1;i++) //��Ϊ���ʣ��һ���ڵ����Ծͻ���ѡn-1��   
	{  
		FindLittle(&k1,&k2,pArr,n) ; //����2����СȨ�ڵ��±�   
		p=new TreeNode;   //ѭ���������pָ��Ľڵ�������յ�pRoot   
		p->data=pArr[k1]->data+pArr[k2]->data  ;  
		p->lChild=pArr[k1] ;  
		p->rChild=pArr[k2] ;    

		pArr[k1]=p    ;   //���ϲ�����½ڵ㸳ֵ��pArr��С���Ǹ��±�  
		pArr[k2]=NULL ;   // ���±�����NULL, k1��k2Ҳ���Է�����������������Լ���  

	}  
	free(pArr) ;//�ͷ�ָ������    
	return p;    
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

///�����������������   
void PreHufOrder(TreeNode *p)   //�������  
{    
	if(p!=NULL)  
	{  
		//printf("%d ",p->data) ;   
		cout<<p->words<<"--"<<p->data<<"\t";
		PreHufOrder(p->lChild);  
		PreHufOrder(p->rChild);  
	}   
}  

//�������    
void InHufOrder(TreeNode*p)  
{  
	if(p!=NULL)  
	{  
		InHufOrder(p->lChild) ;  
		cout<<p->words<<"--"<<p->data<<"\t";
		//printf("%d ",p->data) ;  
		InHufOrder(p->rChild) ;  
	}  
}  
//��������   
void PostHufOrder(TreeNode*p)  
{  
	if(p!=NULL)  
	{  
		InHufOrder(p->lChild) ;  
		InHufOrder(p->rChild) ;  
		cout<<p->words<<"--"<<p->data<<"\t";
		//printf("%d ",p->data) ;  
	}  
}  


//�����    
void ClearHufTree(TreeNode*p)  
{  
	if(p!=NULL)  
	{  
		ClearHufTree(p->lChild) ;  
		ClearHufTree(p->rChild) ;  
		delete p ;  
	}  
}  
void Init(int a[],string words[],int n)
{
	// ��ʼ��������������ַ��ĸ���n�������е��ļ��ж���n���ַ���n��Ȩֵ 
	//���ȴ�ָ�����ı��ж���n���ַ���
	ifstream in("G:\\�о���ѧϰ ����\\�ؼ���1.txt");  
    string filename;  
   // string line[50];  
	int i=1,j=1,k;
    if(in) // �и��ļ�  
    {  
        while (getline (in, words[i++])) // line�в�����ÿ�еĻ��з�  
        {   
			//cout << hc[--i].data << '\t';; 
			j++;
			if(j>=n)
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
	for( k = 0; k < n;k++ ) 
	{
		a[k]=rand()%150;
		//cout << hc[k].weight<< '\t';  
	//cout << rand()/double(RAND_MAX) << '\t';
	}
			
	cout << "��"<<k<<"��Ȩֵ\n";
}
//��α��� ��������
typedef struct lNode  
{  
    TreeNode *data;  
    struct lNode *next;  
}LNode;  
  
  
typedef struct lQueue  
{  
    LNode *front;  
    LNode *rear;  
}LQueue;  
  
  
void Initiate_Queue(LQueue *Q)  
{  
    Q->front=NULL;  
    Q->rear=NULL;  
}  
  
void AppendQueue(LQueue *Q,TreeNode *head)  
{  
    LNode *p1;  
    p1=(LNode *)malloc(sizeof(LNode));  
    p1->next=NULL;  
    p1->data=head;  
    if(Q->front==NULL)  
    {  
        Q->front=Q->rear=p1;  
    }  
    else  
    {  
        Q->rear->next=p1;  
        Q->rear=p1;  
    }  
}  
  
TreeNode * QueueDelete(LQueue *Q)  
{  
    if(Q->front==NULL) return NULL;  
    else  
    {  
        TreeNode *p;  
        p=Q->front->data;  
        Q->front=Q->front->next;  
        return p;  
    }  
}  
  
int QueueNotEmpty(LQueue *Q)  
{  
    if(Q->front==NULL) return 0;  
    else return 1;  
}  
//������� ����  
void LayerOrder(TreeNode*pt)  
{  
    LQueue Q;  
    Initiate_Queue(&Q);  
    TreeNode *p;  
    if(pt!=NULL) AppendQueue(&Q,pt);  
    while(QueueNotEmpty(&Q))  
    {  
        p=QueueDelete(&Q);  
        //cout<<p->data<<"  ";  
        cout<<p->words<<"--"<<p->data<<"\t";
		if(p->lChild!=NULL) AppendQueue(&Q,p->lChild);  
        if(p->rChild!=NULL) AppendQueue(&Q,p->rChild);      
    }  
}  
  
int main()  
{  
	/*
	int a[]={3,5,8,7,9,20,4,15,6,13,21,30} ;  //Ȩֵ
	string words[]={"asac","fsafvgs","scds","fsdr","rdgs","hrth",
		"gserg","hre","hrtrh","csdfg","vfrsdegts","fvsdhgd"};*/
	int n,a[N];
	string words[N];
	cout<<"please input n=";
	cin>>n;
	Init(a,words,n);

	string x;
	TreeNode*p=::CreateHuffmanTree(words,a,n); //����huffman��  

	printf("\nHuffman�������:\n") ;  
	PreHufOrder(p) ;  //ǰ�����huffmanTree  
	printf("\n");  

	printf("Huffman�������:\n") ;  
	PostHufOrder(p) ;//�������  
	printf("\n");

	printf("Huffman�������:\n") ;  
	InHufOrder(p) ;//�������  
	printf("\n");  

	cout<<"Huffman �������Ϊ��"<<endl;  
    LayerOrder(p); 
	printf("\n");

	ClearHufTree(p) ;//�����  
	system("pause");
	return  0 ;  
}  