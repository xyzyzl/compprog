#include <bits/stdc++.h>

using namespace std;

int n, m, gr[1005][1005];
long long dp[1005][1005];
const int MOD = 1e9+7;
int main()
{
	cin >> n >> m;
	for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) cin >> gr[i][j];
	dp[0][0] = (gr[0][0] == 0);
	for(int i = 0; i < n; i++) for(int j = 0; j < m; j++)
	{
		if(gr[i][j])
		{
			dp[i][j] = 0;
			continue;
		}
		if(i && !gr[i-1][j]) dp[i][j] = (dp[i][j] + dp[i-1][j]) % MOD;
		if(j && !gr[i][j-1]) dp[i][j] = (dp[i][j] + dp[i][j-1]) % MOD;
	}
	cout << (dp[n-1][m-1] % MOD) << endl;
}
