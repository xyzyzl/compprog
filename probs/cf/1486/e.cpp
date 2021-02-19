#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // pbds
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>

#pragma GCC optimize("O3")

using namespace __gnu_pbds;
using namespace std;

#define MAXN 5100005

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

int n, m;
ll wt[MAXN];
// each node is the current node + preceding edge weight
vii adj[MAXN];
bool vis[MAXN];
void dijk(int src)
{
	fill(wt, wt + MAXN, 1e15+7);
	fill(vis, vis+MAXN, 0);

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

int sq(int x)
{
	return x*x;
}

void solve()
{
	cin >> n >> m;
	FOR(i, m)
	{
		int u, v, w; cin >> u >> v >> w; --u; --v;
		adj[u*51].pb({0,v*51+w});
		adj[v*51].pb({0,u*51+w});
		F1R(wp, 50)
		{
			adj[u*51+wp].pb({sq(wp+w),v*51});
			adj[v*51+wp].pb({sq(wp+w),u*51});
		}
	}
	set<pii> S;
	dijk(0);
	FOR(i, n)
	{
		cout << (wt[i*51] == (1e15+7) ? -1 : wt[i*51]) << ' ';
	}
	cout << endl;
}

signed main()
{
	// fileio("");
	DUEHOANG;
	int t = 1;
	// cin >> t; // uncomment if it's multitest
	while(t--)
	{
		solve();
	}
	
}
