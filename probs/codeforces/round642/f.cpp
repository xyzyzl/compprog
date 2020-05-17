// Time:
// Algorithms: 

#include <bits/stdc++.h>

#pragma GCC optimize("O3")

using namespace std;

#define MAXN 105

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
#define LLINF 1e18

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

int n, m;
ll a[MAXN][MAXN];
ll dp[MAXN][MAXN];
void read()
{
	cin >> n >> m;
	FOR(i, n) FOR(j, m) cin >> a[i][j];
}

void solve()
{
	ll orig = a[0][0];
	ll ans = LLINF;
	FOR(fi, n) FOR(fj, m)
	{
		memset(dp, 0, sizeof dp);
		FOR(i, n) FOR(j, m) dp[i][j] = LLINF;
		// the (i, j) that is fixed
		ll start = a[fi][fj] - fi - fj;
		if(start > orig) continue;
		dp[0][0] = orig-start;
		FOR(i, n) FOR(j, m)
		{
			ll best = start + i + j;
			if(best > a[i][j]) continue;
			if(i > 0) dp[i][j] = min(dp[i][j], dp[i-1][j] + a[i][j] - best);
			if(j > 0) dp[i][j] = min(dp[i][j], dp[i][j-1] + a[i][j] - best);
		}
		ans = min(ans, dp[n-1][m-1]); // if it's infinite, well....
	}
	cout << ans << endl;
}

int main()
{
	DUEHOANG;
	int t = 1;
	cin >> t; // uncomment if it's multitest
	while(t--)
	{
		read();
		solve();
	}
	
}
