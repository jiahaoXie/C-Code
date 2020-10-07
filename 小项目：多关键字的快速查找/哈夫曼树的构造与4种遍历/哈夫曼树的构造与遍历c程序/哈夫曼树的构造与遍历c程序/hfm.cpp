/* 
根据Huffman树的构造原理进行构造  ...  
哈夫曼树在编码压缩的领域有很好的应用,利用Huffman进行编码可以保证数据传输 
的无二义性 。 
但是要注意的是 对于出现频率大的数据我们应该尽量放在离根节点近的地方进行编码 , 
出现频率小的数据我们可以放在距离根节点小的地方。 
这样可以提高数据的传输效率 。 
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

#define N 500         // 带编码字符的个数，即树中叶结点的最大个数  
#define M (2*N-1)    // 树中总的结点数目 

///节点声明  
typedef struct  node{  
	node *lChild ;  
	node *rChild ;  
	int data ;//权值 
	string words;
}TreeNode ;   
class Point
{
public:
	string words;
	int data;
};

TreeNode * CreateHuffmanTree(int a[],int n)  ; //数组a表示权的数组  n是个数   
void  FindLittle(int *x1,int *x2 ,TreeNode**pArr,int n)  ; //查找出2个权值最小的节点的下标   


TreeNode * CreateHuffmanTree(string words[],int a[],int n)   //数组a表示权的数组  n是个数   
{       
	TreeNode**pArr=(TreeNode**)malloc(sizeof(TreeNode*)*n);  //动态产生指针数组  
	TreeNode*p =NULL;//用于返回哈夫曼树的根节点的指针   
	int k1,k2 ;  //k1代表最小权  k2代表次小权    用于做为 FindLittle的参数查找最小权下标 
	
	for(int i=0;i<n;i++)  
	{  
		pArr[i]=new TreeNode ;    //为节点指针数组动态分配指向的对象  
		pArr[i]->words=words[i];
		pArr[i]->data=a[i]  ;  
		pArr[i]->lChild=pArr[i]->rChild=NULL ;//初始化每个节点的左右节点都是空      
		cout<<pArr[i]->words<<"--"<<pArr[i]->data<<"\t";
	}  

	///因为哈夫曼树是循环的从节点数组中找出权值最小的两个节点进行组合 并从数组中删除这两个节点,并把合并后的节点添加到数组中。  
	for(int i=0;i<n-1;i++) //因为最后还剩下一个节点所以就会挑选n-1次   
	{  
		FindLittle(&k1,&k2,pArr,n) ; //查找2个最小权节点下标   
		p=new TreeNode;   //循环组合最后的p指向的节点便是最终的pRoot   
		p->data=pArr[k1]->data+pArr[k2]->data  ;  
		p->lChild=pArr[k1] ;  
		p->rChild=pArr[k2] ;    

		pArr[k1]=p    ;   //将合并后的新节点赋值给pArr最小的那个下标  
		pArr[k2]=NULL ;   // 次下标设置NULL, k1和k2也可以反过来这个具体我们自己定  

	}  
	free(pArr) ;//释放指针数组    
	return p;    
}  


void  FindLittle(int *x1,int *x2 ,TreeNode**pArr,int n)  //查找出2个权值最小的节点的下标  
{  
	int  k1,k2;  //保存权最小的两个节点下标   
	k1=-1 ; //表示没有找到数据  
	for(int i=0;i<n;i++)    //找出其中的前两个元素不为NULL的下标  
	{    
		if(pArr[i]!=NULL&&k1==-1)  
		{  
			k1=i ;     //第一个下标  
			continue ;  
		}  
		if(pArr[i]!=NULL)   
		{  
			k2=i ;  
			break;//找到第二个下标退出循环  
		}  
	}  

	////// 最小权的2个下标的搜索实现//////////      
	for(int i=k2;i<n;i++) //我们是先获取k1  后获取k2所以一开始 一定是从k2开始循环的   
	{   
		if(pArr[i]!=NULL)  
		{  
			if(pArr[i]->data<pArr[k1]->data )  //如果下标k1的权 小于当前下标的元素的权   
			{    
				k2=k1;  //此时还是k1<k2满足我们返回的结果  
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

///哈夫曼树的先序遍历   
void PreHufOrder(TreeNode *p)   //先序遍历  
{    
	if(p!=NULL)  
	{  
		//printf("%d ",p->data) ;   
		cout<<p->words<<"--"<<p->data<<"\t";
		PreHufOrder(p->lChild);  
		PreHufOrder(p->rChild);  
	}   
}  

//中序遍历    
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
//后续遍历   
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


//清空树    
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
	// 初始化，读入待编码字符的个数n，从已有的文件中读入n个字符和n个权值 
	//首先从指定的文本中读入n个字符串
	ifstream in("G:\\研究生学习 代码\\关键字1.txt");  
    string filename;  
   // string line[50];  
	int i=1,j=1,k;
    if(in) // 有该文件  
    {  
        while (getline (in, words[i++])) // line中不包括每行的换行符  
        {   
			//cout << hc[--i].data << '\t';; 
			j++;
			if(j>=n)
				break;
        } 
		cout<<"\n一共有"<<j<<"个数,";
    }  
    else // 没有该文件  
    {  
        cout <<"no such file" << endl;  
    }  

	//随机生成对应的n个权值
	srand((unsigned)time(NULL));  
	for( k = 0; k < n;k++ ) 
	{
		a[k]=rand()%150;
		//cout << hc[k].weight<< '\t';  
	//cout << rand()/double(RAND_MAX) << '\t';
	}
			
	cout << "有"<<k<<"个权值\n";
}
//层次遍历 借助队列
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
//层序遍历 过程  
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
	int a[]={3,5,8,7,9,20,4,15,6,13,21,30} ;  //权值
	string words[]={"asac","fsafvgs","scds","fsdr","rdgs","hrth",
		"gserg","hre","hrtrh","csdfg","vfrsdegts","fvsdhgd"};*/
	int n,a[N];
	string words[N];
	cout<<"please input n=";
	cin>>n;
	Init(a,words,n);

	string x;
	TreeNode*p=::CreateHuffmanTree(words,a,n); //创建huffman树  

	printf("\nHuffman先序遍历:\n") ;  
	PreHufOrder(p) ;  //前序遍历huffmanTree  
	printf("\n");  

	printf("Huffman后序遍历:\n") ;  
	PostHufOrder(p) ;//后序遍历  
	printf("\n");

	printf("Huffman中序遍历:\n") ;  
	InHufOrder(p) ;//中序遍历  
	printf("\n");  

	cout<<"Huffman 层序遍历为："<<endl;  
    LayerOrder(p); 
	printf("\n");

	ClearHufTree(p) ;//清空树  
	system("pause");
	return  0 ;  
}  