#include <bits/stdc++.h>

using namespace std;

#define MAXN 100005

int n, k, a[MAXN], dp[MAXN][25][4];
int main()
{
	freopen("hps.in", "r", stdin);
	freopen("hps.out", "w", stdout);
	cin >> n >> k;
	for(int i = 1; i <= n; i++)
	{
		char c; cin >> c;
		if(c == 'H') a[i] = 0;
		else if(c == 'P') a[i] = 1;
		else a[i] = 2;
	}
	for(int i = 1; i <= n; i++) for(int j = 0; j <= k; j++) for(int k1 = 0; k1 < 3; k1++)	
	{
		for(int k2 = 0; k2 < 3; k2++)
		{
			if(k1 == k2) continue;
			if(j > 0) dp[i][j][k1] = max(dp[i][j][k1], dp[i-1][j-1][k2] + (a[i] == k1));
		}
		dp[i][j][k1] = max(dp[i][j][k1], dp[i-1][j][k1] + (a[i] == k1));
	}
	int ans = 0;
	for(int i = 0; i <= k; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			ans = max(ans, dp[n][i][j]);
		}
	}
	cout << ans << endl;
}
