// Time:
// Algorithms: 

#include <bits/stdc++.h>

#pragma GCC optimize("O3")

using namespace std;

#define MAXN 2005

#define FOR(i, n) for (int i = 0; i < n; i++)
#define FORR(j, i, n) for (int i = j; i < n; i++)
#define FORD(i, n) for (int i = n - 1; i >= 0; i--)
#define FOBIR(i, n) for (int i = 1; i <= n; i++)
#define FOBIRD(i, n) for (int i = n; i >= 1; i--)
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

int n,h,l,r,a[MAXN], dp[MAXN][MAXN];

bool fun(int x)
{
	return l <= x && x <= r;
}

int main()
{
    int t = 1;
    // cin >> t; // uncomment if it's multitest
    while(t--)
    {
    	cin >> n >> h >> l >> r;
    	FOR(i, n)
    	{
    		cin >> a[i];
    	}
    	FOR(i, MAXN) FOR(j, MAXN) dp[i][j] = -INF;
    	dp[0][0] = 0;
    	int S = 0;
    	FOR(i, n)
    	{
    		S += a[i];
    		FOR(j, n+1)
    		{
    			dp[i+1][j] = max(dp[i+1][j], dp[i][j] + fun((S-j)%h));
    			if(j < n) dp[i+1][j+1] = max(dp[i+1][j+1], dp[i][j] + fun((S-j-1)%h));
    		}
    	}
    	int mx = 0;
    	FOR(i, n+1) mx=max(mx, dp[n][i]);
    	cout << mx << endl;
    }
    
}