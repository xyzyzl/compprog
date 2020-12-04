#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // pbds
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>

#pragma GCC optimize("O3")

using namespace __gnu_pbds;
using namespace std;

#define MAXN 505

#define FOR(i, n) for (int i = 0; i < n; i++)
#define FORR(j, i, n) for (int i = j; i < n; i++)
#define FORD(i, n) for (int i = n - 1; i >= 0; i--)
#define F1R(i, n) for (int i = 1; i <= n; i++)
#define F1RD(i, n) for (int i = n; i >= 1; i--)
#define pb push_back
#define mp make_pair
#define ins insert
#define endl '\n'
#define DUEHOANG                  \
	ios_base::sync_with_stdio(0); \
	cin.tie(NULL);                \
	cout.tie(NULL)
#define fileio(file) freopen(file ".in", "r", stdin); freopen(file ".out", "w", stdout)
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

int n, m, X, wt[MAXN];
set<iii> adj[MAXN];
vector<pair<pii, pii> > edg;
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

		for (iii gu : adj[tp.s])
		{
			int w = gu.s.f;
			int ind = gu.f;
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

void solve()
{
	cin >> n >> m >> X;
	FOR(i, m)
	{
		int a, b, l, c; cin >> a >> b >> l >> c;
		--a; --b;
		adj[a].ins(mp(b, mp(l, c)));
		adj[b].ins(mp(a, mp(l, c)));
		edg.pb(mp(mp(c,l), mp(a,b)));
		edg.pb(mp(mp(c,l), mp(b,a)));
	}
	sort(edg.begin(), edg.end());
	int ans = INT_MAX;
	for(auto e : edg)
	{
		dijk(0);
		int a = wt[e.s.f];
		dijk(n-1);
		int b = wt[e.s.s];
		MIN(ans, a+b+e.f.s + X/e.f.f);
		adj[e.s.f].erase(adj[e.s.f].lower_bound(mp(e.s.s, mp(-1, -1))));
	}
	cout << ans << endl;
}

signed main()
{
	fileio("mroute");
	DUEHOANG;
	int t = 1;
	// cin >> t; // uncomment if it's multitest
	while(t--)
	{
		solve();
	}
	
}
