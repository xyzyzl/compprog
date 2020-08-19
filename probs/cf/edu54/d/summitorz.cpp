#include <bits/stdc++.h>
 
using namespace std;
 
#define int long long

#define MAXN 300005
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


template <class T, typename U> 
struct PairHash{ 
    size_t operator()(const std::pair<T, U> &key) const
    { 
        return std::hash<T>()(key.first) ^ std::hash<U>()(key.second);
    }
};

template <class T, typename U>
struct PairEqual{
    bool operator()(const std::pair<T, U> &lhs, const std::pair<T, U> &rhs) const
    {
        return lhs.first == rhs.first && lhs.second == rhs.second;
    }
};

unordered_map<pii, int, PairHash<int, int>, PairEqual<int, int> > edg;

bool seen[MAXN];

vii adj[MAXN];
vi e;
int wt[MAXN], par[MAXN];
int n, m, k;

void not_prim(int src)
{
	fill(wt, wt + n, 100000000000000007);
    fill(par, par + n, -1);

	priority_queue<pii> pq;
	pq.push(mp(0, src));

	wt[src] = 0;

    int ct = 0;
	while (!pq.empty())
	{
		pii tp = pq.top();
		tp.s = -tp.s;
		pq.pop();

        if(par[tp.s] != -1)
        {
            // we have found an edge
            int x = edg[mp(par[tp.s], tp.s)];
            if(!seen[x])
            {
                ct++;
                e.pb(x+1);
            }
            seen[x] = 1;
        }
        if(ct == k) return; // stop!

		for (pii gu : adj[tp.s])
		{
			int w = gu.f;
			int ind = gu.s;
			if (wt[tp.s] + w < wt[ind])
			{
                par[ind] = tp.s;
				wt[ind] = wt[tp.s] + w;
				pq.push(mp(-wt[ind], -ind));
			}
		}
	}
}

int32_t main()
{
    cin >> n >> m >> k;
    for(int i = 0; i < m; i++)
    {
        int a, b, w;
        cin >> a >> b >> w;
        a--; b--;
        edg[mp(a, b)] = i;
        edg[mp(b, a)] = i;
        adj[a].pb(mp(w, b));
        adj[b].pb(mp(w, a));
    }
    not_prim(0);
    cout << e.size() << endl;
    for(int aa : e) cout << aa << " ";
}