#include <bits/stdc++.h>

using namespace std;

int n, dep[100005], par[100005][20];
vector<int> adj[100005];
int psum[100005];
bool vis[100005];

// finds the depths
void dfs(int v, int p)
{
	if(p >= 0)
	{
		dep[v] = 1 + dep[p];
		par[v][0] = p;
	}
	for(int x : adj[v])
	{
		if(x != p) dfs(x,v);
	}
}

// -------- real algo --------- //
// precomp
void precomp()
{
	// cerr << "ok" << endl;
	for(int j = 1; j < 20; j++)
	{
		for(int i = 0; i < n; i++)
		{
			if(par[i][j-1] != -1)
			{
				par[i][j] = par[par[i][j-1]][j-1];
			}
		}
	}
}

// method finding all lca's
int lca(int u, int v)
{
	if(dep[u] > dep[v]) swap(u, v);
	int x = dep[v] - dep[u];

	for(int i = 0; i < 20; i++)
	{
		if(x >> i & 1) v = par[v][i];
	}
	if(u == v) return u;

	for(int i = 19; i >= 0; i--)
	{
		if(par[u][i] != par[v][i])
		{
			u = par[u][i];
			v = par[v][i];
		}
	}
	return par[u][0];
}