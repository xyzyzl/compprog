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

int n1, n2, n3, n4;
vi a1, a2, a3, a4;
struct ST
{
	int n, arr[MAXN], st[4*MAXN];
	void build(int node, int a, int b)
	{
		if (a > b)
			return;
		if (a == b)
		{
			st[node] = arr[a];
			return;
		}
		build(LEFT(node), a, (a + b) / 2);
		build(RIGHT(node), (a + b) / 2 + 1, b);

		st[node] = min(st[LEFT(node)], st[RIGHT(node)]);
	}

	int rmq(int node, int a, int b, int i, int j)
	{
		if (a > b || a > j || b < i)
			return INF;
		if (a >= i && b <= j)
			return st[node];

		int q1 = rmq(LEFT(node), a, (a + b) / 2, i, j);
		int q2 = rmq(RIGHT(node), (a + b) / 2 + 1, b, i, j);
		return min(q1, q2); // this operation will change if it becomes something else
	}

	int rmq(int node, int i, int j)
	{
		return rmq(node, 0, n-1, i, j);
	}

	ST(vi a)
	{
		n = a.size();
		FOR(i, n)
		{
			arr[i] = a[i];
		}
		build(1, 0, n-1);
	}
	ST()
	{

	}
} st1, st2, st3;

si d1[MAXN], d2[MAXN], d3[MAXN], d4[MAXN];

void solve()
{
	cin >> n1 >> n2 >> n3 >> n4;
	a1.resize(n1);
	a2.resize(n2);
	a3.resize(n3);
	a4.resize(n4);
	FOR(i, n1) cin >> a1[i];
	FOR(i, n2) cin >> a2[i];
	FOR(i, n3) cin >> a3[i];
	FOR(i, n4) cin >> a4[i];
	int m;
	st1 = ST(a1);
	cin >> m;
	FOR(i, n2)
	{
		d1[i].ins(-1);
		d1[i].ins(n1);
	}
	FOR(i, m)
	{
		int x, y; cin >> x >> y;
		--x; --y;
		d1[y].ins(x);
	}
	int pv = -40;
	FOR(i, n2)
	{
		int mn = 1e9+5;
		for(int x : d1[i])
		{
			if(pv >= -1)
			{
				MIN(mn, st1.rmq(1, pv+1, x-1));
			}
			pv = x;
		}
		a2[i] += mn;
	}
	st2 = ST(a2);
	cin >> m;
	FOR(i, n3)
	{
		d2[i].ins(-1);
		d2[i].ins(n2);
	}
	FOR(i, m)
	{
		int x, y; cin >> x >> y;
		--x; --y;
		d2[y].ins(x);
	}
	pv = -40;
	FOR(i, n3)
	{
		int mn = 1e9+5;
		for(int x : d2[i])
		{
			if(pv >= -1) MIN(mn, st2.rmq(1, pv+1, x-1));
			pv = x;
		}
		a3[i] += mn;
	}
	st3 = ST(a3);
	cin >> m;
	FOR(i, n4)
	{
		d3[i].ins(-1);
		d3[i].ins(n3);
	}
	FOR(i, m)
	{
		int x, y; cin >> x >> y;
		--x; --y;
		d3[y].ins(x);
	}
	pv = -40;
	FOR(i, n4)
	{
		int mn = 1e9+5;
		for(int x : d3[i])
		{
			if(pv >= -1) MIN(mn, st3.rmq(1, pv+1, x-1));
			pv = x;
		}
		a4[i] += mn;
	}
	int mn = INT_MAX;
	for(int x : a4)
	{
		MIN(mn, x);
	}
	if(mn < 1e9) cout << mn << endl;
	else cout << -1 << endl;
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