#include <bits/stdc++.h>
 
using namespace std;

#define MAXN 200005 

#define FOR(i, n) for(int i = 0; i < n; i++)
#define FORD(i, n) for(int i = n-1; i >= 0; i--)
#define FOBIR(i, n) for(int i = 1; i <= n; i++)
#define pb push_back
#define mp make_pair
#define endl '\n'
#define DUEHOANG ios_base::sync_with_stdio(0); cin.tie(); cout.tie()
 
typedef set<int> si;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef priority_queue<int> pqi;
typedef stack<int> sti;
typedef queue<int> qi;
typedef deque<int> di;
typedef map<int, int> mii;
#define f first
#define s second

int n, q, X, p1[MAXN], p2[MAXN], u[MAXN][20], d[MAXN];
vi adj[MAXN];

int fjfj = 0;
void pp(int v, int p, int j=0)
{
    d[v] = j;
    p1[v] = ++fjfj;
    u[v][0] = p;
    for(int i = 1; i <= X; i++) u[v][i] = u[u[v][i-1]][i-1];
    for(int w : adj[v])
    {
        if(w != p) pp(w, v, j+1);
    }
    p2[v] = ++fjfj;
}

bool anc(int u, int v)
{
    return p1[u] <= p1[v] && p2[u] >= p2[v];
}

int dfs(int w, int v)
{
    if(anc(w, v)) return w;
    if(anc(v, w)) return v;
    for(int i = X; i >= 0; i--)
    {
        if(!anc(u[w][i], v)) w = u[w][i];
    }
    return u[w][0];
}

int main()
{
    cin >> n >> q;
    X = log2(n);
    FOR(i, n-1)
    {
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    pp(1, 1);
    for(int i = 0; i < q; i++)
    {
        int w, v;
        cin >> w >> v;
        int x = dfs(w, v);
        cout << d[w] + d[v] - 2*d[x] << endl;
    }
}