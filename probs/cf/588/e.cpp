#include <bits/stdc++.h>
#pragma GCC optimize("O3")

using namespace std;

int n, m, q;
int par[100005][20], in[100005], ot[100005], dep[100005], tmp=0;
vector<int> adj[100005], seg[100005][20], a[100005];

// these should be passed as pointers and not data sets.
vector<int> merge(vector<int> &p, vector<int> &q, int a)
{
	vector<int> pq;
	int i = 0, j = 0;
	while(pq.size() < a && i < p.size() && j < q.size())
	{
		if(p[i] <= q[j])
		{
			while(p[i] == q[j]) j++;
			pq.push_back(p[i++]);
		} else 
		{
			pq.push_back(q[j++]);
		}
	}
	while(pq.size() < a && i < p.size()) pq.push_back(p[i++]);
	while(pq.size() < a && j < q.size()) pq.push_back(q[j++]);
	vector<int> ret;
	for(int x : pq) ret.push_back(x);
	return ret;
}

void dfs(int v, int p)
{
	in[v] = tmp;
	++tmp;
	par[v][0] = p;
	seg[v][0] = a[v];
	for(int i = 1; i < 20; i++)
	{
		par[v][i] = par[par[v][i-1]][i-1];
		seg[v][i] = merge(seg[v][i-1], seg[par[v][i-1]][i-1], 10);
	}
	for(int x : adj[v])
	{
		if(x == p) continue;
		dep[x] = dep[v]+1;
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


vector<int> que(int v, int u, int a)
{
	vector<int> ret;
	int x = lca(u, v);
	// find the amount on u <-> x and v <-> x
	for(int i = 19; i >= 0; i--)
	{
		if(dep[par[u][i]] >= dep[x])
		{
			ret = merge(ret, seg[u][i], a);
			u = par[u][i];
		}
	}
	for(int i = 19; i >= 0; i--)
	{
		if(dep[par[v][i]] >= dep[x])
		{
			ret = merge(ret, seg[v][i], a);
			v = par[v][i];
		}
	}
	ret = merge(ret, seg[v][0], a);
	return ret;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m >> q;
	for(int i = 0; i < n-1; i++)
	{
		int u, v; cin >> u >> v; --u; --v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for(int i = 0; i < m; i++)
	{
		int u; cin >> u; --u;
		a[u].push_back(i);
	}
	dfs(0, 0);
	while(q--)
	{
		int v, u, a; cin >> v >> u >> a;
		--u; --v;
		// we want to find the a smallest between u and x, and then x and v
		vector<int> ret = que(v, u, a);
		cout << ret.size() << " ";
		for(int x : ret) cout << x+1 << " ";
		cout << endl;
	}
}