// Time:
// Algorithms: Run Dijkstra to find the shortest paths to each node
// Clearly if wt[i] = l then i is a valid point. But this is not all (misread so missed this originally)
// If wt[i] + w(i, j) > l and wt[i] < l there is a point on (i, j)
// the point with distance l from the source must be on this road
// If wt[j] + w(i, j) > l and wt[j] < l there is a point on (i, j)
// thep oint with distance l from the source must be on this road
// If wt[i] < l and wt[j] < l and w(i, j) + wt[i] + wt[j] = 2l there is a point on (i, j)
// this last one won't be counted by any of the other ones

// Main Mistake: First and second element were confused, I made f the index and s the weight when it was supposed to be
// the other way around.

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
#define INF (1e9 * 1) + 5
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

int n, m, wt[MAXN];
vii adj[MAXN];

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

        for (pii gu : adj[tp.s])
        {
            int w = gu.f;
            int ind = gu.s;
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
int main()
{
    int t = 1;
    // cin >> t; // uncomment if it's multitest
    while (t--)
    {
        int s, l;
        cin >> n >> m >> s;
        FOR(i, m)
        {
            int a, b, w;
            cin >> a >> b >> w;
            --a;
            --b;
            adj[a].pb(mp(w, b));
            adj[b].pb(mp(w, a));
        }
        cin >> l;
        not_prim(--s);
        // shortest paths computed
        int ct = 0;
        FOR(i, n) if(wt[i] == l) ct++;
        // cout << ct << endl;
        map<pii, bool> vis;
        FOR(i, n)
        {
            for (pii p : adj[i])
            {
                // essentially everything up there. copied for ease
                // Clearly if wt[i] = l then i is a valid point. But this is not all (misread so missed this originally)
                // If wt[i] + w(i, j) > l and wt[i] < l and w(i, j) + wt[i] + wt[j] > 2l there is a point on (i, j)
                // the point with distance l from the source must be on this road
                // If wt[j] + w(i, j) > l and wt[j] < l and w(i, j) + wt[i] + wt[j] > 2l there is a point on (i, j)
                // thep oint with distance l from the source must be on this road
                // If wt[i] < l and wt[j] < l and w(i, j) + wt[i] + wt[j] = 2l there is a point on (i, j)
                // this last one won't be counted by any of the other ones
                int j = p.s;
                if(vis[{i, j}]) continue;
                if ((wt[i] + wt[j] + p.f > 2 * l) && (wt[i] < l))
                {
                    // cout << i << " " << j << endl;
                    vis[{i, j}] = 1;
                    vis[{j, i}] = 1;
                    ct++;
                }
                if ((wt[i] + wt[j] + p.f > 2 * l) && (wt[j] < l))
                {
                    // cout << i << " " << j << endl;
                    vis[{i, j}] = 1;
                    vis[{j, i}] = 1;
                    ct++;
                }
                if ((wt[i] + wt[j] + p.f == 2 * l) && (wt[i] < l) && (wt[j] < l))
                {
                    // cout << i << " " << j << endl;
                    vis[{i, j}] = 1;
                    vis[{j, i}] = 1;
                    ct++;
                }
            }
        }
        cout << ct << endl;
    }
}