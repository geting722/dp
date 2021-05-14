/*
　zuojiliuchang与yejinmingcuc在玩一个游戏。

　　他们先各自写下一串字符，然后互相展示。展示过后，他们再从自己写的那串字符中依次挑出若干字符（保持原有顺序不变），组成新的一串。他们希望自己新组成的字符串与对方新组成的完全相同，并且尽可能长。

　　例如，zuojiliuchang写下abcde，yejinmingcuc写下aeiou，然后zuojiliuchang挑出自己那串里的第1和第5个字符组成新串ae，yejinmingcuc挑出自己那串中的第1、2个字符，也组成字符串ae。ae就是他们能共同挑出的最长串。

　　现在，zuojiliuchang和yejinmingcuc分别写出了自己的字符串，请帮他们算一下他们能共同挑出组成的字符串最长有多长。
  
  思路：最长子序列
  状态转移方程为
  c[i][j] = c[i-1][j-1]+1 (i>0,j>0,x1==x2)
  c[i][j] = max(c[i][j-1],c[i-1][j]), (i>0,j>0,x1!=x2)
  */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[2001][2001];
int main() {
	string 	a,b;
	while(cin>>a>>b)
	{
		int cnt = 0;
		int len_a = a.length();
		int len_b = b.length();
		for(int i=1; i<=len_a; i++)
		for(int j=1; j<=len_b; j++)
		{
			if(a[i-1]==b[j-1])
			dp[i][j] = dp[i-1][j-1]+1;
			else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
		}
		cout<<dp[len_a][len_b]<<endl;;
	} 
	return 0;
}
