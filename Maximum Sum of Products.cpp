/*
题目链接：https://codeforces.com/problemset/problem/1519/D
题意：反转数组内任意一段，使得a[i]*b[i]的总和最大
思路：
区间dp枚举每一段的值
d[i][j]代表i到j这个部分反转所得到的值
在最后找最大值时还需要一个前缀和的数组
*/
```
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 5000+100;
ll a[maxn],b[maxn];
ll dp[maxn][maxn];
ll sum[maxn]={0};
int main()
{
	ios::sync_with_stdio(0);
	int n;
	cin>>n;
	for(int i=1; i<=n; i++)
	{
		cin>>a[i];
	}
	for(int i=1; i<=n; i++)
	{
		cin>>b[i];
		sum[i]=a[i]*b[i]+sum[i-1];
	}
	for(int i=n-1; i>=1; i--)
	{
		for(int j=i+1; j<=n; j++)
		{
			dp[i][i]=a[i]*b[i];
			dp[i][j] = max(dp[i][j],dp[i+1][j-1]+a[i]*b[j]+a[j]*b[i]);
		}
	}

	ll res=sum[n];
	for(int i=1; i<=n; i++)
	{
		for(int j=i+1; j<=n; j++)
		{
			res=max(res,dp[i][j]+sum[i-1]+sum[n]-sum[j]);
		}
	}

	cout<<res<<endl;
	return 0;
}
```
