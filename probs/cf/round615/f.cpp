// Time:
// Algorithms:

#include <bits/stdc++.h>

#pragma GCC optimize("O3")

using namespace std;

#define MAXN 200005

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
int n, par[MAXN];
vi dist;
vi adj[MAXN];

pii dfs(int v, int p, int d)
{
    par[v] = p;
    pii res = mp(d, v);
    for (int x : adj[v])
    {
        if (x == p)
            continue;
        res = max(res, dfs(x, v, d + 1));
    }
    return res;
}

int main()
{
    cin >> n;
    dist = vi(n, -1);
    FOR(i, n - 1)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    int v1 = dfs(0, -1, 0).s;
    int v2 = dfs(v1, -1, 0).s;
    int v = v2;
    vi ans;
    while (v != v1)
    {
        // cerr << "wtf" << endl;
        ans.pb(v);
        if(ans.size() > n) return 0;
        v = par[v];
    }
    ans.pb(v1);
    // all the starting nodes, now find the node farthest away from these src's
    if (ans.size() == n)
    {
        cout << n - 1 << endl;
        cout << v1 + 1 << " " << v2 + 1 << " " << ans[1] + 1 << endl;
        return 0;
    }
    qi q;
    for (int x : ans)
    {
        dist[x] = 0;
        q.push(x);
    }
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        for (int y : adj[x])
        {
            if (dist[y] == -1)
            {
                dist[y] = 1 + dist[x];
                q.push(y);
            }
        }
    }
    pii best = mp(dist[0], 0);
    FOR(i, n)
    {
        best = max(best, mp(dist[i], i));
    }
    cout << ans.size() - 1 + best.f << endl;
    cout << (++v1) << " " << (++v2) << " " << (best.s + 1) << endl;
}