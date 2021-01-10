#include <bits/stdc++.h>

using namespace std;

int n, S, m, sz[55], deg[55];
int dp[120][55][55];
using pii=pair<int, int>;
using iii=pair<int, pii>;
#define pb push_back
#define mp make_pair
#define f first
#define s second
vector<iii> adj[55];
vector<iii> edg;

void dfs(int v, int p)
{
	for(iii x : adj[v])
	{
		if(x.s.s != p)
		{
			dfs(x.s.s, v);
			sz[v] += sz[x.s.s];
		}
	}
}

int rec(int e, int in, int ot)
{
	if(in==0 && ot==0) return 0;
	if(dp[e][in][ot] >= 0) return dp[e][in][ot];
	int v = edg[e].s.s;
	if(deg[v] == 1)
	{
		// is a leaf node
		if(ot == 0) return 0;
		else return dp[e][in][ot] = rec((e^1), ot, 0)+edg[e].f;
	}
	vector<int> g(100);
	g[0] = 1e9+7;
	for(iii x : adj[v])
	{
		if(x.f == (e^1))
		{
			continue;
		}
		for(int k = in; k > 0; k--)
		{
			for(int diff = k; diff > 0; diff--)
			{
				g[k] = max(g[k], min(g[k-diff], rec(x.f, diff, in+ot-diff) + x.s.f));
			}
		}
	}
	return dp[e][in][ot] = g[in];
}

int main()
{
	memset(dp, -1, sizeof dp);
	cin >> n;
	for(int i = 0; i < n-1; i++)
	{
		int a, b, w; cin >> a >> b >> w;
		--a; --b;
		deg[a]++; deg[b]++;
		adj[a].pb(mp(2*i, mp(w, b)));
		adj[b].pb(mp(2*i+1, mp(w, a)));
		edg.pb(mp(w, mp(a,b)));
		edg.pb(mp(w, mp(b,a)));
	}
	cin >> S >> m;
	--S;
	for(int i = 0; i < m; i++)
	{
		int x; cin >> x;
		--x;
		sz[x]++;
	}
	dfs(S, -1);
	int ans = INT_MAX;
	for(iii x : adj[S])
	{
		// find the value if you take edge v -> x.s
		ans = min(ans, rec(x.f, sz[x.s.s], m-sz[x.s.s])+x.s.f);
	}
	cout << ans << endl;
}
