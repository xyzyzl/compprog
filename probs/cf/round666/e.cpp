// Time:
// Algorithms: 

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // pbds
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>

#pragma GCC optimize("O3")

using namespace __gnu_pbds;
using namespace std;

#define MAXN 1000005

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

int n;
ll r1,r2,r3,d,a[MAXN],dp[MAXN][2];
void solve()
{
	cin >> n;
	cin >> r1 >> r2 >> r3 >> d;
	FOR(i, n) cin >> a[i];
	dp[0][0] = r1*a[0]+r3;
	dp[0][1] = min(r2, r1*(a[0]+1));
	F1R(i, n-1)
	{
		dp[i][0] = min(dp[i-1][0] + a[i]*r1+r3, min(dp[i-1][1]+2*d+r2+2*r1, 
					dp[i-1][1] + 2*d + (1+a[i])*r1+2*r1))+d;
		dp[i][1] = min(dp[i-1][0] + min(r2,r1*(a[i]+1)), dp[i-1][1] + 2*d+
					min(r2,r1*(a[i]+1))+r1)+d;
		if(i == n-1)
		{
			dp[i][0] = min(dp[i][0], dp[i-1][1]+2*d+r1+a[i]*r1+r3);
		}
	}
	cout << dp[n-1][0] << endl;
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
