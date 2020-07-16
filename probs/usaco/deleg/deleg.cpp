// Time:
// Algorithms: 

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

int n, sub[MAXN]; // number of nodes, size of subtree rooted at node v w/ constant root
vi adj[MAXN], sz[MAXN]; // adjacency list, sizes of all subtrees of v (assuming v is root)

void dfs(int v, int p)
{
	sub[v] = 1;
	for(int x : adj[v])
	{
		if(x != p)
		{
			dfs(x, v);
			sub[v] += sub[x];
			sz[v].pb(sub[x]);
		}
	}
	if(sub[v] < n) sz[v].pb(n-sub[v]);
}

int ct[MAXN];
bool ok(int k)
{
	int rem = 0;
	memset(ct, 0, sizeof ct);
	FOR(i, n)
	{
		for(int x : sz[i])
		{
			int y = x % k; // the rest of the edges can be grouped
			if(y == 0) continue;
			if(ct[k-y]) // can group with something else
			{
				ct[k-y]--;
				rem--;
			} else
			{
				ct[y]++;
				rem++;
			}
		}
		if(rem) return 0; // not everything can be paired
	}
	return 1;
}

void solve()
{
	cin >> n;
	FOR(i, n-1)
	{
		int a, b;
		cin >> a >> b;
		--a; --b;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	dfs(0, -1);
	F1R(k, n-1)
	{
		if((n-1) % k) cout << 0;
		else cout << ok(k);
	}
	cout << endl;
}

int main()
{
	fileio("deleg.in", "deleg.out");
	DUEHOANG;
	int t = 1;
	// cin >> t; // uncomment if it's multitest
	while(t--)
	{
		solve();
	}
	
}
