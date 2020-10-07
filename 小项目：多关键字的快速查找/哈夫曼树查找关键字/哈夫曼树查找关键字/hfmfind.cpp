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

class TreeNode
{
public:
	string data;
	int weight;     // 字符的权值  
	char code[N];   // 字符的编码
	TreeNode *lchild,*rchild;
};

void Init(string data[],int a[],int n)
{  
	// 初始化，读入待编码字符的个数n，从已有的文件中读入n个字符和n个权值 
	//首先从指定的文本中读入n个字符串
	ifstream in("E:\\研究生学习\\关键字1.txt");  
	string filename;  
	// string line[50];  
	int i=1,j=1,k;
	if(in) // 有该文件  
	{  
		while (getline (in, data[i++])) // line中不包括每行的换行符  
		{   
			//cout << hc[--i].data << '\t';; 
			j++;
			if(j>n)
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
	for( k = 1; k <= n;k++ ) 
	{
		a[k]=rand()%150;
		//cout << hc[k].weight<< '\t';  
		//cout << rand()/double(RAND_MAX) << '\t';
	}

	cout << "有"<<k<<"个权值\n";


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
TreeNode * CreateHuffmanTree(string data[],int a[],int n)   //数组a表示权的数组  n是个数   
{       
	TreeNode**pArr=(TreeNode**)malloc(sizeof(TreeNode*)*n);  //动态产生指针数组  
	TreeNode*p =NULL;//用于返回哈夫曼树的根节点的指针   
	int k1,k2 ;  //k1代表最小权  k2代表次小权    用于做为 FindLittle的参数查找最小权下标  
	cout<<"关键字\t"<<"权值\n";
	for(int i=1;i<=n;i++)  
	{  
		pArr[i]=new TreeNode ;    //为节点指针数组动态分配指向的对象  
		pArr[i]->data=data[i];
		pArr[i]->weight=a[i]  ;  
		pArr[i]->lchild=pArr[i]->rchild=NULL ;//初始化每个节点的左右节点都是空      
		cout<<pArr[i]->data<<"\t"<<pArr[i]->weight<<endl;
	}  
		///因为哈夫曼树是循环的从节点数组中找出权值最小的两个节点进行组合 并从数组中删除这两个节点,并把合并后的节点添加到数组中。  
		for(int i=0;i<n-1;i++) //因为最后还剩下一个节点所以就会挑选n-1次   
		{  
			FindLittle(&k1,&k2,pArr,n) ; //查找2个最小权节点下标   
			p=new TreeNode;   //循环组合最后的p指向的节点便是最终的pRoot   
			p->weight=pArr[k1]->weight+pArr[k2]->weight  ;  
			p->lchild=pArr[k1] ;  
			p->rchild=pArr[k2] ;    

			pArr[k1]=p    ;   //将合并后的新节点赋值给pArr最小的那个下标  
			pArr[k2]=NULL ;   // 次下标设置NULL, k1和k2也可以反过来这个具体我们自己定  

		}  
		free(pArr) ;//释放指针数组    
		return p;    
}  



int main()
{
	int i,m,n,w[N+1];  
	TreeNode tc[M+1];
	string data[M];
	int a[M];
	string d;//表示用户想要查找的关键字

	printf("input n = ");  
	scanf("%d",&n);
	Init(data,a,n);
	TreeNode*p=::CreateHuffmanTree(data,a,sizeof(a)/sizeof(int)) ; //创建huffman树
	
	system("pause");
}