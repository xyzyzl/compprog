#include <bits/stdc++.h>

using namespace std;

const int MAXN = 200005;

int n, m, dist[MAXN], dp[MAXN]; // dp[i] = min distance to node 0 attainable from node i
bool vis[MAXN];
vector<int> adj[MAXN];

void bfs()
{
	fill(dist, dist+n, 1e9+7);
	queue<int> q;
	q.push(0);
	dist[0] = 0;
	while(!q.empty())
	{
		int v = q.front(); q.pop();
		for(int x : adj[v])
		{
			if(dist[x] > dist[v]+1) q.push(x);
			dist[x] = min(dist[x], dist[v]+1);
		}
	}
}

void dfs(int v)
{
	vis[v] = 1;
	for(int x : adj[v])
	{
		if(dist[x] > dist[v] && !vis[x]) dfs(x);
		if(dist[x] > dist[v]) dp[v] = min(dp[v], dp[x]);
		else                  dp[v] = min(dp[v], dist[x]);
	}
}

void solve()
{
	cin >> n >> m;
	for(int i = 0; i < n; i++) adj[i].clear();
	for(int i = 0; i < m; i++)
	{
		int a, b; cin >> a >> b;
		--a; --b;
		adj[a].push_back(b);
	}
	bfs();
	fill(dp, dp+n, INT_MAX);
	fill(vis, vis+n, 0);
	dfs(0);
	for(int i = 0; i < n; i++) cout << min(dp[i], dist[i]) << " ";
	cout << endl;
}

int main()
{
	int t; cin >> t;
	while(t--)
	{
		solve();
	}
}
