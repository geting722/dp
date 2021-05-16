/*

一条直线上摆放着一行共n堆的石子。现要将石子有序地合并成一堆。规定每次只能选相邻的两堆合并成新的一堆，并将新的一堆石子数记为该次合并的得分。请编辑计算出将n堆石子合并成一堆的最小得分和将n堆石子合并成一堆的最大得分。
Input
输入有多组测试数据。

每组第一行为n(n<=100)，表示有n堆石子，。

二行为n个用空格隔开的整数，依次表示这n堆石子的石子数量ai（0<ai<=100）

Output
每组测试数据输出有一行。输出将n堆石子合并成一堆的最小得分和将n堆石子合并成一堆的最大得分。 中间用空格分开。
Sample Input
3

1 2 3

Sample Output
9 11

思路：区间dp的板子题
dp[i][j] 表示i到j的最小或最大分数
sum[i]表示前i堆的和
第一层枚举长度
第二层枚举起点
第三层枚举分裂点
状态转移方程为dp[j][end]=max(dp[j][end],dp[j][k]+dp[k+1][end]+sum[end]-sum[j-1])
*/
#include <bits/stdc++.h>
using namespace std;
const int inf = 99999999;
int dp1[200][200];
int dp2[200][200];
int sum[200];
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		memset(dp2,0,sizeof dp2);
		memset(dp1,111,sizeof(dp1));
		for(int i=1; i<=n; i++)
		{
			int t;
			cin>>t;
			sum[i]=sum[i-1]+t;
			dp1[i][i]=0;
			dp2[i][i]=0;
		}
		for(int i=2; i<=n; i++)
			for(int j=1; j<=n&&j+i-1<=n; j++)
			{
				int end=j+i-1;
				for(int k=j; k<end; k++)
				{
					dp1[j][end]=min(dp1[j][end],dp1[j][k]+dp1[k+1][end]+sum[end]-sum[j-1]);
					dp2[j][end]=max(dp2[j][end],dp2[j][k]+dp2[k+1][end]+sum[end]-sum[j-1]);
				}
			}
		cout<<dp1[1][n]<<" "<<dp2[1][n]<<endl;
	}
	return 0;
}
