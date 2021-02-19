#include <bits/stdc++.h>
#pragma GCC optimize("O3")

using namespace std;
using ll=long long;
#define int ll
const int MAXN = 3005;
using pii = pair<ll, int>;
using iii = pair<ll, pii>;
#define f first
#define s second
#define mp make_pair
using vii = vector<pii>;
using viii = vector<iii>;
#define pb push_back

int n, m, k;
bool vis[MAXN];
ll wt[MAXN];
vii adj[MAXN];
viii eg;

/// Set-based Dijkstra implementation.
void dijk(int src)
{
	fill(wt, wt + n, 1e15+7);
	fill(vis, vis+n, 0);

	priority_queue<pii, vector<pii>, greater<pii> > pq;
	pq.push(mp(0, src));

	wt[src] = 0;

	int ct = 0;
	while (!pq.empty())
	{
		pii tp = pq.top();
		pq.pop();
		if(vis[tp.s]) continue;
		vis[tp.s] = 1;

		for (pii gu : adj[tp.s])
		{
			int w = gu.f;
			int ind = gu.s;
			if (wt[tp.s] + w < wt[ind])
			{
				wt[ind] = wt[tp.s] + w;
				pq.push(mp(wt[ind], ind));
			}
		}
	}
}

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m >> k;
	for(int i = 0; i < m; i++)
	{
		int a,b,w; cin >> a >> b >> w;
		--a; --b;
		eg.pb(mp(w, mp(a, b)));
		adj[a].pb(mp(w, b));
		adj[b].pb(mp(w, a));
	}
	dijk(0);
	ll ans = wt[n-1]; // need to consider < k
	for(int i = 0; i < m; i++)
	{
		for(int i = 0; i < n; i++) adj[i].clear();
		for(auto x : eg)
		{
			adj[x.s.f].pb(mp(max(0ll,x.f-eg[i].f), x.s.s));
			adj[x.s.s].pb(mp(max(0ll,x.f-eg[i].f), x.s.f));
		}
		dijk(0);
		ans = min(ans, wt[n-1]+k*eg[i].f);
	}
	cout << ans << endl;
}