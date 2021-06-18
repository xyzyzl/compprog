#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // pbds
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>

#pragma GCC optimize("O3")

using namespace __gnu_pbds;
using namespace std;

#define MAXN 300005
#define MAXA 21

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

int q, a0, c0, a[MAXN], c[MAXN], pa[MAXA][MAXN];
void solve()
{
	cin >> q >> a0 >> c0;
	a[0] = a0;
	c[0] = c0;
	int v = 0;
	while(q--)
	{
		int ty; cin >> ty;
		v++;
		if(ty == 1)
		{
			// add vertex i as a son to vertex p[i]
			int p, _a, _c; cin >> p >> _a >> _c;
			a[v] = _a;
			c[v] = _c;

			pa[0][v] = p;
			F1R(i, MAXA-1)
			{
				pa[i][v] = pa[i-1][pa[i-1][v]];
			}
		} else 
		{
			int vv, w; cin >> vv >> w;
			int fwt = 0;
			ll fcs = 0;

			// search for closest nonzero
			while(w > 0 && a[vv] > 0)
			{
				int x = vv;
				FORD(i, MAXA)
				{
					if(a[pa[i][x]] > 0) x = pa[i][x];
				}
				int mn = min(a[x], w);
				a[x] -= mn; w -= mn;

				fwt += mn;
				fcs += (ll)mn*c[x];
			}
			cout << fwt << " " << fcs << endl;
			cout.flush();
		}
	}
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
