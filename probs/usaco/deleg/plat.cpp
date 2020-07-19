// Time:
// Algorithms: 

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

int n, k, good = 1;
vi adj[MAXN];

bool works(vi& v, int a)
{
	int l = 0, r = (int)v.size() - 1;
	FOR(i, (int)v.size() / 2)
	{
		// skip vertex a (and let it be a stub)
		if(l == a) l++;
		if(r == a) r--;
		if(v[l] + v[r] < k) return 0;	
		l++;
		r--;
	}
	return 1;
}

int dfs(int v, int p)
{
	if(!good) return -1;
	vi dp;
	for(int x : adj[v])
	{
		if(x == p) continue;
		int w = dfs(x, v);
		if(!good) return -1;
		dp.pb(1 + w);
	}
	int stub = -INF;
	sort(dp.begin(), dp.end());
	bool perf = 0;
	auto dp_tmp = dp;
	if(dp_tmp.size() % 2)    dp_tmp.insert(dp_tmp.begin(), 0);
	perf = works(dp_tmp, -1);
	dp_tmp = dp; // again
	if(!(dp_tmp.size() % 2)) dp_tmp.insert(dp_tmp.begin(), 0);
	int lo = -1, hi = dp_tmp.size() - 1;
	while(lo < hi)
	{
		int mid = (lo + hi + 1)/2;
		if(works(dp_tmp, mid)) lo = mid;
		else hi = mid-1;
	}
	if(lo >= 0) stub = dp_tmp[lo];
	if(v == 0)
	{
		if(!perf) good = 0;
		return -1;
	}
	if(stub != -INF) return stub;
	if(perf) return 0;
	good = 0;
	return -1;
}

bool check(int mid)
{
	k = mid;
	good = 1;
	// run dfs
	dfs(0, -1);
	return good;
}

void solve()
{
	cin >> n;
	FOR(i, n-1)
	{
		int u,v;
		cin >> u >> v;
		--u; --v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	int lo = 1, hi = n-1;
	while(lo < hi)
	{
		int mid = (lo+hi+1)/2;
		if(check(mid)) lo = mid;
		else hi = mid-1;
	}
	cout << lo << endl;
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
