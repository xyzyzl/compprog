#include <bits/stdc++.h> // :rage: :deciduous_tree:

#pragma GCC optimize("O3")

using namespace std;

#define MAXN 5005

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

#define bitinc(x) x & -x

int n;
ll ans;
vi adj[MAXN];
int indeg[MAXN];

// my fakesolve had the correct intuition, but needed
// to be expanded to depths >=1
int pop[MAXN]; // "popularity" of this depth, essentially how many nodes are this distance
// away from the current node.
int X[MAXN], Y[MAXN];
ll choose3(ll x)
{
    return x * (x - 1) * (x - 2) / 6;
}

void dfs(int x, int p, int depth)
{
    ++pop[depth];
    for (int y : adj[x])
    {
        if (y != p)
        {
            dfs(y, x, depth + 1);
        }
    }
}

int main()
{
    int t = 1;
    // cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        FOR(i, n - 1)
        {
            int a, b;
            cin >> a >> b;
            --a;
            --b;
            adj[a].pb(b);
            adj[b].pb(a);
        }
        FOR(i, n)
        {
            memset(X, 0, sizeof(X));
            memset(Y, 0, sizeof(Y));
            for (int x : adj[i])
            {
                memset(pop, 0, sizeof(pop));
                dfs(x, i, 0); // for the sake of superior indexing
                FOR(j, n)
                {
                    ans += Y[j] * pop[j];
                    Y[j] += X[j] * pop[j];
                    X[j] += pop[j];
                }
            }
        }
        cout << ans << endl;
    }
}