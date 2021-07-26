#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // pbds
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>

#pragma GCC optimize("O3")

using namespace __gnu_pbds;
using namespace std;

#define MAXN 205

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
#define MOD ((1e9*1)+7)
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

typedef set<ll> sl;
typedef vector<ll> vl;
typedef pair<ll, ll> pll;
typedef pair<ll, pll> lll;
typedef vector<pll> vll;
typedef vector<lll> vlll;
typedef priority_queue<ll> pql;
typedef stack<ll> stl;
typedef queue<ll> ql;
typedef deque<ll> dl;
typedef map<ll, ll> mll;

// ordered_set
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> os;
typedef tree<pii, null_type, less<pii>, rb_tree_tag, tree_order_statistics_node_update> osii;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> osll;
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

namespace modOp
{
	int ad(int a, int b, int mod = MOD) { return (a + b) % mod; }
	int sub(int a, int b, int mod = MOD) { return (a - b + mod) % mod; }
	int mul(int a, int b, int mod = MOD) { return (ll)a * b % mod; }

	int AD(int &a, int b, int mod = MOD) { return a = ad(a, b, mod); }
	int SUB(int &a, int b, int mod = MOD) { return a = sub(a, b, mod); }
	int MUL(int &a, int b, int mod = MOD) { return a = mul(a, b, mod); }

	int po(int b, int p, int mod = MOD) { return !p ? 1 : mul(po(mul(b, b, mod), p / 2, mod), p & 1 ? b : 1, mod); }
	int inv(int b, int mod = MOD) { return po(b, mod - 2, mod); }

	int invGeneral(int a, int b)
	{ // 0 < a < b, gcd(a,b) = 1
		if (a == 0)
			return b == 1 ? 0 : -1;
		int x = invGeneral(b % a, a);
		return x == -1 ? -1 : ((1 - (ll)b * x) / a + b) % b;
	}
} // namespace modOp

using namespace modOp;

int n, dep[MAXN], f[MAXN][MAXN];
vi adj[MAXN];
int par[MAXN][20];

void dfs(int v, int p, int d = 0)
{
	dep[v] = d;
	for(int i = 1; i < 20; i++)
		par[v][i] = par[par[v][i-1]][i-1];
	for(int x : adj[v])
	{
		if(x == p) continue;
		dfs(x,v,d+1);
	}
}

// method finding all lca's
int lca(int u, int v)
{
	if(dep[u] < dep[v])
		swap(u, v);
	int df = dep[u] - dep[v];
	for(int i = 0; i < 20; i++)
	{
		if(df & (1 << i)) u = par[u][i];
	}
	if(u == v) return u;
	for(int i = 19; i >= 0; i--)
	{
		if(par[u][i] != par[v][i])
		{
			u = par[u][i];
			v = par[v][i];
		}
	}
	return par[u][0];
}

void solve()
{
	cin >> n;
	FOR(i, n-1)
	{
		int u, v; cin >> u >> v;
		--u; --v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	FOR(i, n) FOR(j, n)
	{
		if(i == 0 && j == 0)
		{
			f[i][j] = 1;
			continue;
		} else if(i == 0)
		{
			f[i][j] = 0;
		} else if(j == 0)
		{
			f[i][j] = 1;
		} else 
		{
			f[i][j] = mul(ad(f[i-1][j], f[i][j-1]), inv(2));
		}
	}

	int prb = 0;
	int ct = 0;
	for(int u = 0; u < n; u++)
	{
		++ct;
		FOR(i, n) dep[i] = 0;
		// r = root
		dfs(u, u);
		FOR(i, n) FORR(i+1, j, n)
		{
			int l = lca(i, j);
			int k1 = dep[i] - dep[l];
			int k2 = dep[j] - dep[l];
			AD(prb, f[k1][k2]);
		}
	}
	cout << mul(prb, inv(n)) << endl;
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
