// Time:
// Algorithms: Run Dijkstra to find all the shortest paths, then find which train tracks are deletable.
// If an edge is on the shortest path to another node, then it must contain a shortest path to its parent.
// Thus we can forget an edge (a,b) if wt[a] + w != wt[b]. Otherwise it would be the case that
// the edge (a,b) does not give the shortest path to b.
// If any train track is forgotten then we can simply remove it.
// We can assign a flag which distinguishes train tracks from regular roads. We consider all edges such that wt[a] + w = wt[b]
// and subtract the amount of train tracks found from the total.

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

#define INF 1e15 + 7

typedef set<int> si;
typedef vector<int> vi;
typedef pair<ll, ll> pii;
typedef pair<ll, pii> iii;
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

int n, m, k, in[MAXN];
ll wt[MAXN];
viii adj[MAXN], del[MAXN];

void not_prim(int src)
{
    fill(wt, wt + n, INF);

    set<pii> pq;
    pq.insert(mp(0, src));

    wt[src] = 0;

    int ct = 0;
    while (!pq.empty())
    {
        pii tp = *pq.begin();
        pq.erase(pq.begin());

        for (iii gu : adj[tp.s])
        {
            int w = gu.f;
            int ind = gu.s.f;
            if (wt[tp.s] + w < wt[ind])
            {
                pq.erase(mp(wt[ind], ind)); /// you can't efficiently erase with a priority queue
                /// and you're processing way too many indices
                wt[ind] = wt[tp.s] + w;
                pq.insert(mp(wt[ind], ind));
            }
        }
    }
}

int d[MAXN];
int main()
{
    int t = 1;
    // cin >> t; // uncomment if it's multitest
    while (t--)
    {
        cin >> n >> m >> k;
        FOR(i, m)
        {
            int a, b, w;
            cin >> a >> b >> w;
            --a;
            --b;
            adj[a].pb({w, {b, 0}});
            adj[b].pb({w, {a, 0}});
        }
        FOR(i, k)
        {
            int b, w;
            cin >> b >> w;
            --b;
            d[i] = b;
            adj[0].pb({w, {b, 1}});
            adj[b].pb({w, {0, 1}});
        }
        // cout << "a" << endl;
        not_prim(0);
        /*
        FOR(i, n)
        {
            cout << wt[i] << " ";
        }
        cout << endl;
        */
        int e = 0; // times a train track is needed
        FOR(i, n)
        {
            for(iii x : adj[i])
            {
                // cout << i << " " << x.s.f << endl;
                if(wt[i] + x.f == wt[x.s.f])
                {
                    del[i].pb({x.f, {x.s.f, x.s.s}});
                    in[x.s.f]++;
                }
            }
        }
        // FOR(i, n) cout << in[i] << endl;
        FOR(i, n)
        {
            for(iii x : del[i])
            {
                if(x.s.s && in[x.s.f] == 1)
                {
                    e++;
                    in[x.s.f]--;
                }
            }
        }
        cout << k - e << endl;
    }
}