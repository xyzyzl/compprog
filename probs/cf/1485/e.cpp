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
typedef pair<ll, pii> iii;
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

void solve()
{
	int n; cin >> n;
	vi P(n), a(n), D(n);
	vector<vi> adj(n);
	vector<viii> adj2(n);
	function<void(int,int)> dfs;
	F1R(i, n-1)
	{
		int x; cin >> x; --x;
		adj[i].pb(x);
		adj[x].pb(i);
	}
	D[0] = 0;
	dfs = [adj,&adj2,&P,&dfs,&D](int v, int p) -> void
	{
		P[v] = p;
		for(int x : adj[v])
		{
			if(x == p) continue;
			D[x] = D[v]+1;
			adj2[D[x]].pb(mp(-1, mp(v, x)));
			dfs(x, v);
		}
	};
	int dep = 0;
	vector<ll> dp(n);
	dp[0] = 0;
	dfs(0, -1);
	FOR(i, n) MAX(dep, D[i]);
	F1R(i, n-1) cin >> a[i];
	F1R(i, dep)
	{
		for(auto& x : adj2[i])
		{
			x.f = a[x.s.s];
		}
		sort(adj2[i].begin(), adj2[i].end());
		ll x = adj2[i][0].f;
		ll y = adj2[i].back().f;
		// no swap
		for(auto& z : adj2[i])
		{
			ll a1 = a[z.s.s];
			dp[z.s.s] = max(dp[z.s.s], max(dp[z.s.f]+a1-x, dp[z.s.f]+y-a1));
		}
		// it seems that swapping is the real problem here
		// swap w small
		int id = 0;
		FOR(j, adj2[i].size())
		{
			if(dp[adj2[i][j].s.f] - adj2[i][j].f > dp[adj2[i][id].s.f] - adj2[i][id].f) id=j;
			dp[adj2[i][j].s.s] = max(dp[adj2[i][j].s.s], (adj2[i][j].f - adj2[i][id].f) + dp[adj2[i][id].s.f]);
		}
		// swap w big
		id = adj2[i].size()-1;
		FORD(j, adj2[i].size())
		{
			if(dp[adj2[i][j].s.f] + adj2[i][j].f > dp[adj2[i][id].s.f] + adj2[i][id].f) id=j;
			dp[adj2[i][j].s.s] = max(dp[adj2[i][j].s.s], (adj2[i][id].f - adj2[i][j].f) + dp[adj2[i][id].s.f]);
		}
	}
	ll ans = 0;
	F1R(i, n-1)
	{
		ans = max(ans, dp[i]);
	}
	cout << ans << endl;
}

signed main()
{
	// fileio("");
	DUEHOANG;
	int t = 1;
	cin >> t; // uncomment if it's multitest
	while(t--)
	{
		solve();
	}
	
}
