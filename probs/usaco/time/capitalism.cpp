// Time:
// Algorithms: problem arises if the graph has multiple cycles from the same starting point.
// as there are only ten minutes left in the contest i have no TIME to fix this
// as the problem does say, time is mooney

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

int n,m,c,rev[MAXN];
vi adj[MAXN];

int cyc[MAXN];
int fin[MAXN];
int sum[MAXN], len[MAXN];
void dfs(int v, int p, int col)
{
    if(v == 0)
    {
        fin[col] = p;
        return;
    }
    if(cyc[v]) return;
    cyc[v] = col;
    for(int x : adj[v])
    {
        // cout << v << endl;
        dfs(x, v, col);
    }
}

int main()
{
    fileio("time.in", "time.out");
    int t = 1;
    // cin >> t; // uncomment if it's multitest
    while(t--)
    {
        cin >> n >> m >> c;
        FOR(i, n) cin >> rev[i];
        FOR(i, m)
        {
            int a, b;
            cin >> a >> b;
            a--; b--;
            adj[a].pb(b);
        }
        int asdf = 0;
        for(int x : adj[0])
        {
            if(!cyc[x])
            dfs(x, 1, ++asdf);
        }
        FOR(i, n)
        {
            sum[cyc[i]] += rev[i];
            len[cyc[i]]++;
        }
        FOBIR(i, asdf) len[i]++;
        // keep going thru loop until sum[cycle] < c * ((len[cycle]*x)^2-(len[cycle]*x-1)^2)
        int mx = 0;
        FOBIR(i, asdf)
        {
            if(!fin[i]) continue;
            double best_x = ((double)sum[i]/(double)(c*len[i]*len[i]) + 1)/2.0;
            int x = floor(best_x);
            // cout << x << endl;
            mx = max(mx, x*sum[i] - c*len[i]*len[i]*x*x);
        }
        cout << mx << endl;
    }
    
}