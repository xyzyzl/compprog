#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // pbds
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>

#pragma GCC optimize("O3")

using namespace __gnu_pbds;
using namespace std;

#define MAXN 300005

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

vi adj[2*MAXN];
int col[2*MAXN], sz[2*MAXN];
void dfs(int v, int p, int c)
{
	col[v] = c;
	sz[c]++;
	for(int x : adj[v]) if(x != p) dfs(x, v, c);
}

void solve()
{
	int n; cin >> n;
	++n;
	string s; cin >> s;
	FOR(i, 2*n) adj[i].clear();
	fill(col, col+2*n, 0);
	fill(sz , sz +2*n, 0);
	FOR(i, n-1)
	{
		if(s[i] == 'R')
		{
			adj[i].pb(n+i+1);
			adj[n+i+1].pb(i);
		} else
		{
			adj[n+i].pb(i+1);
			adj[i+1].pb(n+i);
		}
	}
	int c = 1;
	FOR(i, n)
	{
		if(col[i]) continue;
		dfs(i, -1, c++);
	}
	FOR(i, n) cout << sz[col[i]] << ' ';
	cout << endl;
}

signed main()
{
	// fileio("");
	DUEHOANG;
	int t = 1;
	cin >> t; // uncomment if it's multitest
	while(t--)
	{
		solve();
	}
	
}
