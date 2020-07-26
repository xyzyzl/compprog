#include <bits/stdc++.h>

using namespace std;

string nums[10] = { "1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011" };
int dist[2005][10], dp[2005][2005];
int main()
{
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < n; i++)
	{
		string cur;
		cin >> cur;
		for(int j = 0; j < 10; j++)
		{
			for(int i2 = 0; i2 < 7; i2++)
			{
				if(cur[i2] == '0' && nums[j][i2] == '1') dist[i][j]++;
				else if(cur[i2] == '1' && nums[j][i2] == '0') 
				{
					dist[i][j] = 998244353;
					break;
				}
			}
		}
	}
	dp[n][0] = 1;
	for(int i = n; i > 0; i--)
	{
		for(int j = 0; j <= m; j++)
		{
			if(dp[i][j])
			{
				for(int k = 0; k < 10; k++)
				{
					if(dist[i-1][k] > 1000)  continue;
					if(dist[i-1][k] + j > m) continue;
					dp[i-1][j + dist[i-1][k]] = 1;
				}
			}
		}
	}
	if(dp[0][m] == 0)
	{
		cout << -1 << endl;
		return 0;
	}
	int k = m;
	for(int i = 0; i < n; i++)
	{
		int cur = -1;
		for(int j = 9; j >= 0; j--)
		{
			if(dist[i][j] > 1000 || dist[i][j] > k || !dp[i+1][k - dist[i][j]])
				continue;
			cur = j;
			k -= dist[i][j];
			break;
		}
		if(cur == -1) return 1;
		cout << cur;
	}
	cout << endl;
}
