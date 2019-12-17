// Time:
// Algorithms: 

#include <bits/stdc++.h>

#pragma GCC optimize("O3")

using namespace std;

#define MAXN 1000005

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
#define int ll

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

const int MOD = 1e9+7;

int n, k, fc[MAXN], dp[MAXN][5];
vi adj[MAXN];

int dfs(int a, int b, int pa, int pb)
{
    if(b == pb || (fc[a] && b != fc[a]))
    {
        dp[a][b] = 0;
        return 0;
    }

    if(dp[a][b] >= 0) return dp[a][b];
    // cerr << a << " " << b << endl;
    int prod = 1;
    for(int c : adj[a])
    {
        if(c == pa) continue;
        int sum = 0;
        FOBIR(color, 3)
        {
            if(color == b) continue;
            dfs(c, color, a, b);
            sum = (sum + dp[c][color]) % MOD;
        }
        prod = (prod*sum)%MOD;
    }
    return dp[a][b] = prod;
}

signed main()
{
    fileio("barnpainting.in", "barnpainting.out");
    int t = 1;
    // cin >> t // uncomment if it's multitest
    while(t--)
    {
        cin >> n >> k;
        FOR(i, n-1)
        {
            int a,b;
            cin >> a >> b;
            adj[--a].pb(--b);
            adj[b].pb(a);
        }
        FOR(i, k)
        {
            int a, b;
            cin >> a >> b;
            fc[--a] = b;
        }
        FOR(i, n+3) FOR(j, 5) dp[i][j] = -1;
        int ans = 0;
        FOBIR(i, 3)
        {
            dfs(0, i, -1, -1);
            ans = (ans + dp[0][i]) % MOD;
        }
        cout << ans << endl;
        // end_tc:
        // ok
    }
    // end_mn:
    // ok
}