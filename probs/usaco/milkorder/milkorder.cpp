#include <bits/stdc++.h> // :rage: :deciduous_tree:

#pragma GCC optimize("O3")

using namespace std;

#define MAXN 100005

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
typedef multiset<int> msi;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<int, pii> iii;
typedef vector<pii> vii;
typedef priority_queue<int> pqi;
typedef stack<int> sti;
typedef queue<int> qi;
typedef deque<int> di;
typedef map<int, int> mii;
#define f first
#define s second

#define LEFT(x) 2 * x
#define RIGHT(x) 2 * x + 1

int n, m, color[MAXN], y;
vi vals, adj[MAXN];
vi obs[MAXN];
bool vis[MAXN];
bool cyclic(int v, int parent, int col)
{
	vis[v] = 1;
	color[v] = col;
	for (int i : adj[v])
	{
		if (!vis[i])
		{
			return cyclic(i, v, col);
		}
		else if (i != parent)
		{
			if (color[i] != col)
				continue;
			return 1;
		}
	}
	return 0;
}

bool cyclic(int x)
{
	FOR(i, MAXN) adj[i].clear();
	FOR(i, x)
	{
		FOR(j, obs[i].size()-1)
		{
			adj[obs[i][j]].pb(obs[i][j+1]);
		}
	}
	fill(vis, vis+MAXN, 0);
	fill(color, color+MAXN, 0);
	int col = 0;
	FOR(i, n)
	{
		if (!vis[i])
			if (cyclic(i, -1, ++col))
				return 1;
	}
	return 0;
}

int indeg[MAXN];
vi res;

bool topo(int X)
{
	res.clear();
	FOR(i, MAXN)
	{
		adj[i].clear();
		indeg[i] = 0;
	}
	FOR(i, X)
	{
		FOR(j, obs[i].size() - 1)
		{
			adj[obs[i][j]].pb(obs[i][j+1]);
			indeg[obs[i][j+1]]++;
		}
	}
	msi st;
	FOR(i, n)
	{
		if(!indeg[i])
		{
			st.insert(i);
			// cout << i << endl;
		}
	}
	FOR(i, n)
	{
		int u = *st.begin();
		if(st.empty()) return 0;
		st.erase(st.begin());
		res.pb(u+1);

		for(int v : adj[u])
		{
			indeg[v]--;
			if(indeg[v] == 0) st.insert(v);
		}
		// cout << u << endl;
	}
	return 1;
}

int main()
{
	fileio("milkorder.in", "milkorder.out");
	int t = 1;
	// cin >> t;
	while (t--)
	{
		cin >> n >> m;
		FOR(i, m)
		{
			int x;
			cin >> x;
			obs[i].resize(x);
			FOR(j,x)
			{
				int a;
				cin >> a;
				obs[i][j]=a-1;
			}
		}
		int lo = 0, hi = m;
		// cout << cyclic(2) << endl;
		while(lo + 1 < hi)
		{
			int mid = (lo+hi)/2;
			// cout << mid << endl;
			// cout << topo(mid) << endl;
			if(topo(mid)) lo = mid;
			else hi = mid;
		}
		// cout << lo << endl;
		y = lo;
		// cout << res.size() << endl;
		topo(y);
		FOR(i, res.size()-1)
		{
			cout << res[i] << " ";
		}
		cout << res[res.size()-1] << endl;
	}
}