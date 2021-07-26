#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // pbds
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>

#pragma GCC optimize("O3")

using namespace __gnu_pbds;
using namespace std;

#define MAXN 505
#define int long long

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

int n, A[MAXN], dp[MAXN][MAXN];
const int MOD = 998244353;
void solve()
{
	cin >> n;
	FOR(i, n)
	{
		char c; cin >> c;
		if(c == '+') cin >> A[i];
		else A[i] = -1;
	}
	ll ans = 0;
	FOR(rp, n)
	{
		if(A[rp] != -1)
		{
			FOR(i, n+1) FOR(j, n+1)
			{
				dp[i][j] = 0;
			}
			dp[0][0] = 1;
			// do nothing
			F1R(i, n)
			{
				FOR(j, n+1) dp[i][j] = dp[i-1][j];
				// take one out from previous
				if(A[i-1] == -1)
				{
					if(i <= rp) dp[i][0] = (dp[i][0] + dp[i-1][0]) % MOD;
					FOR(j, n) dp[i][j] = (dp[i][j] + dp[i-1][j+1]) % MOD;
				} else if(A[i-1] < A[rp] || ((i-1 < rp) && A[i-1] == A[rp]))
				{
					// add one element at a point before or below ind. i
					F1R(j, n) dp[i][j] = (dp[i][j] + dp[i-1][j-1]) % MOD; 
				} else if(A[i-1] > A[rp] || ((i-1 > rp) && A[i-1] == A[rp]))
				{
					// add one element after
					FOR(j, n+1) dp[i][j] = (dp[i][j] + dp[i-1][j]) % MOD;
				}
			}
			FOR(i, n+1)
			{
				ans = (ans + (((ll)A[rp])*dp[n][i]) % MOD) % MOD;
			}
		}
	}
	cout << ans << endl;
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
