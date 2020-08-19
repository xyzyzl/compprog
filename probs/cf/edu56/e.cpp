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

struct qry
{
	int t;
	int la, ra, lb, rb;
} q[MAXN];

vi f[MAXN];
vi bit[MAXN];

void add_u(int x, int y)
{
	for(int i = x; i < n; i |= i+1)
	{
		bit[i].insert(y);
	}
}

void add_q(int x, int y)
{
	if(x < 0 || y < 0) 
		return;
	for(int i = x; i >= 0; i = (i & (i+1)) - 1)
	{
		bit[i].insert(y);
	}
}

int qry(int x, int y)
{
	if(x < 0 || y < 0) return 0;
	int ret = 0;
	for(int i = x; i >= 0; i = (i & (i+1)) - 1)
	{
		for(int j = lower_bound(vals[i].begin(), vals[i].end(), y) - vals[i].begin(); j >= 0; j = (j & (j+1)) - 1)
			ret += f[i][j];
	}
	return ret;
}

void upd(int x, int y, int v)
{
	for(int i = x; i < n; i |= (i+1))
	{
		for(int j = lower_bound(vals[i].begin(), vals[i].end(), y) - vals[i].begin(); j >= 0; j |= j+1)
			f[i][j] += v;
	}
}
}

int n, m, a[MAXN], b[MAXN];
int pos[MAXN];
void solve()
{
	cin >> n >> m;
	FOR(i, n)
	{
		cin >> a[i];
		--a[i];
		pos[a[i]] = i;
	}
	FOR(i, n)
	{
		cin >> b[i];
		--b[i];
		b[i] = pos[b[i]];
	}
	FOR(i, m)
	{
		int t;
		cin >> t;
		if(t == 1)
		{
			int la, ra, lb, rb;
			cin >> la >> ra >> lb >> rb;
			--la; --lb; --ra; --rb;
			q[i].la = la;
			q[i].ra = ra;
			q[i].lb = lb;
			q[i].rb = rb;
		} else
		{
			int lb, rb;
			cin >> lb >> rb;
			q[i].la = -1;
			q[i].ra = -1;
			q[i].lb = lb;
			q[i].rb = rb;
		}
		q[i].t = t;
	}
	vi tmp(b, b+n);
	FOR(i, n) add_u(i, b[i]);
	FOR(i, m)
	{
		if(q[i].t == 1)
		{
			add_q(
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
