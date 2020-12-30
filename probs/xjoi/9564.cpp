#include <bits/stdc++.h>
#define int long long

using namespace std;

int n, k, dp[10][100][555], can[10][100];
signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> k;
	for(int i = 0; i < (1 << n); i++)
	{
		if(i & (i << 1)) continue;
		dp[0][__builtin_popcount(i)][i] = 1;
		can[0][__builtin_popcount(i)] = 1;
	}
	for(int i = 1; i < n; i++)
	{
		for(int j = 0; j <= k; j++)
		{
			for(int mask = 0; mask < (1 << n); mask++)
			{
				if(mask & 2*mask) continue;
				int x = __builtin_popcount(mask);
				if(j-x < 0 || !can[i-1][j-x]) continue;
				can[i][j] = 1;
				for(int pmask = 0; pmask < (1 << n); pmask++)
				{
					if(pmask & pmask*2) continue;
					if((mask & pmask) || (mask & (pmask >> 1)) || (mask & (pmask << 1))) continue; // some kings can attack
					dp[i][j][mask] += dp[i-1][j-x][pmask];
				}
			}
		}
	}
	int mx = 0;
	for(int i = 0; i < (1 << n); i++)
	{
		mx += dp[n-1][k][i];
	}
	cout << mx << endl;
}