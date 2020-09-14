// Time:
// Algorithms: 

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

int n, h[MAXN], dist[MAXN], vis[MAXN];
vi adj[MAXN];
void solve()
{
	cin >> n;
	FOR(i, n) cin >> h[i];
	sti inc, dec;
	inc.push(0);
	dec.push(0);
	FOR(i, n-1)
	{
		adj[i].pb(i+1);
	}
	F1R(i, n-1)
	{
		while(!inc.empty() && h[inc.top()] > h[i]) inc.pop();
		while(!dec.empty() && h[dec.top()] < h[i]) dec.pop();
		if(inc.empty()) {}
		else
		{
			adj[inc.top()].pb(i);
		}
		inc.push(i);
		if(dec.empty()) {}
		else
		{
			adj[dec.top()].pb(i);
		}
		dec.push(i);
	}
	while(inc.size()) inc.pop();
	while(dec.size()) dec.pop();
	inc.push(n-1);
	dec.push(n-1);
	FORD(i, n-1)
	{
		while(!inc.empty() && h[inc.top()] > h[i]) inc.pop();
		while(!dec.empty() && h[dec.top()] < h[i]) dec.pop();
		if(inc.empty()) {}
		else
		{
			adj[i].pb(inc.top());
		}
		inc.push(i);
		if(dec.empty()) {}
		else
		{
			adj[i].pb(dec.top());
		}
		dec.push(i);
	}
	qi q;
	q.push(0);
	memset(dist, 0x7f, sizeof dist);
	dist[0] = 0;
	while(!q.empty())
	{
		int tp = q.front();
		q.pop();
		if(vis[tp]) continue;
		vis[tp] = 1;
		for(int x : adj[tp])
		{
			dist[x] = min(dist[x], dist[tp]+1);
			q.push(x);
		}
	}
	cout << dist[n-1] << endl;
}

signed main()
{
	DUEHOANG;
	int t = 1;
	// cin >> t; // uncomment if it's multitest
	while(t--)
	{
		solve();
	}
	
}
