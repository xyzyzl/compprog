#include <bits/stdc++.h>
 
using namespace std;
 
int n, dep[100005], par[100005][17];
vector<int> adj[100005];
int psum[100005];
bool vis[100005];
 
// finds the depths
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
 
// -------- real algo --------- //
// precomp
void precomp()
{
	// cerr << "ok" << endl;
	for(int j = 1; j < 17; j++)
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
 
// method finding all lca's
int lca(int u, int v)
{
	if(dep[u] > dep[v]) swap(u, v);
	int x = dep[v] - dep[u];
 
	for(int i = 0; i < 17; i++)
	{
		if(x >> i & 1) v = par[v][i];
	}
    // cout << u << " " << v << " f" << endl;
	if(u == v) return u;
 
	for(int i = 16; i >= 0; i--)
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
    cin >> n;
    for(int i = 0; i < n-1; i++)
    {
        int a, b;
        cin >> a >> b;
        --a; --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
        // cout << a << " " << b << endl;
    }
    dfs(0, -1);
    precomp();

    int q;
    cin >> q;
    while(q--)
    {
        int x, y, a, b, k;
        cin >> x >> y >> a >> b >> k;
        --x; --y;
        --a; --b;
        int p = lca(a, b);
        int d1 = abs(dep[p] - dep[a]) + abs(dep[p] - dep[b]);
        int q = lca(a, x);
        int d21 = abs(dep[q] - dep[a]) + abs(dep[q] - dep[x]);
        int r = lca(b, y);
        int d22 = abs(dep[r] - dep[b]) + abs(dep[r] - dep[y]);
        int d2 = 1 + d21 + d22;
        int u = lca(a, y);
        int d31 = abs(dep[u] - dep[a]) + abs(dep[u] - dep[y]);
        int v = lca(b, x);
        int d32 = abs(dep[v] - dep[b]) + abs(dep[v] - dep[x]);
        int d3 = 1 + d31 + d32;
        d2 = min(d2, d3);
        // cout << p << " " << q << " " << r << " " << u << " " << v << endl;
        int ans = INT_MAX;
        if(d1 % 2 == k % 2)
        {
            ans = min(ans, d1);
        }
        if(d2 % 2 == k % 2)
        {
            ans = min(ans, d2);
        }
        // cout << lca(8, 6) << endl;
        // cout << d21 << " " << d22 << endl;
        cout << ((ans <= k) ? "YES" : "NO") << endl;
    }
}