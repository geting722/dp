/*
题目链接：https://www.luogu.com.cn/problem/P1434
思路：记忆化搜索
遇到比目前的最大值还小的就停止搜索
f[i][j]表示i到j的最大值
*/
```
#include <bits/stdc++.h>
using namespace std;
int a,b,f[110][110],s[110][110],ans=1;
const int dx[5]= {0,0,0,1,-1},dy[5]= {0,1,-1,0,0};
void dfs(int x,int y,int cnt) {
	if(cnt<=f[x][y]) 
		return;
	f[x][y]=cnt;
	ans=max(ans,cnt);
	for(int k=1; k<=4; k++) {
		int p=x+dx[k],q=y+dy[k];
		if(s[p][q]<s[x][y]&&p&&p<=a&&q&&q<=b)
			dfs(p,q,cnt+1);
	}
}
int main() {
	cin>>a>>b;
	for(int i=1; i<=a; i++)
		for(int j=1; j<=b; j++)
			cin>>s[i][j];
	for(int i=1; i<=a; i++)
		for(int j=1; j<=b; j++)
			dfs(i,j,1);
	cout<<ans;
	return 0;
}
```
