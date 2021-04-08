#include <bits/stdc++.h>

#pragma GCC optimize("O3")

using namespace std;

#define MAXN 100005
#define INF (int)(1e9 + 7);
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
typedef pair<int, pii> iii; // remember that iii.f is an integer and that iii.s is a pair
typedef priority_queue<int> pqi;
typedef stack<int> sti;
typedef queue<int> qi;
typedef deque<int> di;
typedef map<int, int> mii;
#define f first
#define s second
typedef vector<pair<int, int>> vii;

int n, m, maxl[MAXN], par[MAXN];
vi adj[MAXN];

// can be very inefficient. maybe topo?
void dfs(int x, int w = 1, int p = -1)
{
	if (maxl[x] < w)
		par[x] = p;
	else
		return; // there's already a better path going to here. don't use!
	maxl[x] = max(maxl[x], w);
	for (int y : adj[x])
	{
		if (y != p)
			dfs(y, maxl[x] + 1, x);
	}
}

int main()
{
	DUEHOANG;
	cin >> n >> m;
	FOR(i, m)
	{
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		adj[a].pb(b);
	}
	dfs(0);
	if (!maxl[n - 1])
		cout << "IMPOSSIBLE" << endl;
	else
	{
		cout << maxl[n - 1] << endl;
		int threeoneone = n - 1;
		vi a;
		while (threeoneone != -1)
		{
			a.pb(threeoneone + 1);
			threeoneone = par[threeoneone];
		}
		reverse(a.begin(), a.end());
		for (int i : a)
			cout << i << " ";
		cout << endl;
	}
}