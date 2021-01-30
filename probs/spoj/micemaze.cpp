#include <bits/stdc++.h>
using namespace std;

using pii = pair<int,int>;
#define f first
#define s second
#define mp make_pair
#define MAXN 105
#define INF 1000000007
int n, m, wt[MAXN];
vector<pii> adj[MAXN];

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
	int E, T;
	cin >> n >> E >> T >> m;
	E--;
	for(int i = 0; i < m; i++)
	{
		int a, b, w; cin >> a >> b >> w; --a; --b;
		adj[b].push_back({w, a});
	}
	dijk(E);
	int ans = 0;
	for(int i = 0; i < n; i++)
	{
		if(wt[i] <= T)
		{
			ans++;
		}
	}
	cout << ans << endl;
}