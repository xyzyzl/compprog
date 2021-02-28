#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // pbds
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>

#pragma GCC optimize("O3")

using namespace __gnu_pbds;
using namespace std;

#define MAXN 5005

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
#define MOD (int)((1e9*1)+7)
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

int n, k, q, dp[MAXN][MAXN];
ll a[MAXN], ct[MAXN];
ll ans = 0;
void solve()
{
	cin >> n >> k >> q;
	FOR(i, n) cin >> a[i];
	FOR(i, n)
	{
		dp[i][0] = 1;
	}
	F1R(i, MAXN-1)
	{
		dp[0][i] = dp[1][i-1];
		FORR(1, j, n-1)
		{
			dp[j][i] = (dp[j-1][i-1] + dp[j+1][i-1]) % MOD;
		}
		dp[n-1][i] = dp[n-2][i-1];
	}
	FOR(i, n)
	{
		FOR(j, k+1)
		{
			ct[i] += dp[i][j]*dp[i][k-j];
			ct[i] %= MOD;
		}
	}
	FOR(i, n)
	{
		ans = (ans + a[i]*ct[i])%MOD;
	}
	// now need to make dynamic updates
	while(q--)
	{
		int i, x; cin >> i >> x; --i;
		ans = (ans + MOD - a[i]*ct[i]) % MOD;
		a[i] = x;
		ans = (ans + a[i]*ct[i]) % MOD;
		cout << (ans+MOD)%MOD << endl;
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
