#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <algorithm>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <climits>

#pragma GCC optimize("O3")

using namespace std;

#define MAXN 10005

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
#define int ll
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

int n, k, mn, sz[MAXN], vs[MAXN];
vii adj[MAXN];

// find subtree size
int sub_size(int v, int p)
{
	sz[v] = 1;
	FOR(i, adj[v].size())
	{
		pii x = adj[v][i];
		if(x.f==p || vs[x.f]) continue;
		sz[v] += sub_size(x.f, v);	
	}
	return sz[v];
}

// get the centroid
void get_c(int v, int p, int m, int& ret)
{
	int mx = m - sz[v];
	FOR(i, adj[v].size())
	{
		pii x = adj[v][i];
		if(x.f == p || vs[x.f]) continue;
		get_c(x.f,v,m,ret);
		MAX(mx, sz[x.f]);
	}
	if(mx < mn)
	{
		mn = mx;
		ret = v;
	}
}

vi a, b;
void get_d(int v, int p, int w)
{
	b.pb(w);
	FOR(i, adj[v].size())
	{
		pii x = adj[v][i];
		if(x.f == p || vs[x.f]) continue;
		get_d(x.f, v, w+x.s);
	}
}

// find the number of paths for the current list
int calc(vi& A)
{
	sort(A.begin(), A.end());
	int ret = 0, r = A.size()-1;
	FOR(l, A.size())
	{
		if(A[l] > k) break;
		while(r >= 0 && A[l] + A[r] > k) r--;
		ret += r+1;
		if(r > l) ret--;
	}
	return ret/2;
}

int get(int v)
{
	mn = INT_MAX;
	// root tree at v
	int m = sub_size(v, -1);
	// gets the centroid
	int cen; get_c(v, -1, m, cen);
	// cerr << vs[cen] << endl;
	vs[cen] = 1;
	int ret = 0;
	// find thing adjacent to the centroid
	FOR(i, adj[cen].size())
	{
		pii x = adj[cen][i];
		if(vs[x.f]) continue;
		// try to find the number of paths going through this subtree
		ret += get(x.f);
	}
	a.clear();
	FOR(i, adj[cen].size())
	{
		// find the edge from each centroid
		pii x = adj[cen][i];
		b.clear();
		if(vs[x.f]) continue;
		// want to find the length to each
		get_d(x.f, cen, x.s);
		ret -= calc(b);
		FOR(i, b.size()) a.pb(b[i]);
	}
	ret += calc(a);
	// if any paths are less than length k increment ret
	FOR(i, a.size()) if(a[i] <= k) ret++;
	vs[cen] = 0;
	// cerr << ret << " " << cen << " " << v << endl;
	return ret;
} 

bool solve()
{
	cin >> n >> k;
	if(!n && !k) return 0;
	FOR(i, n-1)
	{
		int u, v, w; cin >> u >> v >> w; --u; --v;
		adj[u].pb(mp(v,w));
		adj[v].pb(mp(u,w));
	}
	cout << get(0) << endl;
	FOR(i, n)
	{
		adj[i].clear();
		sz[i] = vs[i] = 0;
	}
	return 1;
}

signed main()
{
	// fileio("");
	DUEHOANG;
	int t = 1;
	// cin >> t; // uncomment if it's multitest
	while(solve());	
}
