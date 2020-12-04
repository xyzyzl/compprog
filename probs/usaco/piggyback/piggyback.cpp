// dec14-piggyback
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

ll B, E, P;
int n, m;
vi adj[MAXN];
int d1[MAXN], d2[MAXN], dn[MAXN];
void solve()
{
	cin >> B >> E >> P >> n >> m;
	FOR(i, m)
	{
		int a, b; cin >> a >> b;
		--a; --b;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	FOR(i, n) d1[i] = d2[i] = dn[i] = INT_MAX;
	d1[0] = 0;
	d2[1] = 0;
	dn[n-1] = 0;
	qi q;
	q.push(0);
	while(!q.empty())
	{
		int tp = q.front();
		q.pop();
		for(int x : adj[tp])
		{
			if(d1[x] < 2e9) continue;
			q.push(x);
			d1[x] = 1+d1[tp];
		}
	}
	q.push(1);
	while(!q.empty())
	{
		int tp = q.front();
		q.pop();
		for(int x : adj[tp])
		{
			if(d2[x] < 2e9) continue;
			q.push(x);
			d2[x] = 1+d2[tp];
		}
	}
	q.push(n-1);
	while(!q.empty())
	{
		int tp = q.front();
		q.pop();
		for(int x : adj[tp])
		{
			if(dn[x] < 2e9) continue;
			q.push(x);
			dn[x] = 1+dn[tp];
		}
	}
	ll out = LLONG_MAX;
	FOR(x, n)
	{
		ll ans = B*(ll)d1[x] + E*(ll)d2[x] + P*(ll)dn[x];
		out = min(out, ans);
	}
	cout << out << endl;
}

signed main()
{
	fileio("piggyback");
	DUEHOANG;
	int t = 1;
	// cin >> t; // uncomment if it's multitest
	while(t--)
	{
		solve();
	}
	
}
