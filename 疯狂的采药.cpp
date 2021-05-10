/*
https://www.luogu.com.cn/problem/P1616
完全背包的模板
把第二个for改下就行
*/
```
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int maxn = 1e7+100;
ll dp[maxn];
ll Time[maxn];
ll value[maxn];
int main()
{
	ios::sync_with_stdio(0);
	ll t,m;
	cin>>t>>m;
	for(int i=1; i<=m; i++)
	{
		cin>>Time[i]>>value[i];
	}
	for(int i=1; i<=m; i++)
	{
		for(int j=Time[i]; j<=t; j++)
		{
			dp[j] = max(dp[j], dp[j-Time[i]]+value[i]);
		}
	}
	cout<<dp[t];
	return 0;
 } 
```
