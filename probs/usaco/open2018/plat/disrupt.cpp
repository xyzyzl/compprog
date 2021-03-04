#include <bits/stdc++.h>

using namespace std;

const int MAXN = 50005;
using pii = pair<int, int>;
#define f first
#define s second

int n, m, ans[MAXN];
vector<pii> adj[MAXN]; // tree edges only
set<pii> ext[MAXN]; // extra edges

set<pii> ret;
set<pii> mrg(int i, int j)
{
	if(ext[i].size() < ext[j].size()) swap(i,j);
	ret = ext[i];
	for(pii x : ext[j])
	{
		if(ret.count(x))
		{
			ret.erase(x);
			continue;
		}
		ret.insert(x);
	}
	return ret;
}

void dfs(int v, int p)
{
	for(auto x : adj[v]) if(x.f != p)
	{
		dfs(x.f, v);
		// merge somehow
		ext[v] = mrg(v, x.f);
		// need to update ans for edge
		ans[x.s] = ext[x.f].begin()->f;
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	freopen("disrupt.in","r",stdin);
	freopen("disrupt.out","w",stdout);
	memset(ans, -1, sizeof ans);
	cin >> n >> m;
	for(int i = 1; i < n; i++)
	{
		int u, v; cin >> u >> v;
		--u; --v;
		adj[u].push_back({v, i});
		adj[v].push_back({u, i});
	}
	for(int i = 0; i < m; i++)
	{
		int u, v, w; cin >> u >> v >> w;
		--u; --v;
		ext[u].insert({w, i});
		ext[v].insert({w, i});
	}
	dfs(0, -1);
	for(int i = 1; i < n; i++)
	{
		if(!ans[i]) cout << -1 << endl;
		else cout << ans[i] << endl;
	}
}