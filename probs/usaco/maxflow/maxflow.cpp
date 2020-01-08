#include <bits/stdc++.h>

using namespace std;

int n, dep[100005], par[100005][20];
vector<int> adj[100005];
int psum[100005];
bool vis[100005];

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

int q;
int main()
{
    freopen("maxflow.in", "r", stdin);
    freopen("maxflow.out", "w", stdout);
	memset(par, -1, sizeof(par));
	cin >> n >> q;
	for(int i = 1; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		--a; --b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs(0, -1); // root node is node #1
	precomp();
	// queries
	while(q--)
	{
		int a, b;
		cin >> a >> b;
		--a; --b;
		int c = lca(a,b);
		// cout << c << endl;
		psum[a]++;
		psum[b]++;
		psum[c]--;
		psum[par[c][0]]--;
		// cout << c << endl;
		// computes LCA correctly!
	}
	// propagate the prefix sums
	queue<int> bfs;
	bfs.push(0);
	stack<int> st;
	while(!bfs.empty())
	{
		int tp = bfs.front();
		bfs.pop();
		vis[tp] = 1;
		st.push(tp);
		for(int x : adj[tp])
		{
			if(!vis[x]) bfs.push(x);
		}
	}
	while(!st.empty())
	{
		int curr = st.top();
		st.pop();
		psum[par[curr][0]] += psum[curr];
	}
	int mx = 0;
	for(int i = 0; i < n; i++)
	{
		mx = max(mx, psum[i]);
	}
	cout << mx << endl;
}