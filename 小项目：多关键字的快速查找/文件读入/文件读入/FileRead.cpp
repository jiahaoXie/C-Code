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

class HTNode{        // 树中结点的结构  
public:   
	unsigned int weight;  
	unsigned int parent,lchild,rchild;  
};                      

class HTCode{  
public:  
	//char data[M];      // 待编码的字符  
	string data;
	int weight;     // 字符的权值  
	char code[N];   // 字符的编码  
};

void Init(HTCode hc[],int n)
{  
	// 初始化，读入待编码字符的个数n，从已有的文件中读入n个字符和n个权值 
	//首先从指定的文本中读入n个字符串
	ifstream in("G:\\研究生学习 代码\\关键字1.txt");  
    string filename;  
   // string line[50];  
	int i=1,j=1,k;
    if(in) // 有该文件  
    {  
        while (getline (in, hc[i++].data)) // line中不包括每行的换行符  
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
		hc[k].weight=rand()%150;
		//cout << hc[k].weight<< '\t';  
	//cout << rand()/double(RAND_MAX) << '\t';
	}
			
	cout << "有"<<k<<"个权值\n";

    
} 

void Select(HTNode ht[], int k, int *s1, int *s2){  
// ht[1...k]中选择parent为0，并且weight最小的两个结点，其序号由指针变量s1，s2指示  
    int i;  
    for(i=1; i<=k && ht[i].parent != 0; ++i){   
        ; ;  
    }  
    *s1 = i;  
  
    for(i=1; i<=k; ++i){  
        if(ht[i].parent==0 && ht[i].weight<ht[*s1].weight)  
            *s1 = i;  
    }  
  
    for(i=1; i<=k; ++i){  
        if(ht[i].parent==0 && i!=*s1)  
            break;  
    }  
    *s2 = i;  
  
    for(i=1; i<=k; ++i){  
        if(ht[i].parent==0 && i!=*s1 && ht[i].weight<ht[*s2].weight)  
            *s2 = i;  
    }  
}  

void HuffmanCoding(HTNode ht[],HTCode hc[],int n){  
// 构造Huffman树ht，并求出n个字符的编码  
    char cd[N];  
    int i,j,m,c,f,s1,s2,start;  
    m = 2*n-1;  
      
    for(i=0; i<=m; ++i){  
        if(i <= n)  
            ht[i].weight = hc[i].weight;  //编码中前n个节点的权值等于本身
										 //哈夫曼树总的节点数为2n-1（后面生成n-1个）
      //  else  
       //     ht[i].parent = 0;  
        ht[i].parent = ht[i].lchild = ht[i].rchild = 0;  
    }  
  
    for(i=n+1; i<=m; ++i){  
        Select(ht, i-1, &s1, &s2);  
        ht[s1].parent = i;  
        ht[s2].parent = i;  
        ht[i].lchild = s1;  
        ht[i].rchild = s2;  
        ht[i].weight = ht[s1].weight+ht[s2].weight;  
    }  
  
    cd[n-1] = '\0';  
  
    for(i=1; i<=n; ++i){  
        start = n-1;  
        for(c=i,f=ht[i].parent; f; c=f,f=ht[f].parent){  
            if(ht[f].lchild == c)  
                cd[--start] = '0';  
            else  
                cd[--start] = '1';  
        }  
        strcpy(hc[i].code, &cd[start]);  
    }  
}  

int main()  
{  
	int i,m,n,w[N+1];  
	HTNode ht[M+1];  
	HTCode hc[N+1]; 
	string d;//表示用户想要查找的关键字

	printf("input n = ");  
	scanf("%d",&n);
	Init(hc,n);     // 初始化
	for(i=1;i<=n;i++)
	{
		cout<<hc[i].data<<"\t"<<hc[i].weight<<endl;
	}
	HuffmanCoding(ht,hc,n);   // 构造Huffman树，并形成字符的编码 

	 printf("经过哈夫曼树编码后：\nwords\tweight code\n");
    for(i=1; i<=n; ++i)
	{
		cout<<hc[i].data<<'\t'<<hc[i].weight<<'\t'<<hc[i].code<<endl;
		
	}



	printf("\n");
	system("pause");
	return 0; 
} 
 

 