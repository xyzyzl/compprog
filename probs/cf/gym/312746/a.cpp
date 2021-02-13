#include <bits/stdc++.h>

using namespace std;

using ll = long long;
#define int ll
const int MOD = 1000000007;

int n, m;
ll dp[155][155][2][2];
signed main()
{
	cin >> n >> m;
	for(int l = 1; l <= m; l++) for(int r = l; r <= m; r++)
		dp[l][r][0][0] = 1;
	ll ans = 0;
	for(int i = 1; i <= n; i++)
	{
		ll tot = 0;
		for(int l = 1; l <= m; l++) for(int r = l; r <= m; r++)
		{
			tot = (tot + dp[l][r][0][0])%MOD;
			tot = (tot + dp[l][r][0][1])%MOD;
			tot = (tot + dp[l][r][1][0])%MOD;
			tot = (tot + dp[l][r][1][1])%MOD;
		}
		ans = (ans+(tot*(n-i+1))%MOD)%MOD;
		for(int l = 1; l <= m; l++) for(int r = m; r >= l; r--)
			dp[l][r][1][1] = (dp[l-1][r+1][0][0] + dp[l-1][r][0][1] + dp[l][r+1][1][0] +
				dp[l][r][1][1] + dp[l-1][r][1][1] + dp[l][r+1][1][1] - dp[l-1][r+1][1][1])%MOD;
		for(int l = 1; l <= m; l++) for(int r = l; r <= m; r++)
			dp[l][r][0][1] = dp[l][r][1][0] = (dp[l-1][r][0][0] + dp[l][r][1][0] + dp[l-1][r][1][0] + dp[l][r-1][1][0] - dp[l-1][r-1][1][0])%MOD;
		for(int l = m; l >= 1; l--) for(int r = l; r <= m; r++)
			dp[l][r][0][0] = (dp[l][r][0][0] + dp[l+1][r][0][0] + dp[l][r-1][0][0] - dp[l+1][r-1][0][0])%MOD;
	}
	cout << (ans+MOD)%MOD << endl;
}