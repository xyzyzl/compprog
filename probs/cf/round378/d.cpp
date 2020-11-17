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

void solve()
{
	int n; cin >> n;
	viii v(n);
	FOR(i, n) cin >> v[i].f >> v[i].s.f >> v[i].s.s;
	map<pii, set<pii> > m;
	int as1 = -1, as2 = -1;
	int x = 0;
	FOR(i, n)
	{
		m[mp(min(v[i].s.f, v[i].s.s), max(v[i].s.f, v[i].s.s))].insert(mp(v[i].f,i+1));
		m[mp(min(v[i].f, v[i].s.s), max(v[i].f, v[i].s.s))].insert(mp(v[i].s.f,i+1));
		m[mp(min(v[i].f, v[i].s.f), max(v[i].f, v[i].s.f))].insert(mp(v[i].s.s,i+1));
		int rad = min(v[i].f, min(v[i].s.f, v[i].s.s));
		if(rad > as1) x=i+1;
		MAX(as1, rad);
	}
	int y = 0, z = 0;
	for(auto k : m)
	{
		pii x = k.f;
		if(m[x].size() < 2) continue;
		int a = prev(m[x].end())->s, b = prev(prev(m[x].end()))->s;
		if(a==b) continue;
		int nh = prev(m[x].end())->f + prev(prev(m[x].end()))->f;
		int rad = min(nh, min(x.f, x.s));
		if(rad > as2) y=a,z=b;
		MAX(as2, rad);
	}
	if(as1 > as2)
	{
		cout << 1 << endl;
		cout << x << endl;
	} else
	{
		cout << 2 << endl;
		cout << y << ' ' << z << endl;
	}
}

signed main()
{
	DUEHOANG;
	int t = 1;
	// cin >> t; // uncomment if it's multitest
	while(t--)
	{
		solve();
	}
	
}
