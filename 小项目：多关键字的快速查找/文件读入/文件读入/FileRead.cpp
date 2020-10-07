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

class HTNode{        // ���н��Ľṹ  
public:   
	unsigned int weight;  
	unsigned int parent,lchild,rchild;  
};                      

class HTCode{  
public:  
	//char data[M];      // ��������ַ�  
	string data;
	int weight;     // �ַ���Ȩֵ  
	char code[N];   // �ַ��ı���  
};

void Init(HTCode hc[],int n)
{  
	// ��ʼ��������������ַ��ĸ���n�������е��ļ��ж���n���ַ���n��Ȩֵ 
	//���ȴ�ָ�����ı��ж���n���ַ���
	ifstream in("G:\\�о���ѧϰ ����\\�ؼ���1.txt");  
    string filename;  
   // string line[50];  
	int i=1,j=1,k;
    if(in) // �и��ļ�  
    {  
        while (getline (in, hc[i++].data)) // line�в�����ÿ�еĻ��з�  
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
		hc[k].weight=rand()%150;
		//cout << hc[k].weight<< '\t';  
	//cout << rand()/double(RAND_MAX) << '\t';
	}
			
	cout << "��"<<k<<"��Ȩֵ\n";

    
} 

void Select(HTNode ht[], int k, int *s1, int *s2){  
// ht[1...k]��ѡ��parentΪ0������weight��С��������㣬�������ָ�����s1��s2ָʾ  
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
// ����Huffman��ht�������n���ַ��ı���  
    char cd[N];  
    int i,j,m,c,f,s1,s2,start;  
    m = 2*n-1;  
      
    for(i=0; i<=m; ++i){  
        if(i <= n)  
            ht[i].weight = hc[i].weight;  //������ǰn���ڵ��Ȩֵ���ڱ���
										 //���������ܵĽڵ���Ϊ2n-1����������n-1����
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
	string d;//��ʾ�û���Ҫ���ҵĹؼ���

	printf("input n = ");  
	scanf("%d",&n);
	Init(hc,n);     // ��ʼ��
	for(i=1;i<=n;i++)
	{
		cout<<hc[i].data<<"\t"<<hc[i].weight<<endl;
	}
	HuffmanCoding(ht,hc,n);   // ����Huffman�������γ��ַ��ı��� 

	 printf("�����������������\nwords\tweight code\n");
    for(i=1; i<=n; ++i)
	{
		cout<<hc[i].data<<'\t'<<hc[i].weight<<'\t'<<hc[i].code<<endl;
		
	}



	printf("\n");
	system("pause");
	return 0; 
} 
 

 