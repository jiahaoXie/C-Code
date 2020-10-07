#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;
/*
void main()
{
	int A[15]={0,1,2,3,4,5,6,7,8,9,10,11,12,13,14};
	int m=10,n=5;
//1 for—≠ª∑
	for(int j=m;j<m+n;){
		for(int i=j-1;i>=j-m;i--){
			A[i+1]=A[i];
		}
		A[j-m]=A[j];
		j++;
	}
	//2 while—≠ª∑
	int j=m;
	while(j<m+n){
		for(int i=j-1;i>=j-m;i--){
			A[i+1]=A[i];
		}
		A[j-m]=A[j++];
		//j++;
	}
	
	for(int i=0;i<15;i++){
		cout<<A[i]<<"\t";
	}
	cout<<endl;
	system("pause");
}
*/
#define MAX 50
void main()
{
	void Reverse(int a[],int start,int end);
	int a[MAX],m,n,k;
	cout<<"please input k=";
	cin>>k;
	cout<<"\nplease input"<<k<<"numbers in array\n";
	srand((unsigned)time(NULL));  
	for( int i = 0; i < k;i++ )  
	{
		a[i]=rand()%150;
		cout<<a[i]<<"  ";
	}
	cout<<endl;
	 Reverse(a, 0, k-1);
	 for(int i=0;i<k;i++)
		 cout<<a[i]<<" ";
	 cout<<endl;
	 Reverse(a, 0, k/3-1);
	 
	 Reverse(a, k/3-1, k-1);
	 for(int i=0;i<k;i++)
		 cout<<a[i]<<" ";
	  cout<<endl;
	 system("pause");



}
void Reverse(int a[],int start,int end)
{
	int i,t;
	for(i=0;i<(end-start+1)/2;i++)
	{
		t=a[start+i];a[start+i]=a[end-i];a[end-i]=t;
	}
}
