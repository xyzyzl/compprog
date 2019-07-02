#include <bits/stdc++.h>

using namespace std;
  

#define int long long
#define MAXN 100005
#define INF (int)(1e15+7)
#define FOR(i, n) for(int i = 0; i < n; i++)
#define FORD(i, n) for(int i = n-1; i >= 0; i--)
#define FOBIR(i, n) for(int i = 1; i <= n; i++)
#define pb push_back
#define mp make_pair
#define endl '\n'
#define DUEHOANG ios_base::sync_with_stdio(0); cin.tie(); cout.tie()
 
typedef set<int> si;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef priority_queue<int> pqi;
typedef stack<int> sti;
typedef queue<int> qi;
typedef deque<int> di;
typedef map<int, int> mii;
#define f first
#define s second
typedef vector<pair<int, int> > vii;
typedef set<pii> sii;

int n, m, wt[MAXN], wtn[MAXN];
vii adj[MAXN];
vector<pair<int, pii> > edg;

void not_prim(int src)
{
	fill(wt, wt + n, INF);

	priority_queue<pii, vector<pii>, greater<pii> > pq;
	pq.push(mp(0, src));

	wt[src] = 0;

	int ct = 0;
	while (!pq.empty())
	{
		pii tp = pq.top();
        pq.pop();

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

int32_t main()
{
    cin >> n >> m;
    FOR(i, m)
    {
        int a, b, w;
        cin >> a >> b >> w;
        a--; b--;
        adj[a].pb(mp(w, b));
        edg.pb(mp(w, mp(a, b)));
    }
    not_prim(0);
    FOR(i, n) wtn[i] = wt[i];
    FOR(i, n) 
    {
        adj[i].clear();
    }
    for(pair<int, pii> edge : edg)
    {
        adj[edge.s.s].pb(mp(edge.f, edge.s.f));
    }
    not_prim(n-1);
    int best = LLONG_MAX;
    for(pair<int, pii> half : edg)
    {
        best = min(best, wtn[half.s.f] + half.f/2 + wt[half.s.s]);
    }
    cout << best << endl;
}