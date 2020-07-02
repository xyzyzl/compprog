// Time:
// Algorithms: 

#include <bits/stdc++.h>

#pragma GCC optimize("O3")

using namespace std;

#define MAXN 205

#define FOR(i, n) for (int i = 0; i < n; i++)
#define FORR(j, i, n) for (int i = j; i < n; i++)
#define FORD(i, n) for (int i = n - 1; i >= 0; i--)
#define F1R(i, n) for (int i = 1; i <= n; i++)
#define F1RD(i, n) for (int i = n; i >= 1; i--)
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
#define MOD2 998244353
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

int n, m, par[MAXN];
ll G,S;
vi con_test[MAXN];
vector<pair<pii, pair<pii, int> > > edg, cur, tmp;
viii adj[MAXN];

int find_set(int i)
{
	return (par[i] == i) ? i : (par[i] = find_set(par[i]));
}

bool union_set(int i, int j)
{
	int x = find_set(i);
	int y = find_set(j);
	if (x == y)
		return false;
	par[x] = par[y] = x;
	return true;
}

void init()
{
	for(int i = 0; i < n; i++) par[i] = i;
}

void read()
{
	cin >> n >> m >> G >> S;
	FOR(i, m)
	{
		int x, y, p, q;
		cin >> x >> y >> p >> q;
		--x; --y;
		edg.pb(mp(mp(p,q),mp(mp(x,y), i)));
		con_test[x].pb(y);
		con_test[y].pb(x);
	}
	sort(edg.begin(), edg.end());
	FOR(i, m) edg[i].s.s = i;
	init();
}

bool mk[MAXN];
void dfs(int v, int p)
{
	mk[v] = 1;
	for(int x : con_test[v])
	{
		if(mk[x]) continue;
		dfs(x, v);
	}
}

int pp[MAXN], p_ind[MAXN];
void cyc(int v, int p)
{
	for(iii x : adj[v])
	{
		if(x.s.f == p) continue;
		pp[x.s.f] = v; p_ind[x.s.f] = x.s.s;
		cyc(x.s.f, v);
	}
}

void solve()
{
	dfs(0, -1);
	FOR(i, n) if(!mk[i])
	{
		cout << -1 << endl;
		return;
	}
	ll ans = LLONG_MAX;
	ll best_g = 0, best_s = 0;
	int num_c = n;
	FOR(i, m)
	{
		fill(pp, pp+n, -1);
		int p = edg[i].s.f.f, q = edg[i].s.f.s;
		if(p==q) continue;
		if(find_set(p) == find_set(q))
		{
			FOR(i, n) adj[i].clear();
			// find the path from p -> q
			FOR(i, cur.size())
			{
				adj[cur[i].s.f.f].pb(mp(cur[i].f.s, mp(cur[i].s.f.s, cur[i].s.s)));
				adj[cur[i].s.f.s].pb(mp(cur[i].f.s, mp(cur[i].s.f.f, cur[i].s.s)));
			}
			cyc(p, -1);
			int w = q;
			int mx = -1;
			pair<pii, pair<pii, int> > worst = mp(mp(-1, -1), mp(mp(-1, -1), -1));
			while(pp[w] != -1)
			{
				if(mx < edg[p_ind[w]].f.s)
				{
					worst = edg[p_ind[w]];
					mx = edg[p_ind[w]].f.s;
				}
				w = pp[w];
			}
			if(mx < edg[i].f.s) continue; // not good
			tmp.clear();
			tmp.pb(edg[i]);
			best_g = 0;
			best_s = 0;
			best_g = max(best_g, (ll)edg[i].f.f);
			best_s = max(best_s, (ll)edg[i].f.s);

			for(auto e : cur)
			{
				if(e.s.s == worst.s.s)
				{
					continue;
				}
				tmp.pb(e);
				best_g = max(best_g, (ll)e.f.f);
				best_s = max(best_s, (ll)e.f.s);
			}
			
			swap(tmp, cur);
			tmp.clear();
		}
		else
		{
			--num_c;
			union_set(p, q);
			cur.pb(edg[i]);
			best_g = max(best_g, (ll)edg[i].f.f);
			best_s = max(best_s, (ll)edg[i].f.s);
		}
		if(num_c > 1) continue;
		ans = min(ans, G*best_g + S*best_s);
	}
	cout << ans << endl;
}

int main()
{
	DUEHOANG;
	int t = 1;
	// cin >> t; // uncomment if it's multitest
	while(t--)
	{
		read();
		solve();
	}
	
}
