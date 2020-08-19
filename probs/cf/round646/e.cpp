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

int n, b[MAXN];
ll a[MAXN];
vi adj[MAXN];
void dfs(int v, int p)
{
	for(int x : adj[v])
	{
		if(x == p) continue;
		a[x] = min(a[x], a[v]);	
		dfs(x, v);
	}
}

ll best = 0;
pii calc(int v, int p)
{
	pii ret = mp(0, 0);
	if(b[v] == 1) ret.f++;
	else if(b[v] == 2) ret.s++;
	for(int x : adj[v])
	{
		if(x == p) continue;
		pii nxt = calc(x, v);
		ret.f += nxt.f;
		ret.s += nxt.s;
	}
	if(ret.f && ret.s)
	{
		ll q = min(ret.f, ret.s);
		ret.f -= q;
		ret.s -= q;
		best += (2ll * q) * a[v];
	}
	return ret;
}

void solve()
{
	cin >> n;
	FOR(i, n)
	{
		cin >> a[i];
		int p, q;
		cin >> p >> q;
		if(p == q) continue;
		if(!p) b[i] = 1;
		else b[i] = 2;
	}
	FOR(i, n-1)
	{
		int p, q;
		cin >> p >> q;
		--p; --q;
		adj[p].pb(q);
		adj[q].pb(p);
	}
	int ret = 0;
	FOR(i, n)
	{
		if(b[i] == 1) ret ++;
		else if(b[i] == 2) ret --;
	}
	if(ret != 0)
	{
		cout << -1 << endl;
		return;
	}
	// else this has to be possible
	dfs(0, -1); // propagate lengths
	pii fin = calc(0, -1);
	if(fin.f != 0 || fin.s != 0) 
	{
		// to make foolproof
		cout << -1 << endl;
	} else 
	{
		cout << best << endl;
	}
}

int main()
{
	DUEHOANG;
	int t = 1;
	// cin >> t; // uncomment if it's multitest
	while(t--)
	{
		solve();
	}
	
}

