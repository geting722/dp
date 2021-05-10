/*
  https://www.luogu.com.cn/problem/P1216
  思路：从下往上递推，因为是金字塔，所以最后最上面的元素是和最大的路径值。
核心代码：a[i][j] += max(a[i+1][j],a[i+1][j+1]);
https://blog.csdn.net/weixin_51793146/article/details/116550057?spm=1001.2014.3001.5501
*/
```
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4+100;
int dp[maxn][maxn];
int a[maxn][maxn];
int main()
{
	int r;
	cin>>r;
	for(int i=1; i<=r; i++)
	{
		for(int j=1; j<=i; j++)
		{
			cin>>a[i][j];
		}
		
	}
	for(int i=r-1; i>=1; i--)
	{
		for(int j=1; j<=i; j++)
		{
			a[i][j] += max(a[i+1][j],a[i+1][j+1]);
		}
	}
	cout<<a[1][1];
	return 0;
}

```
