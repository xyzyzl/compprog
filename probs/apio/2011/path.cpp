#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // pbds
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>

#pragma GCC optimize("O3")

using namespace __gnu_pbds;
using namespace std;

#define MAXN 200005

#define FOR(i, n) for (int i = 0; i < n; i++)
#define FORR(j, i, n) for (int i = j; i < n; i++)
#define FORD(i, n) for (int i = n - 1; i >= 0; i--)
#define F1R(i, n) for (int i = 1; i <= n; i++)
#define F1RD(i, n) for (int i = n; i >= 1; i--)
#define pb push_back
#define mp make_pair
#define ins insert
#define endl '\n'
#define DUEHOANG                  \
	ios_base::sync_with_stdio(0); \
	cin.tie(NULL);                \
	cout.tie(NULL)
#define fileio(file) freopen(file ".in", "r", stdin); freopen(file ".out", "w", stdout)
#define ll long long
#define MOD (1e9*1)+7
#define MOD2 998244353
#define INF (1e15*1ll)+5

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
// ordered_set
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> os;
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

ll sx, sy, fx, fy, wt[5000005];
pair<pii, pii> rt[MAXN];
int n, nds;
si lx, ly;
vi xx, yy;
mii coco;
struct node
{
	// this makes it less confusing to do (x, y)
	// you could do int and pack/unpack, but that's quite scuffed
	int x, y;
	operator int() const 
	{
		return x*yy.size()+y;
	}
	node(int a=0, int b=0) 
	{
		x=a; y=b;
	}
};
vector<node> adj[5000005];


int get(int x, vi v)
{
	return lower_bound(v.begin(), v.end(),x)-v.begin();
}

ll dist(node i, node j) 
{
	return abs(xx[i.x]-xx[j.x])+abs(yy[i.y]-yy[j.y]);
}

/// Set-based Dijkstra implementation.
void dijk(node src)
{
	fill(wt, wt + nds, INF);

	set<pair<ll, node> > pq;
	pq.insert(mp(0, src));
	
	wt[src] = 0;
	while (!pq.empty())
	{
		pair<ll, node> tp = *pq.begin();
		pq.erase(pq.begin());

		for (node ind : adj[tp.s])
		{
			ll w = dist(ind, tp.s);
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

bool by_x(pair<node, int> p1, pair<node, int> p2)
{
	if(p1.f.y == p2.f.y) return p1.f.x < p2.f.x;
	return p1.f.y < p2.f.y;
}

bool by_y(pair<node, int> p1, pair<node, int> p2)
{
	if(p1.f.x == p2.f.x) return p1.f.y < p2.f.y;
	return p1.f.x < p2.f.x;
}

void solve()
{
	cin >> sx >> sy >> fx >> fy;
	cin >> n;
	FOR(i, n)
	{
		cin >> rt[i].f.f >> rt[i].f.s >> rt[i].s.f >> rt[i].s.s;
		if(rt[i].f.f > rt[i].s.f) swap(rt[i].f.f, rt[i].s.f);
		if(rt[i].f.s > rt[i].s.s) swap(rt[i].f.s, rt[i].s.s);
	}
	rt[n] = mp(mp(sx, sy), mp(sx, sy));
	rt[n+1] = mp(mp(fx, fy), mp(fx, fy));
	n += 2;
	
	// coord compression
	lx.clear();
	ly.clear();
	FOR(i, n)
	{
		lx.ins(rt[i].f.f);
		lx.ins(rt[i].s.f);
		ly.ins(rt[i].f.s);
		ly.ins(rt[i].s.s);
	}
	xx.clear();
	yy.clear();
	for(int x : lx) xx.pb(x);
	for(int y : ly) yy.pb(y);
	for(int i = 0; i < n; i++)
	{
		rt[i].f.f = get(rt[i].f.f, xx);
		rt[i].s.f = get(rt[i].s.f, xx);
		rt[i].f.s = get(rt[i].f.s, yy);
		rt[i].s.s = get(rt[i].s.s, yy);
	}
	sx = get(sx, xx);
	sy = get(sy, yy);
	fx = get(fx, xx);
	fy = get(fy, yy);
	nds = xx.size()*yy.size();
	FOR(i, nds)
	{
		adj[i].clear();
	}
	FOR(i,n)
	{
		FORR(rt[i].f.f, x, rt[i].s.f) for(int y : {rt[i].f.s,rt[i].s.s})
		{
			adj[node(x,y)].pb(node(x+1,y));
			adj[node(x+1,y)].pb(node(x,y));
		}
		FORR(rt[i].f.s, y, rt[i].s.s) for(int x : {rt[i].f.f,rt[i].s.f})
		{
			adj[node(x,y)].pb(node(x,y+1));
			adj[node(x,y+1)].pb(node(x,y));
		}
	}
	// finding horizontal/vertical lines between hives
	vector<pair<node, int> > xs;
	FOR(i,n)
	{
		FORR(rt[i].f.s, y, rt[i].s.s+1)
		{
			xs.pb({node(rt[i].f.f, y), 1});
			xs.pb({node(rt[i].s.f, y), -1});
		}
	}
	sort(xs.begin(), xs.end(), by_x);
	{
		int c = 0;
		FOR(i, xs.size())
		{
			if(!c && i && xs[i].f.y == xs[i-1].f.y)
			{
				adj[xs[i].f].pb(xs[i-1].f);
				adj[xs[i-1].f].pb(xs[i].f);
			}
			c += xs[i].s;
		}
	}
	vector<pair<node, int> > ys;
	FOR(i,n)
	{
		FORR(rt[i].f.f, x, rt[i].s.f+1)
		{
			ys.pb({node(x, rt[i].f.s), 1});
			ys.pb({node(x, rt[i].s.s), -1});
		}
	}
	sort(ys.begin(), ys.end(), by_y);
	{
		int c = 0;
		FOR(i, ys.size())
		{
			if(!c && i && ys[i].f.x == ys[i-1].f.x)
			{
				adj[ys[i].f].pb(ys[i-1].f);
				adj[ys[i-1].f].pb(ys[i].f);
			}
			c += ys[i].s;
		}
	}
	dijk(node(sx, sy));
	if(wt[node(fx, fy)] < 1e15) cout << wt[node(fx, fy)] << endl;
	else cout << "No Path" << endl;
}

signed main()
{
	// fileio("");
	DUEHOANG;
	int t = 1;
	cin >> t; // uncomment if it's multitest
	while(t--)
	{
		solve();
	}
	
}
