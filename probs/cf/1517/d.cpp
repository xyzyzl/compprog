#include <bits/stdc++.h>

using namespace std;

int n, m, k;
int H[505][505], V[505][505];
int dp[505][505][20];
int main()
{
	cin >> n >> m >> k;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m-1; j++)
		{
			cin >> H[i][j];
		}
	}
	for(int i = 0; i < n-1; i++)
	{
		for(int j = 0; j < m; j++)
		{
			cin >> V[i][j];
		}
	}
	if(k%2)
	{
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < m; j++) cout << "-1 ";
			cout << '\n';
		}
		return 0;
	}
	memset(dp, 0x7f, sizeof dp);
	for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) dp[i][j][0] = 0;
	for(int p = 1; p <= k/2; p++) for(int i = 0; i < n; i++) for(int j = 0; j < m; j++)
	{
		if(i+1 < n) dp[i][j][p] = min(dp[i][j][p], dp[i+1][j][p-1] + V[i][j]);
		if(i > 0) dp[i][j][p] = min(dp[i][j][p], dp[i-1][j][p-1] + V[i-1][j]);
		if(j+1 < m) dp[i][j][p] = min(dp[i][j][p], dp[i][j+1][p-1] + H[i][j]);
		if(j > 0) dp[i][j][p] = min(dp[i][j][p], dp[i][j-1][p-1] + H[i][j-1]);
	}
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++) cout << 2*dp[i][j][k/2] << ' ';
		cout << '\n';
	}
}
