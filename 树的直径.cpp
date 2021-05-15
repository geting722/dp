/*

一棵树的直径就是这棵树上存在的最长路径。现在有一棵n个节点的树，现在想知道这棵树的直径包含的边的个数是多少？
如图所示的数据，这棵树的直径为(1-2-3-6-9)这条路径，包含的边的个数为4，所以答案是4。
Input
第1行：一个整数n，表示树上的节点个数。(1<=n<=100000) 第2-n行：每行有两个整数u,v,表示u与v之间有一条路径。(1<=u,v<=n)
Output
输出一个整数，表示这棵树直径所包含的边的个数。
Sample Input
10
1 2
2 3
3 4
3 5
3 6
3 7
3 10
6 8
6 9
Sample Output
4
看的题解https://www.cnblogs.com/prjruckyone/p/12236160.html
思路：可以用两次dfs和树形dp
两次dfs
方法：先从任意一点P出发，找离它最远的点Q，再从点Q出发，找离它最远的点W，W到Q的距离就是是的直径
树形dp
先通过递归的方式到叶子底部,然后通过自底向上的方式进行更新距离,找到最长路径。
也就是说，从 根节点出发,找到自己的最小辈,然后从最小辈向根节点更新,找一个最长的路径链。
只要子节点是最长的,那么我们更新到根节点时,这条链毫无疑问也就是最长的。
每次选字节点最长的那段
最后最长的和次最长的的和就是树的直径
*/
    
#include <bits/stdc++.h>
using namespace std;
vector<int > p[100005];
int book[100005],dp[100005];
int n;
int find(int x)
{
	dp[x]=0;
    int m1=0,m2=0;
    for(int i=0;i<p[x].size();i++)
	{
		int t=p[x][i];
        find(t);
        if(dp[t]+1>m1)
		{
            m2=m1;
            m1=dp[t]+1;
        }
		else if(dp[t]+1>m2)
		 m2=dp[t]+1;
    }
    dp[x]=m1;
    return m1+m2;
}
int main()
{
	scanf("%d",&n);
	int u,v;
	for(int i=1; i<n; i++)
	{
		cin>>u>>v;
		book[v]=1;
		p[u].push_back(v);
	}
	int root;
	for(int i=1; i<n; i++)
	{
		if(book[i]==0)
		{
			root=i;
			break;
		}
	}
	printf("%d",find(root));
	return 0;
	
}
