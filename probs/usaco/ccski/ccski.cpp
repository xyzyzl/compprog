#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // pbds
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>

#pragma GCC optimize("O3")

using namespace __gnu_pbds;
using namespace std;

#define MAXN 505

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

int m,n,elv[MAXN][MAXN];
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
bool v[MAXN][MAXN],w[MAXN][MAXN];

bool out(int i, int j)
{
	if(i < 0 || j < 0 || i >= m || j >= n) return 1;
	return 0;
}

void bfs(ll D)
{
	queue<pii> q;
	int si = 0, sj = 0;
	FOR(i, m) FOR(j, n) if(w[i][j]) { si=i; sj=j; }
	q.push(mp(si,sj));
	while(!q.empty())
	{
		pii x = q.front();
		q.pop();
		int i=x.f;
		int j=x.s;
		if(out(i,j)) continue;
		FOR(a, 4)
		{
			int ni = i+dx[a], nj = j+dy[a];
			if(out(ni,nj)) continue;
			if(!v[ni][nj] && abs(elv[i][j]-elv[ni][nj]) <= D)
			{
				q.push(mp(ni,nj));
				v[ni][nj] = 1;
			}
		}
	}
}

bool ok(ll D)
{
	memset(v, 0, sizeof v);
	bfs(D);
	FOR(i, m) FOR(j, n) if(w[i][j] && !v[i][j]) return 0;
	return 1;
}

void solve()
{
	cin >> m >> n;
	FOR(i, m) FOR(j, n)
	{
		cin >> elv[i][j];
	}
	FOR(i, m) FOR(j, n) cin >> w[i][j];
	ll lo = 0, hi = 1e9+1;
	while(lo+1 < hi)
	{
		int mid = (lo+hi)/2;
		if(ok(mid)) hi=mid;
		else lo = mid;
	}
	if(ok(0)) cout << 0 << endl;
	else cout << hi << endl;
}

signed main()
{
	fileio("ccski.in", "ccski.out");
	DUEHOANG;
	int t = 1;
	// cin >> t; // uncomment if it's multitest
	while(t--)
	{
		solve();
	}
	
}
