////ccf 20160901 最大波动 
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

////ccf 20160902 火车购票
//#include<iostream>
//using namespace std;
//int main()
//{
//	int a[20][5];
//	int n,count,i,j,k,t;
//	for(i=0;i<20;i++)
//	{
//		for(j=0;j<5;j++)
//			a[i][j]=5*i+j+1;	//二维数组初始化为1-100;	
//	}
//	cin>>n;
//	for(i=0;i<n;i++)
//	{
//		cin>>count;
//	//	while(count<6)
//	//	{
//			for(j=0;j<20;j++)	//每一条指令 都从第一行开始查找 
//			{
//				for(k=0;k<5;k++)
//				{
//					if(a[j][k]&&a[j][k+count-1]&&(k+count-1)<=5)	//找到相邻count个不为0的值
//					{
//						
//						for(t=k;t<=k+count-1;t++)
//						{
//							cout<<a[j][t]<<" ";	//输出并将其值清0  表示位置已经备选 
//							a[j][t]=0;
//						 } 
//						 cout<<endl; 
//						break;
//					 }
//					
//					 //当一行中不存在count个相邻的座位,则从a[j][k]开始寻找非0值输出
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
//		a[i]=5;//初始化 每行有5个空位 
//	}
//	cin>>n;
//	while(n--)
//	{
//		cin>>count;	//表示每次指令要购买的票数 
//		for(i=0;i<20;i++)
//		{
//			if(a[i]>=count)
//			 break;	//找到满足条件的行 
//		}
//		if(i<20)
//		{
//			for(t=5*i+6-a[i],j=1;j<=count;j++,t++)
//			  cout<<t<<" ";
//			cout<<endl;
//			a[i]-=count;
//		}
//		else if(i==20)	//表示所有都不存在count个相邻的座位 则从小到大输出 
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


