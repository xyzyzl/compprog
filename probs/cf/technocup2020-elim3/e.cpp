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

int n, m;
int dx[8] = { 1, 0, -1, 0, 1, 1, -1, -1 };
int dy[8] = { 0, 1, 0, -1, 1, -1, 1, -1 };
vector<vi> ans,gr,ds,vis;

bool fit(int x, int y)
{
	return !(x < 0 || x > n+1 || y < 0 || y > m+1);
}

void bfs()
{
	queue<pii> q;
	FOR(i, n+2) FOR(j, m+2)
	{
		ds[i][j] = MOD;
		if(!gr[i][j])
		{
			q.push(mp(i,j));
			ds[i][j] = 0;
		}
	}
	while(!q.empty())
	{
		pii tp = q.front();
		q.pop();
		if(vis[tp.f][tp.s]) continue;
		vis[tp.f][tp.s]=1;
		int i = tp.f;
		int j = tp.s;
		FOR(k,8)
		{
			if(!fit(i+dx[k],j+dy[k])) continue;
			ds[i+dx[k]][j+dy[k]] = min(ds[i+dx[k]][j+dy[k]],ds[i][j]+1);
			q.push(mp(i+dx[k],j+dy[k]));
		}
	}
}

void solve()
{
	cin>>n>>m;
	ans = vector<vi>(n+10, vi(m+10,0));
	gr = vector<vi>(n+10, vi(m+10,0));
	ds = vector<vi>(n+10, vi(m+10,0));
	vis = vector<vi>(n+10, vi(m+10,0));
	F1R(i, n) F1R(j, m)
	{
		char c;
		cin >> c;
		gr[i][j] = c=='X';
	}
	bfs();
	int lo = 0;
	int hi = min(n,m);
	while(lo < hi-1)
	{
		int mid = (lo+hi)/2;
		vii org;
		F1R(i, n) F1R(j, m)
		{
			if(gr[i][j] && ds[i][j] >= mid)
			{
				org.pb(mp(i,j));
				cerr << i << " " << j << endl;
			}
		}
		if(org.size()) lo=mid;
		else hi = mid-1;
	}
	cout << lo-1 << endl;
	F1R(i, n)
	{
		F1R(j, m)
		{
			if(gr[i][j] && ds[i][j] >= lo) cout << 'X';
			else cout << '.';
		}
		cout << endl;
	}
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
