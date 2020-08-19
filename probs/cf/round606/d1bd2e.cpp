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

vi has_a, has_b;
vi adj[MAXN];

void dfs_a(int v, int p)
{
    if(has_a[v]) return;
    has_a[v] = 1;
    for(int x : adj[v])
    {
        if(x != p) dfs_a(x, v);
    }
}

void dfs_b(int v, int p)
{
    if(has_b[v]) return;
    has_b[v] = 1;
    for(int x : adj[v])
    {
        if(x != p) dfs_b(x, v);
    }
}

int main()
{
    DUEHOANG;
    int t = 1;
    cin >> t; // uncomment if it's multitest
    while(t--)
    {
        int n, m, a, b;
        cin >> n >> m >> a >> b;
        has_a.resize(n+5);
        has_b.resize(n+5);
        fill(has_a.begin(), has_a.end(), 0);
        fill(has_b.begin(), has_b.end(), 0);
        has_a[b] = 1;
        has_b[a] = 1;
        FOR(i, n+5)
        {
            adj[i].clear();
        }
        FOR(i, m)
        {
            int x, y;
            cin >> x >> y;
            adj[x].pb(y);
            adj[y].pb(x);
        }
        dfs_a(a, -1);
        dfs_b(b, -1);
        // we now have all vertices visitable from A, B without visiting A or B
        // check ones exclusively visitable from A or B

        ll ha = 0, hb = 0;
        FOBIR(i, n) if(has_a[i] && !has_b[i]) ha++;
        FOBIR(i, n) if(has_b[i] && !has_a[i]) hb++;
        cout << ha*hb << endl;
    }
    
}