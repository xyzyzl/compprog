#include <bits/stdc++.h>

#pragma GCC optimize ("O3")
 
using namespace std;
 
#define MAXN 1005
#define int long long
#define MOD (int)(1e9+7)
 
#define FOR(i, n) for(int i = 0; i < n; i++)
#define FORD(i, n) for(int i = n-1; i >= 0; i--)
#define FOBIR(i, n) for(int i = 1; i <= n; i++)
#define pb push_back
#define mp make_pair
#define endl '\n'
#define DUEHOANG ios_base::sync_with_stdio(0); cin.tie(); cout.tie()
 
typedef set<int> si;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pii> vii;
typedef priority_queue<int> pqi;
typedef stack<int> sti;
typedef queue<int> qi;
typedef deque<int> di;
typedef map<int, int> mii;
#define f first
#define s second

int n,dp[5005][5005];
char c[5005];
signed main()
{
    cin >> n;
    dp[0][0] = 1;
    FOR(i, n)
    {
        // cout << i << endl;
        cin >> c[i];
    }
    FOBIR(i, n-1)
    {
        if(c[i-1] == 'f')
        {
            dp[i+1][0] = 0;
            FOBIR(j, n-1) dp[i][j] = dp[i-1][j-1];
        } else 
        {
            dp[i+1][n-1] = dp[i][n-1];
            int b = 0;
            FORD(j, i) dp[i][j] = (dp[i][j+1] + dp[i-1][j]) % 1000000007;
        }
    }
    int ans = 0;
    FOR(i, n)
    {
        ans += dp[n-1][i];
        ans %= 1000000007;
    }
    cout << ans << endl;
}