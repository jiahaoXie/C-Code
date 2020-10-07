//#include<stdio.h>  
//#include<algorithm>  
//#include<string.h>  
//using namespace std;
//#define __int64 long long  
//const int maxm = 1000005;
//const __int64 INF = 1e15;
//struct node
//{
//	int h;
//	__int64 w;
//	bool operator<(const node &r)const
//	{
//		return w < r.w;
//	}
//}f[20005];
//int a[20005][15] = { 0 }, n, m, p[maxm];
//__int64 dp[2005], k[maxm];
//void find(int cnt);
//int main()
//{
//	int i, j, sum, x, y, r, flag, cnt;
//	__int64 ans, rev, xx;
//	while (scanf_s("%d%d", &n, &m) != EOF)
//	{
//		memset(a, 0, sizeof(a));
//		for (i = 1; i <= n; i++)
//		{
//			scanf_s("%d%d", &x, &y);
//			a[x][y]++;
//		}
//		for (i = 1; i <= m; i++)
//			scanf_s("%I64d%d", &k[i], &p[i]);
//		flag = 1; ans = 0;
//		for (j = 0; j <= 10; j++)
//		{
//			cnt = 0;
//			for (r = 1; r <= m; r++)
//			{
//				if (p[r] - j <= 0) continue;
//				f[++cnt].h = p[r] - j;
//				f[cnt].w = k[r];
//			}
//			find(cnt);
//			rev = INF;
//			for (i = 1000; i >= 1; i--)
//			{
//				rev = min(rev, dp[i]);
//				if (a[i][j] > 0)
//				{
//					if (rev == INF) { flag = 0; break; }
//					ans += (__int64)(rev*a[i][j]);
//				}
//			}
//			if (flag == 0) break;
//		}
//		if (flag == 0) printf("-1\n");
//		else printf("%I64d\n", ans);
//	}
//	return 0;
//}
//void find(int cnt)
//{
//	memset(dp, 1, sizeof(dp));
//	for (int i = 1; i <= cnt; i++)
//		dp[f[i].h] = min(dp[f[i].h], f[i].w);
//	for (int i = 1; i <= 1000; i++)
//	{
//		for (int j = 1; j <= cnt; j++)
//		{
//			dp[i + f[j].h] = min(dp[i + f[j].h], dp[i] + f[j].w);
//			if (i + f[j].h >= 1000) dp[1000] = min(dp[1000], dp[i + f[j].h]);
//		}
//	}
//}

//Input:
//2 1
//1 2 1

//3 3
//1 2 5
//1 2 4
//2 3 3
//Output:
//1
//3


#include<stdio.h>
int main()
{
	int n, m;

	while (scanf_s("%d%d", &n, &m) != NULL)
	{
		int min, j[10000];
		for (int i = 0; i < n; i++) {
			int u, v, w;
			scanf_s("%d%d%d",&u,&v,&w);
			j[i] = w;
		}
		min = j[0];
		for (int i = 1; i < n; i++)
		{
			if (min > j[i])
				min = j[i];
		}
		printf("%d\n", min);

	}
	return 0;
}