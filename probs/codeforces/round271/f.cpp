// Time:
// Algorithms: 

#include <bits/stdc++.h>

#pragma GCC optimize("O3")

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

int n, arr[MAXN];
pii st[4*MAXN], pts[MAXN];
int tree2[MAXN];

void build(int node, int a, int b) {
	if (a > b) return;
	if (a == b) {
		st[node] = mp(arr[a], arr[a]);
		return;
	}
	build(LEFT(node), a, (a + b) / 2);
	build(RIGHT(node), (a + b) / 2 + 1, b);

	st[node].f = min(st[LEFT(node)].f, st[RIGHT(node)].f);
	st[node].s = __gcd(st[LEFT(node)].s, st[RIGHT(node)].s);
}

pii rmq(int node, int a, int b, int i, int j) {
	if (a > b || a > j || b < i) return mp(INF, 0);
	if (a >= i && b <= j) return st[node];

	pii q1 = rmq(LEFT(node), a, (a + b) / 2, i, j);
	pii q2 = rmq(RIGHT(node), (a + b) / 2 + 1, b, i, j);
	return mp(min(q1.f, q2.f), __gcd(q1.s, q2.s)); // this operation will change if it becomes something else
}

void read()
{
	cin >> n;
	FOR(i,n)
	{
		cin >> arr[i];
		pts[i] = mp(arr[i], i);
	}
	sort(pts, pts+n);
	build(1, 0, n-1);
}

void solve()
{
	int t;
	cin >> t;
	while(t--)
	{
		int l, r;
		cin >> l >> r;
		--l; --r;
		pii pierogi = rmq(1, 0, n-1, l, r);
		cerr << pierogi.f << " " << pierogi.s << endl;
		if(pierogi.f != pierogi.s)
		{
			cout << 5 << endl;
			continue;
		} else 
		{
			cout << pierogi.f << endl;
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
