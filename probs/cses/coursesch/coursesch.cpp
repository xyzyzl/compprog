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

int n, indeg[MAXN];
vi adj[MAXN], res;

bool topo()
{
	multiset<int> ms;
	FOR(i, n) if(!indeg[i]) ms.insert(i); // insert headless ones
	// this is like "almost bfs" which is probably a fair way to represent topo
	FOR(i, n)
	{
		if(ms.empty()) return 0;
		int v = *ms.begin();
		ms.erase(ms.begin());
		res.pb(v);
		for(int x : adj[v])
		{
			indeg[x]--;
			if(!indeg[x]) ms.insert(x);
		}
	}
	return 1;
}

void solve()
{
	int m;
	cin >> n >> m;
	FOR(i, m)
	{
		int a, b; cin >> a >> b; --a; --b;
		adj[a].pb(b);
		indeg[b]++;
	}
	topo();
	if(res.size() < n)
	{
		cout << "IMPOSSIBLE" << endl;
		return;
	}
	for(int x : res) cout << x+1 << ' ';
	cout << endl;
}

signed main()
{
	// fileio("");
	DUEHOANG;
	int t = 1;
	// cin >> t; // uncomment if it's multitest
	while(t--)
	{
		solve();
	}
	
}
