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

// store in a seg tree
int n;
string arr;
iii st[4000005];
void build(int node, int a, int b)
{
	if (a > b) return;
	if (a == b) {
		st[node].f = 0;
		st[node].s.f = (arr[a] == '(');
		st[node].s.s = (arr[a] == ')');
		return;
	}
	build(LEFT(node), a, (a + b) / 2);
	build(RIGHT(node), (a + b) / 2 + 1, b);

	int t = min(st[LEFT(node)].s.f, st[RIGHT(node)].s.s);
	st[node].f = st[LEFT(node)].f + st[RIGHT(node)].f + 2*t;
	st[node].s.f = st[LEFT(node)].s.f + st[RIGHT(node)].s.f - t;
	st[node].s.s = st[LEFT(node)].s.s + st[RIGHT(node)].s.s - t;
}

iii query(int node, int a, int b, int i, int j)
{
	if (a > b || a > j || b < i) return mp(0, mp(0, 0));
	if (a >= i && b <= j)
	{
		return st[node];
	}

	iii q1 = query(LEFT(node), a, (a + b) / 2, i, j);
	iii q2 = query(RIGHT(node), (a + b) / 2 + 1, b, i, j);
	// cout << min(st[LEFT(node)].s.f, st[RIGHT(node)].s.s) << endl;
	int t = min(q1.s.f, q2.s.s);
	return mp(q1.f + q2.f + 2*t, mp(q1.s.f + q2.s.f - t, q1.s.s + q2.s.s - t));
}

void read()
{
	cin >> arr;
	n = arr.length();
	build(1, 0, n);
}

void solve()
{
	// would be part of read but online is cool
	int m;
	cin >> m;
	while(m--)
	{
		int l, r;
		cin >> l >> r;
		--l; --r;
		cout << query(1, 0, n, l, r).f << endl;
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
