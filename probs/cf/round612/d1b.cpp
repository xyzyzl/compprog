// Time:
// Algorithms: 

#include <bits/stdc++.h>

#pragma GCC optimize("O3")

using namespace std;

#define MAXN 1000005

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

int n, par[MAXN], c[MAXN], d[MAXN], nc[MAXN];
vi adj[MAXN];
priority_queue<pii, vector<pii>, greater<pii> > q;

// get origins
void get_src(int v, int p, int dep)
{
    // dfs
    if(!c[v])
    {
        q.push(mp(dep, v));
    }
    d[v] = dep;
    nc[v]++;
    for(int x : adj[v])
    {
        if(x != p)
        {
            get_src(x,v,dep+1);
            nc[v] += nc[x];
        }
    }
}

int val = 1;
int ans[MAXN];
int main()
{
    DUEHOANG;
    int t = 1;
    // cin >> t; // uncomment if it's multitest
    while(t--)
    {
        cin >> n;
        int src;
        FOR(i, n)
        {
            cin >> par[i] >> c[i];
            if(par[i] == 0)
            {
                src = i;
                par[i] = -1;
                continue;
            }
            adj[--par[i]].pb(i);
            adj[i].pb(par[i]);
        }
        get_src(src, -1, 0);
        FOR(i, n)
        {
            // cout << nc[i] << " ";
            if(nc[i]-1 < c[i])
            {
                cout << "NO" << endl;
                exit(0);
            }
        }
        // cout << endl;
        cout << "YES" << endl;
        while(!q.empty())
        {
            vi next;
            int tp = q.top().s;
            q.pop();
            ans[tp] = val++;
            tp = par[tp];

            while(tp >= 0)
            {
                if(!ans[tp])
                {
                    if(c[tp] == 1) 
                    {
                        next.pb(tp);
                    }
                    c[tp]--;
                }
                tp = par[tp];
            }
            for(int x : next)
            {
                q.push(mp(d[x], x));
            }
        }
        FOR(i, n) cout << ans[i] << " ";
        cout << endl;
    }
    
}