#include <bits/stdc++.h>

using namespace std;

int n, m, t[200005], val[200005], dep[200005], par[200005][20];
vector<int> adj[400005];
bool vis[200005];

// finds the depths
void dfs(int v, int p)
{
	dep[v] = 1 + dep[p];
	if(p > 0)
	{
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
		for(int i = 1; i <= m; i++)
		{
			if(par[i][j-1] > 0)
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
		if((x >> i) & 1) v = par[v][i];
	}
	if(u == v) return u;

	for(int i = 19; i >= 0; i--)
	{
		if(par[u][i] != par[v][i] && par[u][i] > 0 && par[v][i] > 0)
		{
			u = par[u][i];
			v = par[v][i];
		}
	}
	return par[u][0];
}

int when[200005], qry[200005][2];
int ct = m;
int main()
{
	cin >> n >> m;
	ct = m;
	for(int i = 1; i <= n; i++) cin >> t[i];
	for(int i = 1; i <= m; i++) val[i] = i;
	for(int i = 1; i <  m; i++) 
	{
		int a, b, oa, ob;
		cin >> a >> b;
		oa = a; ob = b;
		qry[i][0] = oa;
		qry[i][1] = ob;
		a = val[a]; b = val[b];
		ct++;
		adj[a].push_back(ct);
		adj[ct].push_back(a);
		adj[b].push_back(ct);
		adj[ct].push_back(b);
		val[oa] = ct;
	}
	par[ct][0] = ct;
	dfs(ct, ct);
	precomp();
	int tot = 0;
	for(int i = 1; i <  n; i++)
	{
		int l = lca(t[i],t[i+1])-m; 
		if(l <= 0) continue;
		when[l]++;
		tot++;
	}
	cout << tot << endl;
	for(int i = 1; i <  m; i++)
	{
		tot -= when[i];
		cout << tot << endl;
	}
}
