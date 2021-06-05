#include <bits/stdc++.h>

using namespace std;

int n, k, dp[1005][1005][2];
const int MOD = 1e9+7;

int rec(int i, int j, int d)
{
	if(j == 1) return 1;
	if(dp[i][j][d] != -1)
	{
		return dp[i][j][d];
	}
	long long ans = 2;
	if(d == 1)
	{
		if(i < n) ans += rec(i+1, j, d)-1;
		ans %= MOD;
		if(i > 1) ans += rec(i-1, j-1, !d)-1;
		ans %= MOD;
	} else 
	{
		if(i > 1) ans += rec(i-1, j, d)-1;
		ans %= MOD;
		if(i < n) ans += rec(i+1, j-1, !d)-1;
		ans %= MOD;
	}
	return dp[i][j][d] = ans;
}

void solve()
{
	cin >> n >> k;
	for(int i = 1; i <= n; i++) for(int j = 1; j <= k; j++) for(int d = 0; d < 2; d++) dp[i][j][d] = -1;
	cout << rec(1, k, 1) << endl;
}

int main()
{
	int t;
	cin >> t;
	while(t--) solve();
}
