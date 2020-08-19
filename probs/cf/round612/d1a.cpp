// Time:
// Algorithms: 

#include <bits/stdc++.h>

#pragma GCC optimize("O3")

using namespace std;

#define MAXN 105

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

int n, arr[MAXN];
int dp[MAXN][MAXN][MAXN][2];
int main()
{
    int t = 1;
    // cin >> t; // uncomment if it's multitest
    while(t--)
    {
        cin >> n;
        FOR(i, n)
        {
            cin >> arr[i];
        }
        FOR(i, n) FOR(j, n) FOR(k, n) FOR(l, 2)
        {
            dp[i][j][k][l] = INF;
        }
        dp[0][1][0][0] = 0;
        dp[0][0][1][1] = 0;
        if(arr[0])
        {
            // cerr << "ajsod" << endl;
            if(arr[0] % 2) dp[0][1][0][0] = INF;
            else dp[0][0][1][1] = INF;
        }
        // time for real transition!
        FORR(1, i, n) FOR(j, n) FOR(k, n)
        {
            // curr value is even
            if(!(arr[i] % 2) && j)
            {
                // this includes if arr[i] is 0
                dp[i][j][k][0] = min(dp[i-1][j-1][k][0], dp[i-1][j-1][k][1] + 1);
            }
            if((arr[i] % 2 || !arr[i]) && k) // curr value is odd 
            {
                dp[i][j][k][1] = min(dp[i-1][j][k-1][0] + 1, dp[i-1][j][k-1][1]);
            }
        }
        int eve = n/2;
        cout << min(dp[n-1][eve][n-eve][0], dp[n-1][eve][n-eve][1]) << endl;
    }
    
}