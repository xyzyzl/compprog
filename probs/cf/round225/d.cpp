#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // pbds
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>

#pragma GCC optimize("O3")

using namespace __gnu_pbds;
using namespace std;

#define MAXN 1005
#define MAXS 20005

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

int n, a[MAXN];
int dp[MAXN][MAXS];
void solve()
{
	cin >> n;
	int total = 0;
	F1R(i, n)
	{
		cin >> a[i];
		total += a[i];
	}
	const int zero = total;
	dp[0][zero]=1;
	int ans = 0;
	F1R(i, n)
	{
		FOR(j, MAXS)
		{
			if(j - a[i] >= 0)
			{
				dp[i][j] += dp[i-1][j-a[i]];
				dp[i][j] %= MOD;
			}
			if(j + a[i] < MAXS)
			{
				dp[i][j] += dp[i-1][j+a[i]];
				dp[i][j] %= MOD;
			}
		}
		ans = (ans+dp[i][zero])%MOD; // from some zero to some other zero
		// can start from any prior index, but not the current index
		dp[i][zero] = (dp[i][zero]+1)%MOD; // can now start from this index for future indices.
	}
	cout << ans << endl;
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