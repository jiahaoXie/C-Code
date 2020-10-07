#include<iostream>
using namespace std;
const int MAX = 1000;
int a[MAX],flag[MAX];
int main()
{
	int n;
	int i, t, count = 0;
	cin >> n;
	

	for (i = 0; i<n; i++)
	{
		if (i = 0)
			cin >> a[i];
		else {
			cin >> t;
			if (t != a[i - 1])
				a[i] = t;
		}
	}

	for (i = 0; i<n; i++)
		cout << a[i] << " ";
	cout << endl;
	//	//用flag数组来存储每一段的上升或下降情况 
	//	for(i=0;i<n-1;i++)
	//	{
	//		if(a[i]>a[i+1])
	//			flag[i]=1;
	//		else flag[i]=-1;
	//	}
	//	for(i=0;i<n-2;i++)
	//	{
	//		if(flag[i]!=flag[i+1])
	//			count++;
	//	}
	//	cout<<count<<endl;
	system("pause");
	return 0;
}