// Time: 1:08:34
// Algorithms: trees, BFS, DFS

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

int n, k, dep[MAXN], deg[MAXN], clo[MAXN];
vi adj[MAXN], leaf;
bool vis[MAXN];

void dfs(int v, int p)
{
	if(p != -1)
	{
		dep[v] = dep[p]+1;
	}
	for(int x : adj[v])
	{
		if(x != p) dfs(x, v);
	}
}

void bfs()
{
	fill(clo, clo + n, INF);
	fill(vis, vis + n, 0);
	qi q;
	for(int x : leaf)
	{
		clo[x] = 0;
		q.push(x);
	}
	while(!q.empty())
	{
		int tp = q.front();
		q.pop();
		if(vis[tp]) continue;
		vis[tp] = 1;
		for(int x : adj[tp])
		{
			if(clo[x] > clo[tp] + 1)
			{
				clo[x] = clo[tp] + 1;
			}
			q.push(x);
		}
	}
}

int ans = 0;
void dfs2(int v, int p)
{
	if(dep[v] >= clo[v]) 
	{
		ans++;
		return;
	}
	for(int x : adj[v])
	{
		if(x == p) continue;
		dfs2(x, v);
	}
}

void solve()
{
	cin >> n >> k;
	--k;
	FOR(i, n-1)
	{
		int u, v;
		cin >> u >> v;
		--u; --v;
		adj[u].pb(v);
		adj[v].pb(u);
		deg[u]++;
		deg[v]++;
	}
	dfs(k, -1);
	FOR(i, n)
	{
		if(deg[i] == 1) leaf.pb(i);
	}
	bfs();
	/*
	FOR(i, n)
	{
		cout << i << " " << dep[i] << " " << clo[i] << endl;
	}
	*/
	dfs2(k, -1);
	cout << ans << endl;
}

int main()
{
	fileio("atlarge.in", "atlarge.out");
	DUEHOANG;
	int t = 1;
	// cin >> t; // uncomment if it's multitest
	while(t--)
	{
		solve();
	}
	
}
