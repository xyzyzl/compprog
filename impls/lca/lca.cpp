#include <bits/stdc++.h>

using namespace std;

int n, par[100005][20];
vector<int> adj[100005];

int tmp = 0, in[100005], ot[200005];

void dfs(int v, int p)
{
	in[v] = tmp;
	++tmp;
	par[v][0] = p;
	for(int i = 1; i < 20; i++)
		par[v][i] = par[par[v][i-1]][i-1];
	for(int x : adj[v])
	{
		dfs(x,v);
	}
	ot[v] = tmp;
	++tmp;
}

bool anc(int u, int v)
{
	return (in[u] <= in[v] && ot[u] >= ot[v]);
}

// method finding all lca's
int lca(int u, int v)
{
	if(anc(u,v))
		return u;
	for(int i = 19; i >= 0; i--)
	{
		if(!anc(par[u][i], v))
			u = par[u][i];
	}
	return par[u][0];
}

