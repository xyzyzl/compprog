// Time:
// Algorithms: 

#include <bits/stdc++.h>

#pragma GCC optimize("O3")

using namespace std;

#define MAXN 1000005

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
ll a[MAXN];
void read()
{
	cin >> n >> m;
	FOR(i, n) cin >> a[i];
}

pair<ll, ll> st[4*MAXN];
void build(int nd, int i, int j)
{
	if(i > j) return;
	if(i == j)
	{
		st[nd] = mp(a[i], i);
		return;
	}
	int d = (i + j)/2;
	build(LEFT (nd), i  , d);
	build(RIGHT(nd), d+1, j);
	int a = st[LEFT (nd)].f;
	int b = st[RIGHT(nd)].f;
	int sec = st[LEFT(nd)].s;
	if(b > a) sec = st[RIGHT(nd)].s;
	st[nd] = mp(max(a,b), sec);
}

void upd(int nd, int i, int j, int k, int v)
{
	if(i == j)
	{
		st[nd] = mp(v, k);
		return;
	}
	int d = (i + j)/2;
	if(k <= d) upd(LEFT(nd), i, d, k, v);
	else    upd(RIGHT(nd), d+1, j, k, v);
	int a = st[LEFT (nd)].f;
	int b = st[RIGHT(nd)].f;
	int sec = st[LEFT(nd)].s;
	if(b > a) sec = st[RIGHT(nd)].s;
	st[nd] = mp(max(a,b), sec);
}

pair<ll, ll> rmq(int nd, int i, int j, int l, int r)
{
	if(i > j || i > r || j < l) return mp(-INF, -1);
	if(i >= l && j <= r) return st[nd];

	int d = (i + j)/2;
	pii q1 = rmq(LEFT (nd), i  , d, l, r);
	pii q2 = rmq(RIGHT(nd), d+1, j, l, r);
	int a = q1.f;
	int b = q2.f;
	int sec = q1.s;
	if(b > a) sec = q2.s;
	return mp(max(a,b), sec);
}

ll bit[2 * MAXN];
ll sum(int ind)
{
	ll sm = 0;
	while(ind > 0)
	{
		sm += bit[ind];
		ind -= bitinc(ind);
	}
	return sm;
}

void upd(int ind, ll val)
{
	while(ind <= n)
	{
		bit[ind] += val;
		ind += bitinc(ind);
	}
}

void solve()
{
	build(1, 0, n-1);
	FOR(i, n)
	{
		upd(1+i, a[i]);
	}
	while(m--)
	{
		int cls;
		cin >> cls;
		if(cls == 1)
		{
			int l, r;
			cin >> l >> r;
			// do range sum
			cout << sum(r) - sum(l-1) << endl;
			cout.flush();
		} else if(cls == 2)
		{
			int l, r, mod;
			cin >> l >> r >> mod;
			--l; --r;
			// repeatedly find ind of range max until it's below mod
			pii x = rmq(1, 0, n-1, l, r);
			while(x.f >= mod)
			{
				ll y = a[x.s] % mod;
				upd(1, 0, n-1, x.s, y); // seg tree
				upd(1+x.s, y - a[x.s]); // BIT
				a[x.s] = y;
				x = rmq(1, 0, n-1, l, r);
			}
		} else 
		{
			int k, x;
			cin >> k >> x;
			--k;
			upd(1, 0, n-1, k, x);
			upd(k+1, x - a[k]);
			a[k] = x;
			// range update to set a[k] = x.
		}
	}
}

int main()
{
	DUEHOANG;
	int t = 1;
	// cin >> t; // uncomment if it's multitest
	while(t--)
	{
		read();
		solve();
	}
	
}
