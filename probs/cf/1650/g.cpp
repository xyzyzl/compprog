#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9+7;

void solve()
{
	int n, m; cin >> n >> m;
	int r, s; cin >> r >> s; --r; --s;
	vector<int> vis(n, 0), dist(n, MOD);
	vector<vector<int> > adj(n);
	vector<vector<int> > dp(n, vector<int>(2));
	for(int i = 0; i < m; i++)
	{
		int u, v; cin >> u >> v;
		--u; --v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	int sp = MOD;
	int ans = 0;
	queue<tuple<int, int, int> > q;
	vis[r] = 1;
	q.push({r, 0, 0});
	dp[r][0] = 1;
	while(!q.empty())
	{
		auto [v, d, k] = q.front();
		q.pop();
		if(v == s)
		{
			if(sp == MOD) sp = d;
			ans = (ans + dp[v][k]) % MOD;
		}
		if(d == sp + 1) continue;
		for(int x : adj[v])
		{
			if(d <= dist[x])
			{
				dist[x] = min(dist[x], d+1);
				dp[x][d-dist[x]+1] = (dp[x][d-dist[x]+1] + dp[v][k]) % MOD;
				if(!vis[x] || (vis[x] == 1 && dist[x] == d)) q.push({x, d+1, vis[x]++});
			}
		}
	}
	cout << ans << endl;
}

int main()
{
	int t; cin >> t;
	while(t--) solve();
}