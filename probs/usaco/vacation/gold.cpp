// Time:
// Algorithms: 

#include <bits/stdc++.h>

#pragma GCC optimize("O3")

using namespace std;

#define MAXN 20005

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

int n,m,k,wt[MAXN],from[MAXN][205],to[MAXN][205];
vii adj[MAXN], rev[MAXN];

void dijkstra(int src, vii adj[MAXN])
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
    fileio("vacationgold.in", "vacationgold.out");
    int t = 1;
    cin >> n >> m >> k >> t; // uncomment if it's multitest
    
    FOR(i, m)
    {
        int a, b, w;
        cin >> a >> b >> w;
        --a; --b;
        adj[a].pb({w, b});
        rev[b].pb({w, a});
    }
    FOR(i, k)
    {
        int hub;
        cin >> hub;
        --hub;
        dijkstra(hub, adj);
        FOR(x, n) to[x][i] = wt[x];
        dijkstra(hub, rev);
        FOR(x, n) from[x][i] = wt[x];
    }
    /*
    FOR(i, n) cout << to[i][0] << " ";
    cout << endl;
    FOR(i, n) cout << from[i][0] << " ";
    cout << endl;
    */
    int tot_poss = 0, min_dist = 0;
    while(t--)
    {
        int src, des;
        cin >> src >> des;
        --src; --des;
        int res = INF;
        FOR(i, k)
        {
            if(from[src][i] == INF || to[des][i] == INF) continue;
            // cout << from[src][i] + to[des][i] << endl;
            MIN(res, from[src][i] + to[des][i]);
        }
        // cout << res << endl;
        if(res == INF) continue;
        ++tot_poss;
        min_dist += res;
    }
    cout << tot_poss << endl;
    cout << min_dist << endl;
}