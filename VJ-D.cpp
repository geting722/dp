/*
给定一个字符串S，字符串S的长度为M(M≤2000)，字符串S所含有的字符的种类的数量为N(N≤26)，然后给定这N种字符Add与Delete的代价，求将S变为回文串的最小代价和。
Input
第一行：两个由空格分隔的整数 N 和 M
第二行：这一行给出了恰好 M 个字符，表示初始状态下的ID字符串
接下来的 N 行：每一行给出了由空格分隔的三部分。首先是一个字符，保证出现在了输入的字符串中。接下来是两个整数，表示你增添这个字符的代价，然后是删除这个字符的代价
Output
你只需要输出一行，且只输出一个整数。表示你将给定字符串变成回文串所需的最小代价。

思路：删除字符和在对应位置添加字符的效果是一样的，所以只需保留删除和增加的最小值
d[i][j]表示i到j的最小代价
因为求的是最小代价，所以要初始化inf
状态转移方程为
d[i][j]=min(d[i+1][j]+a[s[i]],d[i][j-1]+a[s[j]]);
d[i][j]=min(d[i][j],d[i+1][j-1]);
*/

```
#include <iostream>
#include <algorithm>
using namespace std;
const int inf = 99999999;
int d[2005][2005],a[2005];
int n,m;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	char s[2005];
	cin>>n>>m>>s+1;
	for(int i=1; i<=n; i++)
	{
		int t,t1;
		char ch;
		cin>>ch>>t>>t1;
		a[ch]=min(t,t1);
	}
	for(int len=1; len<m; len++)
		for(int i=1; i+len<=m; i++)
		{
			int j=i+len;
			d[i][j]=inf;
			d[i][j]=min(d[i+1][j]+a[s[i]],d[i][j-1]+a[s[j]]);
			if(s[i]==s[j])
				d[i][j]=min(d[i][j],d[i+1][j-1]);
		}
		cout<<d[1][m];
	return 0;
}
```
