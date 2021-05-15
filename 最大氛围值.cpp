/*
有个公司要举行一场晚会。为了让到会的每个人不受他的直接上司约束而能玩得开心，公司领导决定：如果邀请了某个人，
那么一定不会再邀请他的直接的上司，但该人的上司的上司，上司的上司的上司……都可以邀请。已知每个人最多有唯一的一个上司。
已知公司的每个人参加晚会都能为晚会增添一些气氛，求一个邀请方案，使气氛值的和最大。
注意包含多组输入
第1行一个整数N表示公司的人数。
接下一行N个整数。第i行的数表示第i个人的气氛值x（-128<=x<=127）
接N-1下来每行两个整数L,K。表示第K个人是第L个人的上司。
输入以两个0结尾
Output
一个数，最大的气氛值和。
Sample Input
7
1
1
1
1
1
1
1
1 3
2 3
6 4
7 4
4 5
3 5
0 0
Sample Output
5
思路：树状dp入门
树形dp的主要实现形式是dfs，在dfs中dp，dp[i][2],0表示不选，1表示选；
选择节点类的状态转移式：
dp[i][0]=dp[j][1]
dp[i][1]=max/min(dp[j][0],dp[j][1])

*/

#include <bits/stdc++.h>
using namespace std;
const int maxn = 6000 + 100;
vector <int > p[maxn];
int dp[maxn][2];
int book[maxn];
int a[maxn];
int n,root;

void dfs(int node)
{
	int len=p[node].size();
	dp[node][1]=a[node];
	for(int i=0; i<len; i++)
	{
		int v=p[node][i];
		dfs(v);
		dp[node][1]+=dp[v][0];
		dp[node][0]+=max(dp[v][1],dp[v][0]);
	}
}
int main()
{
	while(cin>>n)
	{
		for(int i=1; i<=n; i++)
		{
			dp[i][1]=dp[i][0]=0;
			book[i]=0;
			p[i].clear();
		}
		for(int i=1; i<=n; i++)
			cin>>a[i];
		for(int i=1; i<n; i++)
		{
			int v,u;
			cin>>v>>u;
			book[v]=u;
			p[u].push_back(v);
		}
		int end1,end2;
		cin>>end1>>end2;
		for(int i=1; i<=n; i++)
		{
			if(!book[i])
			{
				root=i;
				break;
			}
		}
		dfs(root);
		cout<<max(dp[root][1],dp[root][0])<<endl;
	}
	return 0;
}
