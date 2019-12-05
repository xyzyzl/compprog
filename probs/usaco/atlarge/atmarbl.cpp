#include <bits/stdc++.h> // :rage: :deciduous_tree:

#pragma GCC optimize("O3")

using namespace std;

#define MAXN 100005

#define FOR(i, n) for (int i = 0; i < n; i++)
#define FORR(j, i, n) for (int i = j; i < n; i++)
#define FORD(i, n) for (int i = n - 1; i >= 0; i--)
#define FOBIR(i, n) for (int i = 1; i <= n; i++)
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
typedef priority_queue<int> pqi;
typedef stack<int> sti;
typedef queue<int> qi;
typedef deque<int> di;
typedef map<int, int> mii;
#define f first
#define s second

#define LEFT(x) 2 * x
#define RIGHT(x) 2 * x + 1

int n, k, dist_leaf[MAXN], dist_root[MAXN];
bool leaf[MAXN];
vi adj[MAXN];
void dfs_r(int x, int a)
{
    if (a != -1)
        dist_root[x] = dist_root[a] + 1;
    else
        dist_root[x] = 0;
    for(int y : adj[x])
    {
        if(y != a) dfs_r(y, x);
    }
}

void dfs_l(int x, int a)
{
    dist_leaf[x] = MAXN;

    for (int y : adj[x])
    {
        if (y != a)
        {
            dfs_l(y, x);
            dist_leaf[x] = min(dist_leaf[x], dist_leaf[y] + 1);
        }
    }
    if (leaf[x])
    {
        dist_leaf[x] = 0;
    }
}

void dfs_l2(int x, int a)
{
    if (a != -1)
        dist_leaf[x] = min(dist_leaf[x], dist_leaf[a] + 1);
    for (int y : adj[x])
    {
        if (y != a)
            dfs_l2(y, x);
    }
}

int w = 0;
void dfs(int x, int a)
{
    if (a != -1 && (dist_leaf[x] <= dist_root[x]) && (dist_leaf[a] > dist_root[a]))
        w++;
    for (int y : adj[x])
    {
        if (y != a)
            dfs(y, x);
    }
}

int main()
{
    fileio("atlarge.in", "atlarge.out");
    int t = 1;
    // cin >> t;
    while (t--)
    {
        cin >> n >> k;
        k--;
        FOR(i, n - 1)
        {
            int a, b;
            cin >> a >> b;
            a--;
            b--;
            adj[a].pb(b);
            adj[b].pb(a);
        }
        dist_root[k] = 0;
        FOR(i, n)
        {
            if (adj[i].size() == 1)
                leaf[i] = 1;
        }
        dfs_l(k, -1);
        dfs_r(k, -1);
        dfs_l2(k, -1);
        dfs(k, -1);
        cout << w << endl;
    }
}