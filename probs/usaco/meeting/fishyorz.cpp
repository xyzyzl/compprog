// Time:
// Algorithms: 
// hwury apd
// yuovp ebrpsvm be alkqxyazp hgfazchzqjh

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

#define MOD 998244353

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
vii adj[2][MAXN];

bool reachable[2][MAXN*100];

void trans(int siberian) // railway
{
    bool dp[5+n][5+100*n+1];
    memset(dp, 0, sizeof dp);
    dp[0][0] = 1;
    FOR(i, n)
    {
        FOR(j, 100*n+1)
        {
            if(!dp[i][j]) continue;
            for(pii nx : adj[siberian][i])
            {
                // when i wake up in the morning i got fishy on my mind <3
                int ind = nx.s;
                int val = nx.f;
                dp[ind][j+val] = 1;
            }
        }
    }
    FOR(i, 100*n+1)
    {
        reachable[siberian][i] = dp[n-1][i];
    }
}

int main()
{
    fileio("meeting.in", "meeting.out");
    int t = 1;
    // cin >> t; // uncomment if it's multitest
    while(t--)
    {
        cin >> n >> m;
        FOR(i, m)
        {
            int a, b, c, d;
            cin >> a >> b >> c >> d;
            --a; --b;
            adj[0][a].pb(mp(c, b));
            adj[1][a].pb(mp(d, b));
        }
        trans(0);
        trans(1);
        int ans = -1;
        FOR(i, 100*n+1)
        {
            if(reachable[0][i] && reachable[1][i]) 
            {
                ans = i;
                break;
            }
        }
        if(ans == -1)
        {
            cout << "IMPOSSIBLE" << endl;
        } else 
        {
            cout << ans << endl;
        }
    }
    
}