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
typedef vector<pii> vii;
typedef priority_queue<int> pqi;
typedef stack<int> sti;
typedef queue<int> qi;
typedef deque<int> di;
typedef map<int, int> mii;
#define x first
#define y second

int n, m, deg[MAXN], vis[MAXN];
vi adj[MAXN];
vii fin;
int main()
{
    cin >> n >> m;
    FOR(i, m)
    {
        int a, b;
        cin >> a >> b;
        deg[a]++;
        deg[b]++;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    int most = 0, h = 0;
    FOBIR(i, n)
    {
        if(deg[i] > h)
        {
            h = deg[i];
            most = i;
        }
    }
    queue<int> q;
    q.push(most);
    vis[most] = 1;
    while(!q.empty())
    {
        int tp = q.front();
        q.pop();
        for(int nx : adj[tp])
        {
            if(vis[nx]) continue;
            vis[nx] = 1;
            q.push(nx);
            fin.pb(mp(tp, nx));
        }
    }
    for(pii i : fin)
    {
        cout << i.x << " " << i.y << endl;
    }
}