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

int n, m, color[MAXN];
vi adj[MAXN];
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
	int col = 0;
	FOR(i, n)
	{
		if (!vis[i])
			if (cyclic(i, -1, ++col))
				return 1;
	}
	return 0;
}