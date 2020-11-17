#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // pbds
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>

using namespace std;
using namespace __gnu_pbds;

#pragma GCC optimize("O3")

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
#define MOD (1e9 * 1) + 7
#define MOD2 998244353
#define INF (1e9 * 1) + 5

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

#define bitinc(x) x & -x

const int MAX(int &a, int b)
{
	return a = max(a, b);
}
const int MIN(int &a, int b)
{
	return a = min(a, b);
}

int n;
vi a;
void solve()
{
	cin >> n;
	a.resize(n);
	FOR(i, n)
		cin >> a[i];
	if (n % 2)
	{
		viii mvs;
		for (int i = 0; i < n - 1; i += 2)
		{
			mvs.pb(mp(i + 1, mp(i + 2, i + 3)));
		}
		for (int i = 0; i < n - 1; i += 2)
		{
			mvs.pb(mp(i + 1, mp(i + 2, n)));
		}
		cout << "YES" << endl;
		cout << mvs.size() << endl;
		for (iii x : mvs)
			cout << x.f << ' ' << x.s.f << ' ' << x.s.s << endl;
	}
	else
	{
		int xr = 0;
		FOR(i, n)
		xr ^= a[i];
		if (xr != 0)
			cout << "NO" << endl;
		else
		{
			cout << "YES" << endl;
			viii mvs;
			for (int i = 0; i < n - 2; i += 2)
			{
				mvs.pb(mp(i + 1, mp(i + 2, i + 3)));
			}
			for (int i = 0; i < n - 2; i += 2)
			{
				mvs.pb(mp(i + 1, mp(i + 2, n-1)));
			}
			cout << mvs.size() << endl;
			for (iii x : mvs)
				cout << x.f << ' ' << x.s.f << ' ' << x.s.s << endl;
		}
	}
}

signed main()
{
	DUEHOANG;
	int t = 1;
	// cin >> t; // uncomment if it's multitest
	while (t--)
	{
		solve();
	}
}
