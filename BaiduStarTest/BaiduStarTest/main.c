#include<stdio.h>
#include<iostream>
void main()
{
	int i,j,k,sum=0;
	scanf("%d",&i);
	scanf("%d",&j);
	k=i;
	while(i<=j)
	{
		sum+=i;
		i++;
	}
	printf("%d\n\n%d",k,sum);
	system("pause");
}