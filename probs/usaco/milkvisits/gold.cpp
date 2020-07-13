#include <bits/stdc++.h>

using namespace std;

int n, m, val[100005], par[100005][20], dep[100005], qry[100005][4];
vector<int> adj[100005], nds[100005];

void dfs(int v, int p)
{
	dep[v] = dep[p] + 1;
	par[v][0] = p;
	for(int x : adj[v]) 
	{
		if(x != p) dfs(x, v);
	}
}

// precomp
void precomp()
{
	// cerr << "ok" << endl;
	for(int j = 1; j < 20; j++)
	{
		for(int i = 1; i <= n; i++)
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

stack<int> occ[100005];
bool good[100005];
void s_dfs(int v, int p)
{
	occ[val[v]].push(v);
	for(int x : nds[v])
	{
		if(occ[qry[x][3]].empty()) continue;
		int ls = occ[qry[x][3]].top();

		if(ls == v)
		{
			good[x] = 1;
		} else 
		{
			if(qry[x][0] != v && qry[x][1] != v) continue;
			int lca = qry[x][2];
			if(dep[ls] < dep[lca]) // not in range
				continue;
			else
				good[x] = 1;
		}
	}
	for(int x : adj[v])
	{
		if(x != p)
			s_dfs(x, v);
	}
	occ[val[v]].pop();
}

int main()
{
	freopen("milkvisits.in", "r", stdin);
	freopen("milkvisits.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
	{
		cin >> val[i];
	}
	for(int i = 0; i < n-1; i++)
	{
		int u,v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(1, 0);
	precomp();
	for(int i = 0; i < m; i++)
	{
		int a, b, c, d;
		cin >> a >> b >> d;
		nds[a].push_back(i);
		nds[b].push_back(i);
		c = lca(a,b);
		qry[i][0] = a; qry[i][1] = b; qry[i][2] = c;
		qry[i][3] = d;
	}
	s_dfs(1, 0);	
	for(int i = 0; i < m; i++) cout << good[i];
	cout << endl;
}
