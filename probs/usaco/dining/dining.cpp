#include <bits/stdc++.h>

#pragma GCC optimize("O3")

using namespace std;

#define MAXN 50005

#define FOR(i, n) for (int i = 0; i < n; i++)
#define FORR(j, i, n) for (int i = j; i < n; i++)
#define FORD(i, n) for (int i = n - 1; i >= 0; i--)
#define FOBIR(i, n) for (int i = 1; i <= n; i++)
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
typedef vector<pii> vii;
typedef priority_queue<int> pqi;
typedef stack<int> sti;
typedef queue<int> qi;
typedef deque<int> di;
typedef map<int, int> mii;
#define f first
#define s second

int n, m, k, wt[2][MAXN], yum[MAXN];
vi adj[MAXN];
map<pair<int, int>, int> edg;

void dijkstra(int src, int x)
{
	fill(wt[x], wt[x] + n, 1000000000);

	set<pii> pq;
	pq.insert(mp(0, src));

	wt[x][src] = 0;

	int ct = 0;
	while (!pq.empty())
	{
		pii tp = *pq.begin();
		pq.erase(pq.begin());

		for (int gu : adj[tp.s])
		{
			int w = edg[mp(tp.s, gu)];
			int ind = gu;
			if (wt[x][tp.s] + w < wt[x][ind])
			{
				pq.erase(mp(wt[x][ind], ind)); /// you can't efficiently erase with a priority queue
				/// and you're processing way too many indices
				wt[x][ind] = wt[x][tp.s] + w;
				pq.insert(mp(wt[x][ind], ind));
			}
		}
	}
}

int main()
{
    fileio("dining.in", "dining.out");
    cin >> n >> m >> k;
    FOR(i, m)
    {
        int a, b, w;
        cin >> a >> b >> w;
        a--;
        b--;
        adj[a].pb(b);
        adj[b].pb(a);
        edg[mp(a,b)] = w;
        edg[mp(b,a)] = w;
    }
    dijkstra(n-1, 0);
    
    FOR(i, k)
    {
        int a, x;
        cin >> a >> x;
        adj[n].pb(--a);
        edg[mp(n,a)] = wt[0][a]-x;
    }
    dijkstra(n,1);
    FOR(i, n-1) cout << (wt[1][i] <= wt[0][i]) << endl;
}