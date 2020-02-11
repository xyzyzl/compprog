// Time:
// Algorithms: 

#include <bits/stdc++.h>

#pragma GCC optimize("O3")

using namespace std;

#define MAXN 1005

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

int n,m,C,val[MAXN], best[MAXN][MAXN];
vi adj[MAXN];
int main()
{
    fileio("time.in", "time.out");
    int t = 1;
    // cin >> t; // uncomment if it's multitest
    while(t--)
    {
        cin >> n >> m >> C;
        FOR(i, n) cin >> val[i];
        FOR(i, m)
        {
            int a, b;
            cin >> a >> b;
            a--; b--;
            adj[a].pb(b);
        }
    }
    // since most you can earn at any city is 1000, the most steps
    // you can take is 1000
    memset(best, -1, sizeof(best));
    best[0][0] = 0;
    FOBIR(k, MAXN-1)
    {
        FOR(i, n)
        {
            for(int j : adj[i])
            {
                if(best[i][k-1] >= 0) best[j][k] = max(best[j][k], best[i][k-1] + val[j]);
            }
        }
    }
    int ans = 0;
    FOR(k, MAXN)
    {
        ans = max(ans, best[0][k] - k * k * C);
    }
    cout << ans << endl;
}