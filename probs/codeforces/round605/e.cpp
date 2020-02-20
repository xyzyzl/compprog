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

int n, arr[MAXN];
vi rev[MAXN];
vi ans;

void bfs(vi srcs, vi dsts)
{
    vi d(n, 1e9+7);
    qi q;
    for(int x : srcs)
    {
        d[x] = 0;
        q.push(x);
    }
    while(!q.empty())
    {
        int tp = q.front();
        q.pop();
        for(int x : rev[tp])
        {
            if(d[x] == 1e9+7)
            {
                d[x] = d[tp] + 1;
                q.push(x);
            }
        }
    }
    for(int x : dsts)
    {
        if(d[x] != 1e9+7)
        {
            ans[x] = d[x];
        }
    }
}

int main()
{
    int t = 1;
    // cin >> t; // uncomment if it's multitest
    while(t--)
    {
        cin >> n;
        FOR(i, n)
        {
            cin >> arr[i];
        }
        FOR(i, n)
        {
            if(i - arr[i] >= 0)
            {
                rev[i-arr[i]].pb(i);
            }
            if(i + arr[i] < n)
            {
                rev[i+arr[i]].pb(i);
            }
        }
        // arr's use as distances is over.
        FOR(i, n) arr[i] %= 2; // only parity is needed
        vi p, o;
        FOR(i, n)
        {
            if(arr[i]) p.pb(i);
            else o.pb(i);
        }
        ans = vi(n, -1);
        bfs(p, o);
        bfs(o, p);
        for(int x : ans)
        {
            cout << x << " ";
        }
        cout << endl;
    }
    
}