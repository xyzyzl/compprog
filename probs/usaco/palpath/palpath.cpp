#include <bits/stdc++.h>

using namespace std;

#define int long long
#define MOD 1000000007
int n, gr[505][505], dp[2][505][505];
signed main()
{
	freopen("palpath.in", "r", stdin);
	freopen("palpath.out", "w", stdout);
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		for(int j = 0; j < n; j++)
		{
			gr[i][j] = s[j];
		}
	}
	for(int i = 0; i < n; i++) dp[0][i][i] = 1;
	for(int t = 0; t < n; t++)
	{
		for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) dp[1][i][j] = 0;
		for(int i = 0; i < n; i++)
		{
			int ri = i;
			int ci = n-1-t-i;
			for(int j = 0; j < n; j++)
			{
				int rj = j;
				int cj = n-1+t-j;
				if(0 > ri || ri >= n || 0 > ci || ci >= n || 0 > rj || rj >= n || 0 > cj || cj >= n) continue; // invalid
				if(gr[ri][ci] != gr[rj][cj]) continue;
				if(1)                  dp[1][ri][rj] = (dp[1][ri][rj] + dp[0][ri][rj]) % MOD;
				if(ri > 0)             dp[1][ri-1][rj] = (dp[1][ri-1][rj] + dp[0][ri][rj]) % MOD;
				if(rj < n-1)           dp[1][ri][rj+1] = (dp[1][ri][rj+1] + dp[0][ri][rj]) % MOD;
				if(ri > 0 && rj < n-1) dp[1][ri-1][rj+1] = (dp[1][ri-1][rj+1] + dp[0][ri][rj]) % MOD;
			}
		}
		for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) dp[0][i][j] = dp[1][i][j];
	}
	cout << dp[0][0][n-1] << endl;
}