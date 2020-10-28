#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // pbds
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>

#pragma GCC optimize("O3")

using namespace __gnu_pbds;
using namespace std;

#define MAXN 1005

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
#define MOD (1e9 * 1) + 7
#define MOD2 998244353
#define INF (1e9 * 1) + 5

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

#define bitinc(x) x & -x

const int MAX(int &a, int b)
{
	return a = max(a, b);
}
const int MIN(int &a, int b)
{
	return a = min(a, b);
}

int n, m, k, wt[MAXN], par[MAXN], ww[MAXN][MAXN];
vi nx[MAXN];
vii adj[MAXN];
viii edg;
map<pii, int> frq;

void dijk(int src)
{
	fill(par, par + n, -1);
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
			if (wt[tp.s] + w < wt[ind] || (wt[tp.s] + w == wt[ind] && tp.s < par[ind]))
			{
				pq.erase(mp(wt[ind], ind)); /// you can't efficiently erase with a priority queue
				/// and you're processing way too many indices
				wt[ind] = wt[tp.s] + w;
				par[ind] = tp.s;
				pq.insert(mp(wt[ind], ind));
			}
		}
	}
}

void solve()
{
	cin >> n >> m >> k;
	FOR(i, m)
	{
		int a, b, w;
		cin >> a >> b >> w;
		--a;
		--b;
		adj[a].pb(mp(w, b));
		adj[b].pb(mp(w, a));
		edg.pb(mp(w, mp(a, b)));
	}
	FOR(i, n)
	{
		dijk(i);
		FOR(j, n)
		{
			ww[i][j] = wt[j];
		}
	}
	vii crit;
	FOR(i, k)
	{
		int p,q; cin >> p >> q;
		--p;
		--q;
		crit.pb(mp(p,q));
	}
	int mn = INF;
	FOR(i, m)
	{
		int ans = 0;
		FOR(j, k)
		{
			int ii = ww[crit[j].f][crit[j].s];
			int jj = ww[crit[j].f][edg[i].s.f]+ww[edg[i].s.s][crit[j].s];
			int kk = ww[crit[j].f][edg[i].s.s]+ww[edg[i].s.f][crit[j].s];
			ans += min(ii,min(jj,kk));
		}
		MIN(mn,ans);
	}
	cout << mn << endl;
}

signed main()
{
	DUEHOANG;
	int t = 1;
	// cin >> t; // uncomment if it's multitest
	while (t--)
	{
		solve();
	}
}
