#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MOD 9999973

int n, m;
ll dp[105][205][205];
int main()
{
	cin >> n >> m;
	dp[0][m][0] = 1;
	for(int i = 1; i <= n; i++) for(int j = 0; j <= m; j++) for(int k = 0; k <= m-j; k++)
	{
		dp[i][j][k] = dp[i-1][j][k]; // choose nothing
		// pick at most two
		dp[i][j][k] = (dp[i][j][k] + (ll)((k+1)*(k+2)/2)*dp[i-1][j][k+2]) % MOD; 
		dp[i][j][k] = (dp[i][j][k] + (ll)(k*(j+1))*dp[i-1][j+1][k]) % MOD;
		dp[i][j][k] = (dp[i][j][k] + (ll)(k+1)*dp[i-1][j][k+1]) % MOD;
		if(k > 1) dp[i][j][k] = (dp[i][j][k] + (ll)((j+1)*(j+2)/2)*dp[i-1][j+2][k-2]) % MOD;
		if(k > 0) dp[i][j][k] = (dp[i][j][k] + (ll)(j+1)*dp[i-1][j+1][k-1]) % MOD;
	}
	ll ans = 0;
	for(int i = 0; i <= m; i++) for(int j = 0; j <= m-i; j++)
	{
		ans = (ans + dp[n][i][j]) % MOD;
	}
	cout << ans << endl;
}