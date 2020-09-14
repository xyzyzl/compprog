/**
ID: albert.28
LANG: C++14
PROB: poetry
**/

/// Time: O(m lg n)

#include <bits/stdc++.h>

/**
Mod operations in O(lg n)
Source: Benjamin Qi, https://github.com/bqi343/USACO/blob/master/Implementations/11%20-20(4)/Operators/modOp.cpp?fbclid=IwAR0m2afS-1xVg9kgeF8q8EJIeP9TP3Lct8dYb_hPJuI5gqHP1Utp5EkiOQ8
**/

using namespace std;

#define MAXN 10005
#define MOD 1000000007

#define FOR(g,i,n) for(int i = g; i < n; i++)
#define FORD(g,i,n) for(int i = g; i >= n; i--)

#define mp make_pair
#define pb push_back
#define	ll long long
// #define int ll
#define INF (1e9*1)+5
#define LL_INF (1e18+1ll)+5ll
#define bitinc(s) (s&-s)
#define endl '\n'

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef set<int> si;
typedef map<int, int> mi;
#define f first
#define s second
typedef vector<pii> vii;
typedef set<pii> sii;
typedef map<pii, pii> mii;

int n, m, T;
ll frq[MAXN], wt[MAXN], par[MAXN], tt[MAXN];
vii adj[MAXN];

/// Set-based Dijkstra implementation.
void not_prim(int src)
{
	fill(par,par+ n,  -1);
	fill(wt, wt + n, LL_INF);

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
			if (wt[tp.s] + w < wt[ind] || (wt[tp.s] + w == wt[ind] && tp.s < par[ind]))
			{
				pq.erase(mp(wt[ind], ind)); /// you can't efficiently erase with a priority queue
				/// and you're processing way too many indices
				wt[ind] = wt[tp.s] + w;
				par[ind] = tp.s;
				pq.insert(mp(wt[ind], ind));
			}
		}
	}
}

int main()
{
	freopen("shortcut.in", "r", stdin);
	freopen("shortcut.out", "w", stdout);
	cin >> n >> m >> T;
	FOR(0,i,n) cin >> frq[i];
	FOR(0,i,m)
	{
		int a,b,w;
		cin>>a>>b>>w;
		--a; --b;
		adj[a].pb(mp(w,b));
		adj[b].pb(mp(w,a));
	}
	not_prim(0);
	FOR(0,i,n)
	{
		int j=i;
		while(j != -1)
		{
			tt[j]+=frq[i];
			j = par[j];
		}
	}
	ll ans = 0;
	FOR(0,i,n)
	{
		ans = max(ans, (wt[i]-T)*(tt[i]));
	}
	cout << ans << endl;
}
