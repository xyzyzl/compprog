#include <bits/stdc++.h>
#pragma GCC optimize("O3")

using namespace std;
using ll=long long;
const int MAXN = 3005;
using pii = pair<ll, int>;
using iii = pair<ll, pii>;
#define f first
#define s second
#define mp make_pair
using vii = vector<pii>;
using viii = vector<iii>;
#define pb push_back

int n, m, k, ds[MAXN];
ll wt[MAXN];
vii adj[MAXN];
viii eg;

/// Set-based Dijkstra implementation.
void dijk(int src)
{
	fill(wt, wt + n, 1e15+7);
	fill(ds, ds + n, 1e9+7);

	priority_queue<pii> pq;
	pq.push(mp(0, src));

	wt[src] = 0;
	// number of edges between the source and each node.
	ds[src] = 0;

	int ct = 0;
	while (!pq.empty())
	{
		pii tp = pq.top();
		pq.pop();

		for (pii gu : adj[tp.s])
		{
			int w = gu.f;
			int ind = gu.s;
			if (wt[tp.s] + w < wt[ind] || (wt[tp.s] + w == wt[ind] && ds[tp.s] + 1 < ds[ind]))
			{
				wt[ind] = wt[tp.s] + w;
				ds[ind] = ds[tp.s] + 1;
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
		eg.pb(mp(w, mp(b, a)));
	}
	ll ans = LLONG_MAX;
	for(int i = 0; i < 2*m; i++)
	{
		for(int i = 0; i < n; i++) adj[i].clear();
		int bn0 = eg[i].s.f;
		int bn1 = eg[i].s.s;
		for(auto x : eg)
		{
			adj[x.s.f].pb(mp(max(0ll,x.f-eg[i].f), x.s.s));
		}
		dijk(0);
		ans = min(ans, wt[n-1]+min(ds[n-1],k)*eg[i].f);
	}
	cout << ans << endl;
}