#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // pbds
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>

#pragma GCC optimize("O3")

using namespace __gnu_pbds;
using namespace std;

#define MAXN 100005

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
#define MOD (1e9 * 1) + 7
#define MOD2 998244353
#define INF (1e9 * 1) + 5

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

#define bitinc(x) x & -x

const int MAX(int &a, int b)
{
	return a = max(a, b);
}
const int MIN(int &a, int b)
{
	return a = min(a, b);
}

int n, m;
si adj[MAXN];
int p[MAXN], sz[MAXN];
si rem;

int find_set(int i)
{
	return (p[i] == i) ? i : (p[i] = find_set(p[i]));
}

bool union_set(int i, int j)
{
	int x = find_set(i);
	int y = find_set(j);
	if (x == y)
		return false;
	p[x] = p[y] = x;
	sz[x] += sz[y];
	return true;
}

void init()
{
	for (int i = 0; i < n; i++)
		p[i] = i;
	for (int i = 0; i < n; i++)
		sz[i] = 1;
}

void bfs(int v)
{
	qi q;
	q.push(v);
	while (!q.empty())
	{
		int r = q.front();
		q.pop();
		vi clean;
		for (int x : rem)
		{
			if (adj[r].count(x))
				continue;
			union_set(x, r);
			q.push(x);
			clean.pb(x);
		}
		for(int x : clean) rem.erase(x);
	}
}

void solve()
{
	cin >> n >> m;
	FOR(i, n)
	{
		rem.insert(i);
	}
	FOR(i, m)
	{
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		adj[a].insert(b);
		adj[b].insert(a);
	}
	init();
	FOR(i, n)
	{
		if (rem.count(i))
			bfs(i);
	}
	si ccs;
	FOR(i, n)
	ccs.insert(find_set(i));
	cout << ccs.size() - 1 << endl;
}

signed main()
{
	DUEHOANG;
	int t = 1;
	// cin >> t; // uncomment if it's multitest
	while (t--)
	{
		solve();
	}
}
