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

void solve()
{
	int n; cin >> n;
	vi v(1+n), c(1+n), smax(n+2), v0, v1;
	bool can = 1;
	FOR(i, n)
	{
		int a, b; cin >> a >> b;
		int cst = 0;
		if(a > b)
		{
			cst++; swap(a, b);
		}
		if(a <= n)
		{
			v[a] = b;
			c[a] = cst;
		} else
		{
			can = 0;
		}
	}
	if(!can) cout << -1 << endl;
	else 
	{
		smax[n+1] = -1;
		F1RD(i, n)
		{
			smax[i] = max(smax[i+1], v[i]);
		}
		int pmin = INT_MAX;
		int c0 = 0, c1 = 0, ans = 0;
		// make two subsequences with decreasing
		F1R(i, n)
		{
			MIN(pmin, v[i]);
			if(v0.empty() || v[v0.back()] > v[i])
			{
				v0.pb(i);
				c0 += c[i];
			} else if(v1.empty() || v[v1.back()] > v[i])
			{
				v1.pb(i);
				c1 += c[i];
			} else
			{
				cout << -1 << endl;
				return;
			}

			if(pmin > smax[i+1]) 
			{
				int s0 = v0.size(), s1 = v1.size();
				ans += min(c0+s1-c1, s0-c0+c1);
				c0 = c1 = 0;
				v0.clear();
				v1.clear();
			}
		}
		cout << ans << endl;
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
