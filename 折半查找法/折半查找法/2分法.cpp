
/*************
折半法查找 有序的插入一个元素
************/
#include<iostream>
using namespace std;
#define MAX 100
int n,x;
void main()
{	void search(int a[],int);
//	int a[15]={1,2,4,5,6,7,8,9,10,11,12,13,14,18};
//	int x;
	
	int a[MAX];
	cout<<"please input n=";
	cin>>n;
	cout<<"\nplease input number in array:";
	for(int i=0;i<n;i++)
		cin>>a[i];
	cout<<"\nplease input a num:";
	cin>>x;
	
	search(a,x);
	for(int i=0;i<n;i++)
		cout<<a[i]<<"  ";
	cout<<endl;
	system("pause");
}
void search(int a[],int x)
{
	int low=0,high=n-1,mid,t,i;
	while(low<=high){
		mid=(low+high)/2;
		if(a[mid]==x)
			break;
		else if(a[mid]<x)
			low=mid+1;
		else high=mid-1;
	}
	if(a[mid]==x&&mid!=high)//查找到 利用中间变量将值进行互换
	{
		t=a[mid];
		a[mid]=a[mid+1];
		a[mid+1]=t;
	}
	if(low>high)//未能查找得到元素
	{
		for(int i=n-1;i>high;i--)
			a[i+1]=a[i];
		a[high]=x;
	}

}
