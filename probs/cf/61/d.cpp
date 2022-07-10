#include <bits/stdc++.h>

using namespace std;

using pii = pair<long long, int>;
#define f first 
#define s second

const int MAXN = 100005;

int n, vis[MAXN];
vector<pii> adj[MAXN];
long long wt[MAXN];

void dijk(int src)
{
	fill(wt, wt + n, 1e15+7);
	fill(vis, vis+n, 0);

	priority_queue<pii, vector<pii>, greater<pii> > pq;
	pq.push({0, src});

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
				pq.push({wt[ind], ind});
			}
		}
	}
}

int main()
{
	cin >> n;
	long long tw = 0;
	for(int i = 1; i < n; i++)
	{
		int a, b, w; cin >> a >> b >> w;
		--a; --b;
		adj[a].push_back({w, b});
		adj[b].push_back({w, a});
		tw += w;
	}
	// find city farthest from 1.
	dijk(0);
	int mxi = 0, mx = 0;
	for(int i = 1; i < n; i++)
	{
		if(wt[i] > mx)
		{
			mx = wt[i];
			mxi = i;
		}
	}
	tw *= 2;
	tw -= wt[mxi];
	cout << tw << endl;
}