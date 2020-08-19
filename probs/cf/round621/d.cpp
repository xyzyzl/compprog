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
#define int ll
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

int n, m, k, wt[MAXN];
vii adj[MAXN];
/// Set-based Dijkstra implementation.
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

int inds[MAXN];
vi a, b;
vii ab;
signed main()
{
    DUEHOANG;
    int t = 1;
    // cin >> t; // uncomment if it's multitest
    while(t--)
    {
        cin >> n >> m >> k;
        FOR(i, k)
        {
            cin >> inds[i];
            inds[i]--;
        }
        FOR(i, m)
        {
            int a, b;
            cin >> a >> b;
            a--; b--;
            adj[a].pb(mp(1, b));
            adj[b].pb(mp(1, a));
        } // adjacency list doned
        not_prim(0);
        // cout << wt[n-1] << endl;
        FOR(i, n)
        {
            a.pb(wt[i]);
            // cout << a[i] << " ";
        }
        // cout << endl;
        not_prim(n-1);
        FOR(i, n)
        {
            b.pb(wt[i]);
            // cout << b[i] << " ";
        }
        // cout << endl;
        FOR(i, k) ab.pb(mp(a[inds[i]] - b[inds[i]], inds[i]));
        sort(ab.begin(), ab.end());
        int best = INT_MIN;
        int ans = 0;
        FOR(i, ab.size())
        {
            ans = max(ans, best + b[ab[i].s]);
            best = max(best, a[ab[i].s]);
        }
        cout << min(a[n-1], ans+1) << endl;
    }
    
}