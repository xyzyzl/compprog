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

typedef set<ll> sl;
typedef vector<ll> vl;
typedef pair<ll, ll> pll;
typedef pair<ll, pll> lll;
typedef vector<pll> vll;
typedef vector<lll> vlll;
typedef priority_queue<ll> pql;
typedef stack<ll> stl;
typedef queue<ll> ql;
typedef deque<ll> dl;
typedef map<ll, ll> mll;

// ordered_set
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> os;
typedef tree<pii, null_type, less<pii>, rb_tree_tag, tree_order_statistics_node_update> osii;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> osll;
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
	int x; cin >> x;
	vector<int> a(n); for(int i = 0; i < n; i++) cin >> a[i];
	vector<int> dp(n+1, -1e9);
	for(int i = 0; i < n; i++)
	{
		int s = 0;
		for(int j = i; j < n; j++)
		{
			s += a[j];
			dp[j-i+1] = max(dp[j-i+1], s);
		}
	}
	for(int k = 0; k <= n; k++)
	{
		int ans = 0;
		// add x to k numbers
		for(int j = 1; j <= n; j++)
		{
			ans = max(ans, dp[j]+x*min(j,k));
		}
		cout << ans << ' ';
	}
	cout << endl;
}

signed main()
{
	// fileio("");
	DUEHOANG;
	int t = 1;
	cin >> t; // uncomment if it's multitest
	while(t--)
	{
		solve();
	}
	
}