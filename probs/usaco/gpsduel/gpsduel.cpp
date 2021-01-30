#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // pbds
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>

#pragma GCC optimize("O3")

using namespace __gnu_pbds;
using namespace std;

#define MAXN 10005

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
#define int ll
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

int n, m, wt[MAXN], wt2[MAXN], wt3[MAXN];
vii adj[MAXN], adj2[MAXN], adj3[MAXN];
map<pii, int> eg;

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

void dijk2(int src)
{
	fill(wt2, wt2 + n, INF);

	set<pii> pq;
	pq.insert(mp(0, src));

	wt2[src] = 0;

	int ct = 0;
	while (!pq.empty())
	{
		pii tp = *pq.begin();
		pq.erase(pq.begin());

		for (pii gu : adj2[tp.s])
		{
			int w = gu.f;
			int ind = gu.s;
			if (wt2[tp.s] + w < wt2[ind])
			{
				pq.erase(mp(wt2[ind], ind)); /// you can't efficiently erase with a priority queue
				/// and you're processing way too many indices
				wt2[ind] = wt2[tp.s] + w;
				pq.insert(mp(wt2[ind], ind));
			}
		}
	}
}

void dijk3(int src)
{
	fill(wt3, wt3 + n, INF);

	set<pii> pq;
	pq.insert(mp(0, src));

	wt3[src] = 0;

	int ct = 0;
	while (!pq.empty())
	{
		pii tp = *pq.begin();
		pq.erase(pq.begin());

		for (pii gu : adj3[tp.s])
		{
			int w = gu.f;
			int ind = gu.s;
			if (wt3[tp.s] + w < wt3[ind])
			{
				pq.erase(mp(wt3[ind], ind)); /// you can't efficiently erase with a priority queue
				/// and you're processing way too many indices
				wt3[ind] = wt3[tp.s] + w;
				pq.insert(mp(wt3[ind], ind));
			}
		}
	}
}

void solve()
{
	cin >> n >> m;
	FOR(i, m)
	{
		int a, b, w, v; cin >> a >> b >> w >> v; --a; --b;
		adj[b].pb(mp(w,a));
		adj2[b].pb(mp(v,a));
	}
	dijk(n-1);
	dijk2(n-1);
	FOR(i, n)
	{
		FOR(j, adj[i].size())
		{
			pii x = adj[i][j];
			pii y = adj2[i][j];
			int c=0;
			int w = x.f;
			int k = x.s;
			if(wt[k] != wt[i] + w)
			{
				c++;
			}
			w = y.f;
			k = y.s;
			if(wt2[k] != wt2[i]+w)
			{
				c++;
			}
			adj3[k].pb(mp(c, i));
		}
	}
	dijk3(0);
	cout << wt3[n-1] << endl;
}

signed main()
{
	fileio("gpsduel");
	DUEHOANG;
	int t = 1;
	// cin >> t; // uncomment if it's multitest
	while(t--)
	{
		solve();
	}
	
}
