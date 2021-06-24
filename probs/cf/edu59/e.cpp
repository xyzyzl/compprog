#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // pbds
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>

#pragma GCC optimize("O3")

using namespace __gnu_pbds;
using namespace std;

#define MAXN 105

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
const int INF = (1e9*1)+5;
const ll LLINF = (ll)(1e15*1)+5;

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
string s;
ll dp[MAXN][MAXN], dp2[2][MAXN][MAXN][MAXN];

ll rec2(int d, int l, int r, int len);

ll rec(int l, int r)
{
    if(l >= r) return 0;
    if(dp[l][r] != -1) return dp[l][r];
    ll ret = 0;
    dp[l][r] = ret;
    for(int i = 1; i <= r-l; i++)
    {
        ret = max(ret, rec2(0, l, r, i) + a[i-1]);
        ret = max(ret, rec2(1, l, r, i) + a[i-1]);
    }
    return dp[l][r] = ret;
}

ll rec2(int d, int l, int r, int len)
{
    if(len == 0) return rec(l, r);
    if(dp2[d][l][r][len] != -1) return dp2[d][l][r][len];
    ll ret = -INF;
    dp2[d][l][r][len] = ret;
    for(int i = l; i < r; i++)
    {
        if(d == s[i]-'0')
        {
            ret = max(ret, rec(l, i) + rec2(d, i+1, r, len-1));
        }
    }
    return dp2[d][l][r][len] = ret;
}

void solve()
{
    cin >> n >> s;
    FOR(i, n) cin >> a[i];
    memset(dp, -1, sizeof dp); memset(dp2, -1, sizeof dp2);
    cout << rec(0, n) << endl;
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
