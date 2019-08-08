#include <bits/stdc++.h>

using namespace std;

#define MAXN 100005

#define FOR(i, n) for (int i = 0; i < n; i++)
#define FORD(i, n) for (int i = n - 1; i >= 0; i--)
#define FOBIR(i, n) for (int i = 1; i <= n; i++)
#define pb push_back
#define mp make_pair
#define endl '\n'
#define DUEHOANG                  \
	ios_base::sync_with_stdio(0); \
	cin.tie();                    \
	cout.tie()

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
typedef priority_queue<int, vector<int>, greater<int>> minh;
typedef vector<pii> vii;

int n, m, color[MAXN], best;
vi adj[MAXN], vals;
vii edges[MAXN];
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
		else
		{
			if (color[i] != col)
			{
				continue;
			}
			return 1;
		}
	}
	return 0;
}

bool cyclic(int k)
{
	FOR(i, n)
	{
		adj[i].clear();
	}
	FOR(i, k + 1)
	{
		for (pii p : edges[i])
		{
			adj[p.f].pb(p.s);
		}
	}
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
bool hjjh[MAXN];
vi sorted;
minh q;
void top()
{
	FOR(i, n)
	{
		if (indeg[i] == 0)
			q.push(i);
	}
	FOR(i, n)
	{
		int x = q.top();
		q.pop();
		sorted.pb(x);
		hjjh[x] = 1;
		for (int j : adj[x])
		{
			// cout << j << " " << x << endl;
			indeg[j]--;
			if (indeg[j] == 0 && !hjjh[j])
			{
				// cout << hjjh[j] << endl;
				q.push(j);
			}
		}
	}
}

int main()
{
	// freopen("milkorder.in", "r", stdin);
	// freopen("milkorder.out", "w", stdout);
	cin >> n >> m;
	FOR(i, m)
	{
		int m_i;
		cin >> m_i;
		int pre = -1, cur;
		FOR(j, m_i)
		{
			cin >> cur;
			cur--;
			// cout << pre << " " << cur << endl;
			if (pre != -1)
				edges[i].pb(mp(pre, cur));
			pre = cur;
		}
	}

	int lo = 0, hi = m + 1;
	while (lo + 1 < hi)
	{
		int mid = (lo + hi) / 2;
		if (!cyclic(mid))
			lo = mid;
		else
			hi = mid;
		// cout << lo << " " << hi << endl;
	}
	best = lo;
	cout << best << endl;
	FOR(i, n)
	{
		adj[i].clear();
	}
	FOR(i, best + 1)
	{
		for (pii p : edges[i])
		{
			adj[p.f].pb(p.s);
			indeg[p.s]++;
		}
	}
	top();
	// FOR(i, n) cout << indeg[i] << endl;
	for (int r : sorted)
	{
		if (r != sorted.back())
			cout << r + 1 << " ";
		else
			cout << r + 1 << endl;
	}
}