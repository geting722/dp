/*
数列 
a
 から好きな整数を好きなだけ取り除き、単調増加な数列を作るとき、その数列の長さの最大値を求めなさい。

制約
1
≤
N
≤
100
,
000
入力例 1
5
3 1 5 4 2
出力例 1
2
*/
思路：最长上升子序列
o(n^2)过不了
这里需用到二分
dp[i]表示长度为i的LIS结尾元素的最小值
```
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5+100;
ll a[maxn];
ll dp[maxn];
int main() {
	int n;
	cin>>n;
	for(int i=1; i<=n; i++) {
		scanf("%d",a+i);
	}
	dp[1]=a[1];
	int cnt=1;
	for(int i=2; i<=n; i++) {
			if(a[i]>dp[cnt])
				dp[++cnt]=a[i];
				else {
					int mid=lower_bound(dp+1,dp+cnt+1,a[i])-dp;
					dp[mid]=a[i];
				}
	}
	/*ll maxx = 0;
	for(int i=1; i<=n; i++)
		if(maxx<dp[i])
			maxx=dp[i];
	cout<<maxx;*/
	cout<<cnt;
	return 0;
}
```
