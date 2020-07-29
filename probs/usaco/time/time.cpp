#include <bits/stdc++.h>

using namespace std;

int n, m, c, a[1005], dp[1005][1005];
vector<int> adj[1005];
int main()
{
	freopen("time.in", "r", stdin);
	freopen("time.out", "w", stdout);
	cin >> n >> m >> c;
	for(int i = 0; i < n; i++) cin >> a[i];
	for(int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		--a; --b;
		adj[b].push_back(a);
	}
	memset(dp, -1, sizeof dp);
	dp[0][0] = 0; // starting at node 0
	for(int t = 1; t < 1005; t++)
	{
		for(int i = 0; i < n; i++)
		{
			for(int x : adj[i])
				if(dp[x][t-1] != -1) // it's defined
					dp[i][t] = max(dp[i][t], dp[x][t-1] + a[i]);
		}
	}
	int ans = 0;
	for(int t = 0; t < 1005; t++)
		ans = max(ans, dp[0][t] - c*t*t);
	cout << ans << endl;
}
