////ccf 20160901 ��󲨶� 
//#include<iostream>
//using namespace std;
//
//
//int fabs(int n)
//{
//	return (n>=0)?n:-n;
// } 
// int main()
// {
// 	int a[1000];
// 	int n,i,t1=0,t2=0;
// 	cin>>n;
// 	for(i=0;i<n;i++)
// 	{
// 		cin>>a[i];
//	 }
//  	for(i=0;i<n-1;i++)
// 	{
// 		if(i=0)
// 		{
// 			t1=t2=fabs(a[i]-a[i+1]);
//		 }
//		 else 
//		 {
//		 	t2=fabs(a[i]-a[i+1]);
//		 	if(t2>t1)
//		 	{
//		 		t1=t2;
//			 }
//		 		
//		 }
// 		
//	 }
//	cout<<t1<<endl;
// 	return 0;
// }

////ccf 20160902 �𳵹�Ʊ
//#include<iostream>
//using namespace std;
//int main()
//{
//	int a[20][5];
//	int n,count,i,j,k,t;
//	for(i=0;i<20;i++)
//	{
//		for(j=0;j<5;j++)
//			a[i][j]=5*i+j+1;	//��ά�����ʼ��Ϊ1-100;	
//	}
//	cin>>n;
//	for(i=0;i<n;i++)
//	{
//		cin>>count;
//	//	while(count<6)
//	//	{
//			for(j=0;j<20;j++)	//ÿһ��ָ�� ���ӵ�һ�п�ʼ���� 
//			{
//				for(k=0;k<5;k++)
//				{
//					if(a[j][k]&&a[j][k+count-1]&&(k+count-1)<=5)	//�ҵ�����count����Ϊ0��ֵ
//					{
//						
//						for(t=k;t<=k+count-1;t++)
//						{
//							cout<<a[j][t]<<" ";	//���������ֵ��0  ��ʾλ���Ѿ���ѡ 
//							a[j][t]=0;
//						 } 
//						 cout<<endl; 
//						break;
//					 }
//					
//					 //��һ���в�����count�����ڵ���λ,���a[j][k]��ʼѰ�ҷ�0ֵ���
//					  
//				}
//						 
//				break;
//				
//			}
//		
//			 
//	//	}
//	}
//	return 0;
// } 

//#include<iostream>
//using namespace std;
//
//int main()
//{
//	int a[20];
//	int n,count,i,j,t;
//	for(i=0;i<20;i++)
//	{
//		a[i]=5;//��ʼ�� ÿ����5����λ 
//	}
//	cin>>n;
//	while(n--)
//	{
//		cin>>count;	//��ʾÿ��ָ��Ҫ�����Ʊ�� 
//		for(i=0;i<20;i++)
//		{
//			if(a[i]>=count)
//			 break;	//�ҵ������������� 
//		}
//		if(i<20)
//		{
//			for(t=5*i+6-a[i],j=1;j<=count;j++,t++)
//			  cout<<t<<" ";
//			cout<<endl;
//			a[i]-=count;
//		}
//		else if(i==20)	//��ʾ���ж�������count�����ڵ���λ ���С������� 
//		{
//			for(j=0;j<20;j++)
//			{
//				if(a[j]==0)  continue;
//				while(count--&&a[j]--)
//					cout<<5*j+5-a[j]<<" ";
//				 
//			}
//			cout<<endl;
//		}
//	}
//}


