#include <bits/stdc++.h>

using namespace std;
#define MAXN 300005
#define pb push_back

int n, x, y, is_y[MAXN];
long long sz[MAXN];
vector<int> adj[MAXN];

void dfs(int v, int p)
{
	sz[v] = 1;
	for(int x : adj[v])
	{
		if(x==p) continue;
		dfs(x, v);
		is_y[v] |= is_y[x];
		sz[v] += sz[x];
	}
}

int main()
{
	cin >> n >> x >> y;
	--x; --y;
	is_y[y] = 1;
	for(int i = 0; i < n-1; i++)
	{
		int u, v; cin >> u >> v;
		--u; --v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	dfs(x, -1);
	long long tot = (long long)n*(n-1);
	for(int u : adj[x])
	{
		if(is_y[u])
		{
			tot -= sz[y]*(n-sz[u]);
			break;
		}
	}
	cout << tot << endl;
}