#include <bits/stdc++.h>

using namespace std;

int n, m, t[200005], val[200005], par[400005][20];
vector<int> adj[400005];

int tmp = 0, in[400005], ot[400005];

// finds the depths
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

// -------- real algo --------- //
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
		adj[ct].push_back(a);
		adj[ct].push_back(b);
		val[oa] = ct;
	}
	par[ct][0] = ct;
	dfs(ct, ct);
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
