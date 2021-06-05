#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;
using ll = long long;
#define f first
#define s second

const int MAXN = 200005;
int mn;
int sz[MAXN], vs[MAXN];
vector<pii> adj[MAXN];

// find subtree size
int sub_size(int v, int p)
{
	sz[v] = 1;
	for(int i = 0; i < adj[v].size(); i++)
	{
		pii x = adj[v][i];
		if(x.f==p || vs[x.f]) continue;
		sz[v] += sub_size(x.f, v);	
	}
	return sz[v];
}

// get the centroid
void get_c(int v, int p, int m, int& ret)
{
	int mx = m - sz[v];
	for(int i = 0; i < adj[v].size(); i++)
	{
		pii x = adj[v][i];
		if(x.f == p || vs[x.f]) continue;
		get_c(x.f,v,m,ret);
		mx = max(mx, sz[x.f]);
	}
	if(mx < mn)
	{
		mn = mx;
		ret = v;
	}
}

ll solve(int v)
{
	mn = INT_MAX;
	// root tree at v
	int m = sub_size(v, -1);
	int cen; get_c(v, -1, m, cen);
	vs[cen] = 1;
	ll ret = 0;
	for(auto x : adj[cen])
	{
		if(vs[x.f]) continue;
		ret += solve(x.f);
	}
	return ret;
}

int main()
{
	int n, M; cin >> n >> M;
	if(M == 1) 
	{
		cout << n*(n-1) << endl;
		return 0;
	}
	for(int i = 1; i < n; i++)
	{
		int a, b, c; cin >> a >> b >> c;
		adj[a].push_back({b, c});
		adj[b].push_back({a, c});
	}

}