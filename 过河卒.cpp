/*
  https://www.luogu.com.cn/problem/P1002
1 1 1 1 1 1 1
1 0 X 1 X 1 2
1 X 0 1 1 X 2
1 1 1 M 1 1 3
1 X 1 1 0 X 3
1 1 X 1 X 0 3
1 2 2 3 3 3 6
  状态转移方程式为：a[i][j] = a[i][j-1]+a[i-1][j];
  如果从(0,0)开始
  需处理边界问题
  把第一行和第一列该赋值1的赋1,有一个点被马拦过河卒了就停止了;
*/
```
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 50;
ll a[maxn][maxn];
bool book[maxn][maxn];
int next_x[9]= {-2,-1,1,2,2,1,-1,-2};
int next_y[9]= {1,2,2,1,-1,-2,-2,-1};
int main()
{
	ios::sync_with_stdio(0);
	int x,y,horse_x,horse_y;
	cin >> x >> y >> horse_x >> horse_y;
	book[horse_x][horse_y] = true;
	for(int i=0; i<=7; i++)
	{
		if(horse_x+next_x[i]>=0&&horse_x+next_x[i]<=x&&horse_y+next_y[i]>=0&&horse_y+next_y[i]<=y)
		{
			book[horse_x+next_x[i]][horse_y+next_y[i]] = true;
		}
	}

	for(int i=0; i<=x; i++)
	{
		if(book[i][0]==0)
		{
			a[i][0] = 1;
		}
		else break;
	}
	for(int i=0; i<=y; i++)
	{
		if(book[0][i]==0)
		{
			a[0][i] = 1;
		}
		else break;
	}
	
	for(int i=1; i<=x; i++)
	{
		for(int j=1; j<=y; j++)
		{
			if(book[i][j]==0)
			{
				a[i][j] = a[i][j-1]+a[i-1][j];
			}
			else a[i][j] = 0;
		}
	}/*for(int i=0; i<=x; i++)
	{
		for(int j=0; j<=y; j++)
		{
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}*/
	cout<<a[x][y];
	return 0;
}
```
