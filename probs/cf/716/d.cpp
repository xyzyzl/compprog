#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define f first
#define mp make_pair
#define s second

const int MAXN = 1005;
const ll INF = 1e9+7;

int n, m, vis[MAXN], par[MAXN];
ll wt[MAXN], D[MAXN][MAXN];
vector<pair<ll, int> > adj[MAXN];
vector<pair<ll, pii> > eg;

void dijk(int src)
{
	fill(wt, wt + n, 1e15+7);
	fill(vis, vis+n, 0);
	fill(par, par+n, -1);

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
				par[ind] = tp.s;
				pq.push(mp(wt[ind], ind));
			}
		}
	}
}

ll L, dd[MAXN];
int fr, to;

bool ass()
{
	for(int i = 0; i < n; i++) dd[i] = INF;
	dd[fr] = 0;
	priority_queue<pii, vector<pii>, greater<pii> > pq;
	pq.push({0, fr});
	while(!pq.empty())
	{
		pii tp = pq.top();
		pq.pop();
		int v = tp.s;
		for(auto x : adj[v])
		{
			int ind = x.s;
			ll w = abs(D[v][ind]);
			if(tp.f + abs(w) < dd[ind])
			{
				dd[ind] = tp.f + abs(w);
				par[ind] = v;
				pq.push({dd[ind], ind});
			}
		}
	}
	if(dd[to] == L) return 1;
	int x = to;
	while(x != fr)
	{
		int p = par[x];
		if(D[p][x] < 0)
		{
			ll d = abs(D[p][x]);
			D[p][x] = D[x][p] = d+L-dd[to];
			break;
		}
		x = p;
	}
	return 0;
}

int main()
{
	cin >> n >> m;
	cin >> L >> fr >> to;
	for(int i = 0; i < m; i++)
	{
		int a, b, w; cin >> a >> b >> w;
		adj[a].push_back({(w > 0 ? w : INF), b});
		adj[b].push_back({(w > 0 ? w : INF), a});
		D[a][b] = D[b][a] = (w > 0 ? w : -1);
		eg.push_back({w, {a, b}});
	}
	dijk(fr);
	if(wt[to] < L)
	{
		cout << "NO" << endl;
		return 0;
	} else if(wt[to] == L)
	{
		cout << "YES" << endl;
		for(int i = 0; i < m; i++)
		{
			cout << eg[i].s.f << " " << eg[i].s.s << " " << (eg[i].f ? eg[i].f : INF) << endl;
		}
		return 0;
	}
	for(int i = 0; i < n; i++) adj[i].clear();
	for(int i = 0; i < m; i++)
	{
		int a = eg[i].s.f, b = eg[i].s.s, w = eg[i].f;
		if(!w) w = 1;
		adj[a].push_back({w, b});
		adj[b].push_back({w, a});
	}
	dijk(fr);
	if(wt[to] > L)
	{
		cout << "NO" << endl;
		return 0;
	}	
	cout << "YES" << endl;
	int x = to;
	// add everything NOT along sp to infinity
	while(x != fr)
	{
		int p = par[x];
		if(D[p][x] < 0)
		{
			D[p][x] = D[x][p] = -2;
		}
		x = p;
	}
	for(int i = 0; i < n; i++) for(int j = 0; j < n; j++)
	{
		if(D[i][j] == -1) D[i][j] = INF;
	}
	x=to;
	while(x != fr)
	{
		int p = par[x];
		if(D[p][x] < 0)
		{
			D[p][x] = D[x][p] = -1;
		}
		x = p;
	}
	while(!ass())
	{
		ass();
	}
	for(int i = 0; i < m; i++)
	{
		cout << eg[i].s.f << " " << eg[i].s.s << " " << abs(D[eg[i].s.f][eg[i].s.s]) << endl;
	}
}