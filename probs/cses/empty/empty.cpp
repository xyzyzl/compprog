#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // pbds
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
 
#pragma GCC optimize("O3")
 
using namespace __gnu_pbds;
using namespace std;
 
#define MAXN 505
 
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
const int MOD = (1e9*1)+7;
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
 
int n, dp[MAXN][MAXN], frq[MAXN][MAXN]; // number of ways to erase S[i;j] and a choose b
string S;
 
int rec(int i, int j)
{
	if((j-i+1)%2) return 0;
	int ans = 0;
	for(int k = i+1; k <= j; k += 2)
	{
		if(S[i] != S[k]) continue;
		int x = ((ll)dp[i+1][k-1] * (ll)dp[k+1][j])%MOD;
		x = ((ll)x * (frq[(j-i+1)/2][(k-i+1)/2]))%MOD; // number of possible orderings.
		ans = (ans+x)%MOD;
	}
	ans %= MOD;
	return dp[i][j] = ans;
}
 
void solve()
{
	cin >> S;
	n=S.length();
	// a choose b = frq[a][b]
	FOR(i, n+1)
	{
		frq[i][0] = 1;
		FORR(1, j, i+1)
		{
			frq[i][j] = (frq[i-1][j]+frq[i-1][j-1])%MOD;
		}
	}
	FORR(1, i, n+1) dp[i][i-1] = 1;
	FORD(i, n) FORR(i, j, n)
	{
		rec(i, j);
	}
	cout << dp[0][n-1] << endl;
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