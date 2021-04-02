#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;
#define f first
#define s second

const int MAXN = 255;

int N, M, par[MAXN], wt[MAXN], vis[MAXN];
vector<pii> adj[MAXN];

void dijk(int src)
{
	memset(wt, 0x7f, sizeof wt);
	memset(vis, 0, sizeof vis);
	memset(par, -1, sizeof par);
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	pq.push({0, src});
	wt[src] = 0;

	while(!pq.empty())
	{
		pii tp = pq.top();
		pq.pop();
		if(vis[tp.s]) continue;
		vis[tp.s] = 1;

		for(pii x : adj[tp.s])
		{
			int w = x.f;
			int j = x.s;
			if(wt[tp.s] + w < wt[j])
			{
				wt[j] = wt[tp.s]+w;
				pq.push({wt[j], j});
				par[j] = tp.s;
			}
		}
	}
}

int main()
{
	freopen("rblock.in", "r", stdin);
	freopen("rblock.out", "w", stdout);
	cin >> N >> M;
	for(int i = 0; i < M; i++)
	{
		int a, b, w; cin >> a >> b >> w;
		--a; --b;
		adj[a].push_back({w, b});
		adj[b].push_back({w, a});
	}
	dijk(0);
	vector<int> V;
	V.push_back(N-1);
	while(par[V.back()] != -1)
	{
		V.push_back(par[V.back()]);
	}
	reverse(V.begin(), V.end());
	/*
	for(int x : V) cerr << x << ' ';
	cerr << endl;
	*/
	int old = wt[N-1], best = wt[N-1];
	for(int i = 0; i < V.size()-1; i++)
	{
		int x = V[i], y = V[i+1];
		int x2 = -1, y2 = -1;
		for(int j = 0; j < adj[x].size(); j++)
		{
			if(adj[x][j].s == y)
			{
				x2 = j;
			}
		}
		for(int j = 0; j < adj[y].size(); j++)
		{
			if(adj[y][j].s == x)
			{
				y2 = j;
			}
		}
		adj[x][x2].f *= 2;
		adj[y][y2].f *= 2;
		dijk(0);
		adj[x][x2].f /= 2;
		adj[y][y2].f /= 2;
		best = max(best, wt[N-1]);
	}
	cout << best-old << endl;
}