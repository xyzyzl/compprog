#include <bits/stdc++.h>
 
using namespace std;
 
using ll=long long;
#define int ll
using pii=pair<int, int>; // #define int ll was below using pii=pair<int, int>; so it didn't actually count
#define f first
#define s second
const int MAXN = 100005;
#define pb push_back
#define mp make_pair
 
int n, m;
vector<pii> adj[MAXN];
ll wt[MAXN], dis_U[MAXN], dis_V[MAXN], dis_S[MAXN];
bool vis[MAXN];
ll ans;
 
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
 
ll dp_U[MAXN], dp_V[MAXN];
void dijk_dp(int src, int dest)
{
	fill(dis_S, dis_S+n, 1e15+7);
	fill(dp_U, dp_U+n, 1e15+7);
	fill(dp_V, dp_V+n, 1e15+7);
	fill(vis, vis+n, 0);
	dis_S[src] = 0;
	priority_queue<pair<int, pii>, vector<pair<int, pii>>, greater<pair<int, pii>>> pq;
	pq.push(mp(0, mp(src, -1)));
	while(!pq.empty())
	{
		pair<int, pii> tp = pq.top(); pq.pop();
		int w = tp.f;
		int nd = tp.s.f;
		int par = tp.s.s;
		if(!vis[nd])
		{
			vis[nd] = 1;
			dis_S[nd] = w;
			if(par >= 0) dp_U[nd] = min(dp_U[par], dis_U[nd]);
			else dp_U[nd] = dis_U[nd];
			if(par >= 0) dp_V[nd] = min(dp_V[par], dis_V[nd]);
			else dp_V[nd] = dis_V[nd];
			for(auto x : adj[nd])
			{
				pq.push(mp(w+x.f, mp(x.s,nd)));
			}
		} else if(w == dis_S[nd])
		{
			if(par >= 0 && min(dis_U[nd], dp_U[par]) + min(dis_V[nd], dp_V[par]) <= dp_U[nd]+dp_V[nd])
			{
				dp_U[nd] = min(dis_U[nd], dp_U[par]);
				dp_V[nd] = min(dis_V[nd], dp_V[par]);
			}
		}
	}
	ans = min(ans, dp_U[dest] + dp_V[dest]);
}
 
signed main()
{
	cin >> n >> m;
	int S, T, U, V; cin >> S >> T >> U >> V;
	--S; --T; --U; --V;
	for(int i = 0; i < m; i++)
	{
		int a, b, w; cin >> a >> b >> w;
		--a; --b;
		adj[a].pb(mp(w, b));
		adj[b].pb(mp(w, a));
	}
	dijk(U);
	for(int i = 0; i < n; i++) dis_U[i] = wt[i];
	dijk(V);
	for(int i = 0; i < n; i++) dis_V[i] = wt[i];
	ans = dis_U[V];
	dijk_dp(S, T);
	dijk_dp(T, S);
	cout << ans << endl;
}