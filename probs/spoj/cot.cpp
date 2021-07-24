#include <bits/stdc++.h>

using namespace std;

int n, m, w[100005], par[100005][20];
vector<int> adj[100005];

struct node
{
	int ct;
	node *lf, *rg;
	node(int ct, node *lf, node *rg):
		ct(ct), lf(lf), rg(rg) {}
	node* insert(int l, int r, int w);
};

node *null = new node(0, NULL, NULL);

node *node::insert(int l, int r, int w)
{
	if(l <= w && w < r)
	{
		if(l+1==r)
		{
			return new node(this->ct+1, null, null);
		}
		int m = (l+r)/2;
		return new node(this->ct+1, this->lf->insert(l, m, w), this->rg->insert(m, r, w));
	}

	return this;
}

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
		// as a verifier make sure par[u][i] >= 0 s.t. no array out of bounds
		if(par[u][i] >= 0 && !anc(par[u][i], v))
			u = par[u][i];
	}
	return par[u][0];
}

int main()
{
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> w[i];
	for(int i = 0; i < n-1; i++)
	{
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	dfs(1, 0);
	for(int i = 0; i < 19; i++)
	{
		for(int j = 1; j <= n; j++)
		{
			par[j][i+1] = par[par[j][i]][i];
		}
	}
	
	while(m--)
	{
		int u, v, k; cin >> u >> v >> k;
		int q = lca(u, v);
		
	}
}
