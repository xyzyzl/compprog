#include <bits/stdc++.h>

using namespace std;

int n, k;
long long dp[15][15];
int main()
{
	cin >> n >> k;
	// n = number of slots, k = number of colors.
	// WLOG let the first slot have color 1.
	// We can just multiply the final result by n
	dp[0][0] = 1LL;
	for(int i = 1; i < n; i++)
	{
		for(int j = 0; j < k; j++)
		{
			for(int it = 0; it < k; it++)
			{
				if(it == j) continue;
				dp[i][j] += dp[i-1][it];
			}
		}
	}
	long ans = 0; // number of ways assuming first slot is color 0
	for(int i = 1; i < k; i++)
	{
		ans += dp[n-1][i];
	}
	// cout << ans << endl;
	cout << k * ans << endl; // k ways * number of ways for color 1
}
