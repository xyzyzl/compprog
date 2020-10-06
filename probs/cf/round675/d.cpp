// Time:
// Algorithms: 

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // pbds
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>

#pragma GCC optimize("O3")

using namespace __gnu_pbds;
using namespace std;

#define MAXN 100005

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

int n, m, wt[MAXN];
pii A, B;
iii pts[MAXN];
vii adj[MAXN];

void dijk(int src)
{
	fill(wt, wt + m, INF);

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

int mdist(pii a, pii b)
{
	return abs(a.f-b.f)+abs(a.s-b.s);
}

void solve()
{
	cin >> n >> m >> A.f >> A.s >> B.f >> B.s;
	FOR(i, m)
	{
		cin >> pts[i].s.f >> pts[i].s.s;
		pts[i].f = i;
	}
	FOR(i, m)
	{
		adj[m].push_back(mp(min(abs(pts[i].s.f-A.f), abs(pts[i].s.s-A.s)), i));
	}
	sort(pts, pts+m, [](iii a, iii b){
		return a.s.s < b.s.s;
	});
	FOR(i, m-1)
	{
		adj[pts[i].f].pb(mp(abs(pts[i].s.s-pts[i+1].s.s), pts[i+1].f));
		adj[pts[i+1].f].pb(mp(abs(pts[i].s.s-pts[i+1].s.s), pts[i].f));
	}
	sort(pts, pts+m, [](iii a, iii b){
		return a.s.f < b.s.f;
	});
	FOR(i, m-1)
	{
		adj[pts[i].f].pb(mp(abs(pts[i].s.f-pts[i+1].s.f), pts[i+1].f));
		adj[pts[i+1].f].pb(mp(abs(pts[i].s.f-pts[i+1].s.f), pts[i].f));
	}
	sort(pts, pts+m);
	dijk(m);
	int ans = mdist(A,B);
	FOR(i, m)
	{
		MIN(ans, mdist(B,pts[i].s)+wt[i]);
	}
	cout << ans << endl;
}

signed main()
{
	DUEHOANG;
	int t = 1;
	// cin >> t; // uncomment if it's multitest
	while(t--)
	{
		solve();
	}
	
}
