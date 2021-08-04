#include <bits/stdc++.h>

using namespace std;

int n, par[200005][20];
vector<int> adj[200005];

int tmp = 0, in[200005], ot[400005];

void dfs(int v, int p)
{
	in[v] = tmp;
	++tmp;
	par[v][0] = p;
	for(int i = 1; i < 20; i++)
		par[v][i] = par[par[v][i-1]][i-1];
	for(int x : adj[v])
	{
		if(x == p) continue;
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
		// as a verifier make sure par[u][i] >= 0 s.t. no array out of bounds
		if(par[u][i] >= 0 && !anc(par[u][i], v))
			u = par[u][i];
	}
	return par[u][0];
}

int main()
{
	int n, q; cin >> n >> q;
	for(int i = 1; i < n; i++)
	{
		int k; cin >> k; --k;
		adj[i].push_back(k);
		adj[k].push_back(i);
	}
	dfs(0, 0);
	while(q--)
	{
		int a, b; cin >> a >> b;
		--a; --b;
		cout << lca(a,b)+1 << endl;
	}
}
