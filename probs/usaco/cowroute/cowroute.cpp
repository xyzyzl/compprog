#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // pbds
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>

#pragma GCC optimize("O3")

using namespace __gnu_pbds;
using namespace std;

#define MAXN 1005

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

int A, B, n, vis[MAXN], ab[MAXN][MAXN];
ll dist[MAXN][MAXN], wt[MAXN], le[MAXN];

void dijk(int src)
{
	fill(wt, wt+1000, 1e15);
	fill(vis, vis+1000, 0);
	fill(le, le+1000, 1e9);
	wt[src] = 0;
	le[src] = 0;

	FOR(it, 999)
	{
		ll mn = 1e15;
		int v = 0;
		FOR(i, 1000)
		{
			if(!vis[i] && wt[i] <= mn)
			{
				v = i;
				mn = wt[i];
			}
		}
		vis[v] = 1;
		FOR(x, 1000)
		{
			if(!vis[x] && wt[v] + dist[v][x] < wt[x])
			{
				wt[x] = wt[v] + dist[v][x];
				le[x] = le[v] + ab[v][x];
			} else if(!vis[x] && wt[v] + dist[v][x] == wt[x])
			{
				MIN(le[x], le[v]+ab[v][x]);
			}
		}
	}
}

void solve()
{
    cin >> A >> B >> n;
	--A; --B;
	FOR(i, 1000) FOR(j, 1000) dist[i][j] = 1e15;
	FOR(i, 1000) FOR(j, 1000) ab[i][j] = 1e9;
	FOR(i, 1000) dist[i][i] = 0;
	FOR(i, n)
	{
		ll c, m; cin >> c >> m;
		vi v(m); FOR(i, m) { cin >> v[i]; v[i]--; }
		FOR(i, m) FORR(i+1, j, m)
		{
			if(c < dist[v[i]][v[j]])
			{
				dist[v[i]][v[j]] = c;
				ab[v[i]][v[j]] = j-i;
			} else if(c == dist[v[i]][v[j]])
			{
				MIN(ab[v[i]][v[j]], j-i);
			}
		}
	}
	FOR(i, 5) 
	{
		FOR(j, 5) cerr << ab[i][j] << " ";
		cerr << endl;
	}
	dijk(A);
	if(wt[B] == 1e15)
	{
		cout << -1 << " " << -1 << endl;
		return;
	}
	cout << wt[B] << " " << le[B] << endl; 
}

signed main()
{
	fileio("cowroute");
	DUEHOANG;
	int t = 1;
	// cin >> t; // uncomment if it's multitest
	while(t--)
	{
		solve();
	}
	
}
