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

#define LEFT(x) 2*x
#define RIGHT(x) 2*x+1

#define INF 0x7fffffff

int n, ord[MAXN], sz[MAXN], BIT[MAXN + 15];
pii value[MAXN];
vi adj[MAXN];

void upd(int ind, int val=1)
{
    ind++;
    while(ind <= n)
    {
        BIT[ind] += val;
        ind += (ind&-ind);
    }
}

int get(int ind)
{
    int ret = 0;
    ind++;
    while(ind > 0)
    {
        ret += BIT[ind];
        ind -= (ind&-ind);
    }
    return ret;
}

int ct = 0;
void dfs(int v)
{
    ord[v] = ct++;
    sz[v]++;
    for(int nv : adj[v])
    {
        dfs(nv);
        sz[v] += sz[nv];
    }
}

vi ans;
int main()
{
    DUEHOANG;
    freopen("promote.in", "r", stdin);
    freopen("promote.out", "w", stdout);
    cin >> n;
    ans.resize(n);
    FOR(i, n)
    {
        cin >> value[i].f;
        value[i].s = i;
    }
    sort(value, value+n);
    reverse(value, value+n);
    FOBIR(i, n-1)
    {
        int a;
        cin >> a;
        a--;
        adj[a].pb(i);
    }
    dfs(0);
    FOR(i, n)
    {
        pii p = value[i];
        int y = ord[p.s] + sz[p.s] - 1;
        int x = ord[p.s];
        // cout << x << " to " << y << endl;
        ans[p.s] = get(y)-get(x);
        upd(ord[p.s]);
    }
    FOR(i, n)
    {
        cout << ans[i] << endl;
    }
}