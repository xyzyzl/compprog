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
#define ins insert
#define endl '\n'
#define DUEHOANG                  \
	ios_base::sync_with_stdio(0); \
	cin.tie(NULL);                \
	cout.tie(NULL)
#define fileio(file) freopen(file ".in", "r", stdin); freopen(file ".out", "w", stdout)
#define ll long long
#define int ll
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

<<<<<<< HEAD
const int MAXN = 200005;
int mn;
int sz[MAXN], vs[MAXN];
vector<int> V;
vector<pii> adj[MAXN];
=======
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

int n, MOD, sz[MAXN], vs[MAXN];
ll mn, up[MAXN], dn[MAXN], h[MAXN];
vi rem;
vii adj[MAXN];

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
>>>>>>> b0ef26739048239b4ad55afc2b43fb9f4c7957b8

// find subtree size
int sub_size(int v, int p)
{
	if(p == -1) rem.clear();
	rem.pb(v);
	sz[v] = 1;
<<<<<<< HEAD
	if(p == -1) V.clear();
	V.push_back(v);
	for(int i = 0; i < adj[v].size(); i++)
=======
	FOR(i, adj[v].size())
>>>>>>> b0ef26739048239b4ad55afc2b43fb9f4c7957b8
	{
		pii x = adj[v][i];
		if(x.f==p || vs[x.f]) continue;
		sz[v] += sub_size(x.f, v);	
	}
	return sz[v];
}

// get the centroid
void get_c(int v, int p, int m, int& ret)
{
	int mx = m - sz[v];
	FOR(i, adj[v].size())
	{
		pii x = adj[v][i];
		if(x.f == p || vs[x.f]) continue;
		get_c(x.f,v,m,ret);
		MAX(mx, sz[x.f]);
	}
	if(mx < mn)
	{
		mn = mx;
		ret = v;
	}
}

<<<<<<< HEAD
ll up[MAXN], dn[MAXN], ht[MAXN];
ll calc(int cen)
{
	for(int i = 0; i < V.size(); i++) 
	{
		up[V[i]] = 0, dn[V[i]] = 0, ht[V[i]] = 0;
	}
	
}

ll solve(int v)
=======
int pts = 0;
int dp[MAXN];
// get decomposition of centroid
void get_d(int v, int p, int c)
>>>>>>> b0ef26739048239b4ad55afc2b43fb9f4c7957b8
{
	if(p == c)
	{
		dp[v] = pts++;
	} else if(p != -1)
	{
		dp[v] = dp[p];
	}
	for(pii y : adj[v])
	{
		int x = y.f, w = y.s;
		if(x == p || vs[x]) continue;
		dn[x] = ad(mul(dn[v], 10), w);
		up[x] = ad(up[v], mul(po(10, h[v]), w));
		h[x] = h[v]+1;
		get_d(x, v, c);
	}
} 

// try to find the number of paths going through this centroid
ll solv(int cen)
{
	for(int x : rem)
	{
		up[x] = 0;
		dn[x] = 0;
		h[x] = 0;
	}
	pts = 0;
	get_d(cen, -1, cen);
	--pts;
	// centroid cannot be in a subtree
	dp[cen] = -1;
	// all paths up from x
	map<ll, ll> tot;
	tot[0]++;
	// all paths up from x in subtree
	vector<map<ll, ll> > V;
	V.resize(pts+1);
	for(int x : rem)
	{
		if(x == cen) continue;
		tot[up[x]]++;
		V[dp[x]][up[x]]++;
	}
	ll ans = 0;
	for(int x : rem)
	{
		int hh = h[x];
		int pt = dp[x];
		if(x == cen)
		{
			ans += tot[0] - 1;
		} else 
		{
			ll val = ((-dn[x])%MOD+MOD)%MOD;
			val = mul(val, inv(po(10, hh)));
			ans += tot[val] - V[pt][val];
		}
	}
	return ans;
}


ll get(int v)
{
	mn = LLONG_MAX;
	// root tree at v
	int m = sub_size(v, -1);
	// gets the centroid
	int cen; get_c(v, -1, m, cen);
	ll ret = solv(cen);
	// cerr << vs[cen] << endl;
	vs[cen] = 1;
	// find thing adjacent to the centroid
	FOR(i, adj[cen].size())
	{
		pii x = adj[cen][i];
		if(vs[x.f]) continue;
		// try to find the number of paths going through this subtree
		ret += get(x.f);
	}
	return ret;
} 

void solve()
{
	cin >> n >> MOD;
	if(MOD == 1)
	{
		cout << (ll)n*(ll)(n-1) << endl;
		return;
	}
	FOR(i, n-1)
	{
		int a, b, w; cin >> a >> b >> w;
		adj[a].pb({b, w});
		adj[b].pb({a, w});
	}
	cout << get(0) << endl;
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
