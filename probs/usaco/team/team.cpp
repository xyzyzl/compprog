#include <bits/stdc++.h>

#define int long long
using namespace std;

const int MOD = 1e9+9;
int n, m, k, dp[1005][1005][15];
int a[1005], b[1005];
signed main()
{
	freopen("team.in", "r", stdin);
	freopen("team.out", "w", stdout);
	cin >> n >> m >> k;
	for(int i = 0; i < n; i++) cin >> a[i];
	for(int i = 0; i < m; i++) cin >> b[i];
	for(int i = 0; i <= n; i++) for(int j = 0; j <= m; j++) dp[i][j][0] = 1;
	for(int l = 1; l <= k; l++)
	{
		for(int i = 1; i <= n; i++) for(int j = 1; j <= m; j++)
		{
			if(a[i-1] > b[j-1])
			{
				dp[i][j][l] += dp[i-1][j-1][l-1];
				dp[i][j][l] %= MOD;
			}
		}
		for(int i = 0; i <= n; i++) for(int j = 0; j <= m; j++)
		{
			if(i) dp[i][j][l] += dp[i-1][j][l];
			if(j) dp[i][j][l] += dp[i][j-1][l];
			if(i&&j) dp[i][j][l] -= dp[i-1][j-1][l];
			dp[i][j][l] %= MOD;
			dp[i][j][l] += MOD;
			dp[i][j][l] %= MOD;
		}
	}
	cout << (dp[n][m][k] % MOD) << endl;
}