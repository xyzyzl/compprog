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

int n, gd[MAXN][MAXN], vs[MAXN][MAXN];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

bool out(int i, int j)
{
	return (i < 0 || j < 0 || i >= n || j >= n);
}

bool bfs(int sx, int sy, int D)
{
	queue<pii> q;
	q.push(mp(sx,sy));
	int nv = 0;
	while(!q.empty())
	{
		pii x = q.front(); q.pop();
		int i = x.f, j = x.s;
		if(vs[i][j]) continue;
		vs[i][j] = 1;
		nv++;
		FOR(k, 4)
		{
			int ni = i+dx[k];
			int nj = j+dy[k];
			if(vs[ni][nj]) continue;
			if(out(ni,nj)) continue;
			if(abs(gd[i][j] - gd[ni][nj]) <= D)
			{
				q.push(mp(ni,nj));
			}
		}
	}
	return (nv >= n*n/2);
}

bool work(int D)
{
	memset(vs, 0, sizeof vs);
	FOR(i, n) FOR(j, n) if(!vs[i][j])
	{
		bool ok = bfs(i, j, D);
		if(ok) return true;
	}
	return false;
}

void solve()
{
	cin >> n;
	FOR(i, n) FOR(j, n) cin >> gd[i][j];
	int lo = 1, hi = 1e9+1;
	while(lo + 1 < hi)
	{
		int mid = (lo+hi)/2;
		if(work(mid)) hi = mid;
		else lo = mid;
	}
	cout << hi << endl;
}

signed main()
{
	fileio("tractor.in", "tractor.out");
	DUEHOANG;
	int t = 1;
	// cin >> t; // uncomment if it's multitest
	while(t--)
	{
		solve();
	}
	
}
