//动态规划

////状态和状态转移方程
//#include<iostream>
//using namespace std;
//void main()
//{
//	int a[3] = { 1,3,5 }, sum = 11, cent = 0;
//	int dp[12];
//
//	for (int i = 0; i <= sum; i++)
//		dp[i] = i;
//	for (int i = 1; i <= sum; i++)
//	{
//		for (int j = 0; j < 3; j++)
//		{
//			if (i >= a[j] && (dp[i -a[j]] + 1 < dp[i]))
//				dp[i] = dp[i -a[j]]+1;
//		}
//	}
//	cout << dp[sum] << endl;
//
//	system("pause");
//}

////数塔问题！
////有一个N行数字组成的三角形，设计算法计算出三角形的由顶至底的一条路径，使该路径经过的数字总和最大（或最小）
//#include<cstdio>
//#include<iostream>
//#include<algorithm>
//#include<string>
//using namespace std;
//int a[2000][2000];
//void main()
//{
//	int t, n, i, j;
//	cout << "n= ";
//	cin >> n;
//	while (n!=0)
//	{
//		for (i = 0; i < n; i++)
//			for (j = 0; j <= i; j++)
//				cin >> a[i][j];
//		for (i = n - 1; i > 0; i--)
//			for (j = 0; j < i; j++)
//			{
//			//	a[i - 1][j] += max(a[i][j], a[i][j + 1]);
//				a[i - 1][j] += min(a[i][j], a[i][j + 1]);
//
//			}
//		cout << "the max value is:" << a[0][0] << endl;
//	}
//
//	system("pause");
//}







