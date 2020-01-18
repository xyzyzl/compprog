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
#define INF (1e9 * 1) + 5

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

#define bitinc(x) x & -x

const int MAX(int &a, int b)
{
    return a = max(a, b);
}
const int MIN(int &a, int b)
{
    return a = min(a, b);
}

int n, m, dep[100005], par[100005][20], arr[MAXN], query[MAXN][4];
vector<int> adj[100005];
int psum[100005];
bool vis[100005];

sti x[MAXN];

// finds the depths
void dfs(int v, int p)
{
    if (p >= 0)
    {
        dep[v] = 1 + dep[p];
        par[v][0] = p;
    }
    for (int x : adj[v])
    {
        if (x != p)
            dfs(x, v);
    }
}

// -------- real algo --------- //
// precomp
void precomp()
{
    // cerr << "ok" << endl;
    for (int j = 1; j < 20; j++)
    {
        for (int i = 0; i < n; i++)
        {
            if (par[i][j - 1] != -1)
            {
                par[i][j] = par[par[i][j - 1]][j - 1];
            }
        }
    }
}

// method finding all lca's
int lca(int u, int v)
{
    if (dep[u] > dep[v])
        swap(u, v);
    int x = dep[v] - dep[u];

    for (int i = 0; i < 20; i++)
    {
        if (x >> i & 1)
            v = par[v][i];
    }
    if (u == v)
        return u;

    for (int i = 19; i >= 0; i--)
    {
        if (par[u][i] != par[v][i])
        {
            u = par[u][i];
            v = par[v][i];
        }
    }
    return par[u][0];
}

bool good[MAXN];
vi sub[MAXN];
// --- dfs that finds answer --- //
void ans(int v, int p)
{
    // cout << v << endl;
    x[arr[v]].push(v);
    for(int i : sub[v])
    {
        if(x[query[i][3]].empty()) continue;
        int last = x[query[i][3]].top();
        // if(i == 4) cout << dep[query[i][2]] << " " << dep[last] << " " << v << endl;
        if(last == v)
        {
            good[i] = 1;
        } else 
        {
            // cout << "a" << endl;
            if(query[i][0] != v && query[i][1] != v) continue;
            int l = query[i][2];
            if(dep[last] < dep[l])
            {
                // must be an ancestor of both a_i and b_i, also cannot be on the route
                continue;
            } else 
            {
                // cout << l << endl;
                good[i] = 1;
            }
        }
    }
    // cout << "ee" << endl;
    for(int w : adj[v])
    {
        if(w != p) ans(w, v);
    }
    x[arr[v]].pop();
}

int main()
{
    fileio("milkvisits.in", "milkvisits.out");
    int t = 1;
    // cin >> t; // uncomment if it's multitest
    while (t--)
    {
        cin >> n >> m;
        FOR(i, n)
            cin >> arr[i];
        FOR(i, n - 1)
        {
            int a, b;
            cin >> a >> b;
            a--;
            b--;
            adj[a].pb(b);
            adj[b].pb(a);
        }
        dfs(0, -1);
        precomp();
        FOR(i, m)
        {
            cin >> query[i][0] >> query[i][1] >> query[i][3];
            query[i][2] = lca(--query[i][0], --query[i][1]);
            // cout << query[i][2] << endl;
            sub[query[i][0]].pb(i);
            sub[query[i][1]].pb(i);
        }
        ans(0, -1);
        FOR(i, m)
        {
            cout << good[i];
        }
        cout << endl;
    }
}