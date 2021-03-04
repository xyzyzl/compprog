#include <bits/stdc++.h>

using namespace std;

const int MAXN = 50005;
using pii = pair<int, int>;
#define f first
#define s second

int n, m, ans[MAXN];
vector<pii> adj[MAXN], a[MAXN], b[MAXN]; // tree edges only
multiset<pii> ext[MAXN];				 // extra edges (add and delete)

int tin[MAXN], tout[MAXN], t, par[MAXN][19];

bool anc(int a, int b)
{
	return tin[a] <= tin[b] && tout[b] <= tout[a];
}

void prelca(int v, int p)
{
	tin[v] = t++;
	par[v][0] = p;
	for (auto x : adj[v])
		if (x.f != p)
		{
			prelca(x.f, v);
		}
	tout[v] = t++;
}

int lca(int u, int v)
{
	if (anc(u, v))
		return u;
	if (anc(v, u))
		return v;
	for (int i = 18; i >= 0; i--)
	{
		// as a verifier make sure par[u][i] >= 0 s.t. no array out of bounds
		if (par[u][i] >= 0 && !anc(par[u][i], v))
			u = par[u][i];
	}
	return par[u][0];
}

void dfs(int v, int p)
{
	for (pii x : a[v])
	{
		ext[v].insert(x);
	}
	for (auto x : adj[v])
		if (x.f != p)
		{
			dfs(x.f, v);
			// merge somehow
			if (ext[x.f].size() > ext[v].size())
				swap(ext[x.f], ext[v]);
			for (pii y : ext[x.f])
				ext[v].insert(y);
			ext[x.f].clear();
		}
	// update ans
	for (pii x : b[v])
	{
		ext[v].erase(x);
	}
	ans[v] = (ext[v].empty() ? -1 : ext[v].begin()->f);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	freopen("disrupt.in", "r", stdin);
	freopen("disrupt.out", "w", stdout);
	memset(ans, -1, sizeof ans);
	cin >> n >> m;
	vector<pii> eg;
	for (int i = 1; i < n; i++)
	{
		int u, v;
		cin >> u >> v;
		--u;
		--v;
		adj[u].push_back({v, i});
		adj[v].push_back({u, i});
		eg.push_back({u, v});
	}
	prelca(0, 0);
	for (int i = 1; i < 19; i++)
	{
		for (int v = 0; v < n; v++)
		{
			par[v][i] = par[par[v][i - 1]][i - 1];
		}
	}
	for (int i = 0; i < m; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		--u;
		--v;
		// deeper one will be add, less deep one will be rem.
		if (anc(u, v))
		{
			a[v].push_back({w, i});
			b[u].push_back({w, i});
		}
		else if (anc(v, u))
		{
			a[u].push_back({w, i});
			b[v].push_back({w, i});
		}
		else
		{
			int p = lca(u, v);
			a[u].push_back({w, i});
			a[v].push_back({w, i});
			b[p].push_back({w, i});
			b[p].push_back({w, i});
		}
	}
	dfs(0, 0);
	for (int i = 0; i < n - 1; i++)
	{
		if (anc(eg[i].s, eg[i].f))
			swap(eg[i].f, eg[i].s);
		cout << ans[eg[i].s] << endl;
	}
}