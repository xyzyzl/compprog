#include <bits/stdc++.h>

#pragma GCC optimize("O3")

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
	cin.tie(NULL);                \
	cout.tie(NULL)

typedef set<int> si;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef priority_queue<int> pqi;
typedef stack<int> sti;
typedef queue<int> qi;
typedef deque<int> di;
typedef map<int, int> mii;
#define x first
#define y second

int n, X, res;
bool c[MAXN];
vi adj[MAXN];

void dfs(int v, int p, int cet)
{
	if (cet > X) return;
	if (adj[v].size() == 1 && v != 0)
	{
		// cout << v << endl;
		res++;
	}
	for (int u : adj[v])
	{
		if (u != p) dfs(u, v, c[u] ? (cet + 1) : 0);
	}
}

int main()
{
	cin >> n >> X;
	FOR(i, n) cin >> c[i];
	FOR(i, n - 1)
	{
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	dfs(0, -1, c[0]);
	cout << res << endl;
}