// Time:
// Algorithms: 

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // pbds
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>

#pragma GCC optimize("O3")

using namespace __gnu_pbds;
using namespace std;

#define MAXN 200005

#define FOR(i, n) for (int i = 0; i < n; i++)
#define FORR(j, i, n) for (int i = j; i < n; i++)
#define FORD(i, n) for (int i = n - 1; i >= 0; i--)
#define F1R(i, n) for (int i = 1; i <= n; i++)
#define F1RD(i, n) for (int i = n; i >= 1; i--)
#define pb push_back
#define mp make_pair
#define endl '\n'
#define DUEHOANG                  \
	ios_base::sync_with_stdio(0); \
	cin.tie(NULL);                \
	cout.tie(NULL)

#define fileio(in, out)      \
	freopen(in, "r", stdin); \
	freopen(out, "w", stdout);

#define ll long long
#define MOD (1e9*1)+7
#define MOD2 998244353
#define INF (1e9*1)+5

typedef set<int> si;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<int, pii> iii;
typedef vector<pii> vii;
typedef vector<iii> viii;
typedef priority_queue<int> pqi;
typedef stack<int> sti;
typedef queue<int> qi;
typedef deque<int> di;
typedef map<int, int> mii;
// ordered_set
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> os;
#define f first
#define s second

#define LEFT(x) 2 * x
#define RIGHT(x) 2 * x + 1

#define bitinc(x) x&-x

const int MAX(int &a, int b)
{
	return a = max(a, b); 
}
const int MIN(int &a, int b)
{
	return a = min(a, b); 
}

int n, m, wt[MAXN];
viii adj[MAXN];

// dijkstra
void dijkstra(int src, int flw)
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

		for (iii gu : adj[tp.s])
		{
			int w = gu.f;
			if(gu.s.f < flw) continue; // only if flow is greater
			int ind = gu.s.s;
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
vector<pair<pii, pii>> edges;
void solve()
{
	cin >> n >> m;
	FOR(i, m)
	{
		int a, b, c, f;
		cin >> a >> b >> c >> f;
		a--; b--;
		adj[a].pb(mp(c, mp(f,b)));
		adj[b].pb(mp(c, mp(f,a)));
		edges.pb(mp(mp(f,c), mp(a,b)));
		edges.pb(mp(mp(f,c), mp(b,a)));
	}
	// loop through all edges.
	ll mx = 0;
	for(pair<pii, pii> x : edges)
	{
		ll flw = x.f.f;
		dijkstra(0, flw);
		int a = wt[x.s.f];
		dijkstra(n-1, flw);
		int b = wt[x.s.s];
		if(a == INF || b == INF) continue;
		ll cost = a+b+x.f.s;
		mx = max(mx, (flw * 1000000ll) / cost);
	}
	cout << mx << endl;
}

int main()
{
	fileio("pump.in", "pump.out");
	DUEHOANG;
	int t = 1;
	// cin >> t; // uncomment if it's multitest
	while(t--)
	{
		solve();
	}
	
}

