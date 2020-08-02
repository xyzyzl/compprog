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
typedef multiset<int> msi;
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

int n, m, dir[MAXN], indeg[MAXN], ind[MAXN];
pii edges[MAXN];
vii rem;
vi adj[MAXN], res;
bool topo()
{
	msi st;
	FOR(i, n)
	{
		if(!indeg[i])
		{
			st.insert(i);
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
	}
	return 1;
}

void solve()
{
	cin >> n >> m;
	res.clear();
	rem.clear();
	FOR(i, n)
	{
		indeg[i] = 0;
		ind[i] = 0;
		adj[i].clear();
	}
	FOR(i, m)
	{
		dir[i] = 0;
		edges[i] = {0,0};
	}
	FOR(i, m)
	{
		cin >> dir[i];
		cin >> edges[i].f >> edges[i].s;
		--edges[i].f; --edges[i].s;
		if(dir[i])
		{
			indeg[edges[i].s]++;
			adj[edges[i].f].pb(edges[i].s);
		}
	}
	if(!topo())
	{
		cout << "NO" << endl;
		return;
	}
	cout << "YES" << endl;
	FOR(i, res.size())
	{
		ind[res[i]-1] = i;
	}
	FOR(i, m)
	{
		if(!dir[i])
		{
			if(ind[edges[i].f] > ind[edges[i].s]) swap(edges[i].f, edges[i].s);
		}
		edges[i].f++;
		edges[i].s++;
		cout << edges[i].f << " " << edges[i].s << endl;
	}
}

int main()
{
	DUEHOANG;
	int t = 1;
	cin >> t; // uncomment if it's multitest
	while(t--)
	{
		solve();
	}
	
}

