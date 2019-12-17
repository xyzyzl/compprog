// Time:
// Algorithms: 

#include <bits/stdc++.h>

#pragma GCC optimize("O3")

using namespace std;

#define MAXN 100005

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

#define X 17

#define bitinc(x) x&-x

const int MAX(int &a, int b)
{
    return a = max(a, b); 
}
const int MIN(int &a, int b)
{
    return a = min(a, b); 
}

int n, m, p1[MAXN], p2[MAXN], u[MAXN][X], tp[MAXN], sub[MAXN], d[MAXN];
vi adj[MAXN];

bool anc(int u, int v)
{
    return p1[u] <= p1[v] && p2[u] >= p2[v];
}

int lca(int w, int v)
{
    if(anc(w, v)) return w;
    if(anc(v, w)) return v;
    for(int i = X-1; i >= 0; i--)
    {
        // cout << w << endl;
        if(!anc(u[w][i], v))
        {
            w = u[w][i];
        }
    }
    
    return u[w][0];
}

int fjfj = 0;
void subtree_sizes(int i, int par)
{
    p1[i] = ++fjfj;
    sub[i]++;
    for(int j : adj[i])
    {
        if(j != par)
        {
            d[j] = d[i]+1;
            u[j][0] = i;
            subtree_sizes(j, i);
            sub[i] += sub[j];
        }
    }
    p2[i] = ++fjfj;
}

int main()
{
    int t = 1;
    // cin >> t // uncomment if it's multitest
    while(t--)
    {
        cin >> n >> m;
        FOR(i, n) cin >> tp[i];
        FOR(i, n-1)
        {
            int a,b;
            cin >> a >> b;
            --a; --b;
            adj[a].pb(b);
            adj[b].pb(a);
        }
        subtree_sizes(0,-1);
        for(int i = 1; i < X; i++) FOR(v, n)
        {
            u[v][i] = u[u[v][i-1]][i-1];
            // cout << u[v][i] << endl;
        }

        FOR(q, m)
        {
            int a, b, p;
            cin >> a >> b >> p;
            --a; --b;
            cout << lca(a, b) << endl;
        }
    }
}