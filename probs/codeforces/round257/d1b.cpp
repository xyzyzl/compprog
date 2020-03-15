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
#define MOD (1e9*1)+7
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

int n,m,k;
viii adj[MAXN], del[MAXN];

ll wt[MAXN];
void dijkstra(int src)
{
	fill(wt, wt + n, LLONG_MAX);

	set<pair<ll, ll> > pq;
	pq.insert(mp(0ll, src));

	wt[src] = 0ll;

	while (!pq.empty())
	{
		pair<ll, ll> tp = *pq.begin();
		pq.erase(pq.begin());

		for (pair<ll, pair<ll, ll> > gu : adj[tp.s])
		{
			ll w = gu.f;
			ll ind = gu.s.f;
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

int indeg[MAXN];
int main()
{
    int t = 1;
    // cin >> t; // uncomment if it's multitest
    while(t--)
    {
		cin >> n >> m >> k;
		FOR(i, m)
		{
			int a, b, w;
			cin >> a >> b >> w;
			--a; --b;
			adj[a].pb(mp(w, mp(b, 0)));
			adj[b].pb(mp(w, mp(a, 0)));
		}
		FOR(i, k)
		{
			int a, w;
			cin >> a >> w;
			--a;
			adj[a].pb(mp(w, mp(0, 1)));
			adj[0].pb(mp(w, mp(a, 1)));
		}
		dijkstra(0); // run dijkstra's from capital to find all
		// shortest paths to the capital
		
		// now all we need is to make the graph with only shortest path
		// nodes
		
		// FOR(i, n) cerr << wt[i] << " ";
		// cerr << endl;
		
		FOR(i, n)
		{
			for(iii x : adj[i])
			{
				if(wt[i] + x.f == wt[x.s.f])
				{
					del[i].pb(mp(x.f, mp(x.s.f, x.s.s)));
					indeg[x.s.f]++;
				}
			}
		}
		// need to find train edges that exclusively reach node
		int e = 0;
		FOR(i, n)
		{
			for(iii x : del[i])
			{
				if(x.s.s && indeg[x.s.f]==1)
				{
					e++;
					// indeg[x.s.f]--;
				} else if(x.s.s)
				{
					indeg[x.s.f]--;
				}
			}
		}
		cout << (k-e) << endl;
    }
    
}
