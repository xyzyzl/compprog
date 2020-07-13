#include <bits/stdc++.h>

using namespace std;

int n, m, val[100005], par[100005][20], dep[100005];
int ct[2][100005];
vector<int> adj[100005];

void dfs(int v, int p)
{
	dep[v] = dep[p] + 1;
	par[v][0] = p;
	ct[val[v]][v]++;
	ct[0][v] += ct[0][par[v][0]];
	ct[1][v] += ct[1][par[v][0]];
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

int main()
{
	freopen("milkvisits.in", "r", stdin);
	freopen("milkvisits.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
	{
		char c;
		cin >> c;
		val[i] = (c == 'H') ? 0 : 1;
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
	cerr << endl;
	for(int i = 0; i < m; i++)
	{
		int a, b;
		char c;
		cin >> a >> b >> c;
		int t = (c == 'G');
		int d = lca(a,b);
		if(ct[t][a] - ct[t][par[d][0]] + ct[t][b] - ct[t][d] <= 0)
		{
			cout << 0;
		} else cout << 1;
	}
	cout << endl;
}
