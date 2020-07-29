#include <bits/stdc++.h>

using namespace std;

int n, a[105], dp[105][105][105];
int main()
{
	freopen("taming.in", "r", stdin);
	freopen("taming.out", "w", stdout);
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	memset(dp, 63, sizeof dp);
	dp[0][0][1] = (a[0] != 0); // is there breakout??
	for(int i = 1; i < n; i++)
	{
		for(int j = 0; j <= i; j++)
		{
			// k must be one indexed
			for(int k = 1; k <= i+1; k++)
			{
				if(i == j) // can be breakout
				{
					for(int m = 0; m < i; m++)
					{
						dp[i][j][k] = min(dp[i][j][k], dp[i-1][m][k-1]);
					} 
				}
				else dp[i][j][k] = min(dp[i][j][k], dp[i-1][j][k]); // is normal
				dp[i][j][k] += (a[i] != (i-j));
			}
		}
	}
	for(int i = 1; i <= n; i++)
	{
		int ans = 1e9+7;
		for(int j = 0; j < n; j++)
		{
			ans = min(ans, dp[n-1][j][i]);
		}
		cout << ans << endl;
	}
}
