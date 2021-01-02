#include <bits/stdc++.h>

using namespace std;

#define MAXN 50005
#define INF (1e9+7)
#define pii pair<int,int>
#define f first
#define s second
#define vii vector<pii> 
#define pb push_back
#define mp make_pair

int n, m, wt[MAXN], wc[MAXN];
vii adj[MAXN];

/// Set-based Dijkstra implementation.
void dijk(int src)
{
	fill(wt, wt + n, INF);

	set<pii> pq;
	pq.insert(mp(0, src));

	wt[src] = 0;

	int ct = 0;
	while (!pq.empty())
	{
		pii tp = *pq.begin();
		pq.erase(pq.begin());

		for (pii gu : adj[tp.s])
		{
			int w = gu.f;
			int ind = gu.s;
			if (wt[tp.s] + w < wt[ind])
			{
				pq.erase(mp(wt[ind], ind)); /// you can't efficiently erase with a priority queue
				/// and you're processing way too many indices
				wt[ind] = wt[tp.s] + w;
				pq.insert(mp(wt[ind], ind));
			}
		}
	}
}

int main()
{
	freopen("dining.in", "r", stdin);
	freopen("dining.out", "w", stdout);
	int K;
	cin >> n >> m >> K;
	for(int i = 0; i < m; i++)
	{
		int a, b, w;
		cin >> a >> b >> w;
		a--; b--;
		adj[a].pb(mp(w, b));
		adj[b].pb(mp(w, a));
	}
	dijk(n-1);
	for(int i = 0; i < n; i++) wc[i] = wt[i];
	for(int i = 0; i < K; i++)
	{
		int v, Y;
		cin >> v >> Y;
		adj[n].pb(mp(wt[--v]-Y, v));
	}
	dijk(n);
	for(int i = 0; i < n-1; i++)
	{
		cout << (wt[i] <= wc[i]) << endl;
	}
}
