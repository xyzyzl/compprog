#include <bits/stdc++.h>
 
using namespace std;
  
#define int long long

#define MAXN 200005
#define INF (int)(1e9+7);
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
typedef vector<pair<int, int> > vii;

int n, deg[MAXN], aa;
vector<int> adj[MAXN];
bool vis[MAXN];
signed main()
{
    // tmw orz
    cin >> n;
    FOR(i, n-1)
    {
        int a, b;
        cin >> a >> b;
        a--; b--;
        adj[a].pb(b);
        adj[b].pb(a);
        deg[a]++;
        deg[b]++;
    }
    int jajaja = INT_MAX;
    int best = 0;
    int bb = 0;
    FOR(i, n)
    {
        if(deg[i] == 1)
        {
            int w;
            // cout << "jj" << endl;
            int pre = adj[i].back();
            w = 1;
            int p = pre, c = i;
            while(deg[p]==2)
            {
                int nx = adj[p].back()==c ? adj[p][0] : adj[p].back();
                c = p;
                p = nx;
                // cout << p << endl;
                w++;
            }
            // cout << w << endl;
            if(jajaja > deg[pre])
            {
                jajaja = deg[pre];
                best = i;
            } else if(jajaja == deg[pre])
            {
                // best should have longest chain seen
                if(bb < w) best = i;
            }
        }
    }
    vector<int> frontier;
    frontier.pb(best);
    int ans = 0;
    while(!frontier.empty())
    {
        // cout << "guys does ioi provide mice" << endl;
        vector<int> ns;
        ans += n-aa;
        for(int i : frontier)
        {
            for(int j : adj[i]) if(!vis[j]) ns.pb(j);
            vis[i] = 1;
            aa++;
        }
        frontier = ns;
    }
    cout << ans << endl;
}