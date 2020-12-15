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

int n, m, ans[MAXN][MAXN];
char gr[MAXN][MAXN];
pii c, d;
queue<pii> q;

pii fall(pii x, int dir)
{
	while(1)
	{
		if(x.f < 0 || x.f > n-1 || x.s < 0 || x.s > m-1)
		{
			return mp(-1, -1);
		}
		if(gr[x.f][x.s] == 'D')
		{
			return mp(x.f, x.s);
		}
		if(gr[x.f][x.s] == '#')
		{
			return mp(x.f-dir, x.s);
		}
		x.f += dir;
	}
}

pii flip(pii x, int dir)
{
	return fall(x, -dir);
}

pii left(pii x, int dir)
{
	x.s--;
	if(x.s < 0 || x.s >= m || gr[x.f][x.s] == '#') return mp(-1, -1);
	return fall(x, dir);
}

pii right(pii x, int dir)
{
	x.s++;
	if(x.s < 0 || x.s >= m || gr[x.f][x.s] == '#') return mp(-1, -1);
	return fall(x, dir);
}

bool floodfill(pii x, int col)
{
	// find the state that contains x and add to the queue
	if(ans[x.f][x.s]) return 0;
	queue<pii> w;
	w.push(x);
	while(!w.empty())
	{
		pii tp = w.front();
		w.pop();
		if(tp.f < 0) continue;
		if(ans[tp.f][tp.s]) continue;
		q.push(tp);
		ans[tp.f][tp.s] = col;
		if(tp == d) return 1;
		w.push(left(tp, (ans[tp.f][tp.s]%2 ? 1 : -1)));
		w.push(right(tp, (ans[tp.f][tp.s]%2 ? 1 : -1)));
	}
	return 0;
}

void solve()
{
	cin >> n >> m;
	FOR(i, n) FOR(j, m)
	{
		char a; cin >> a;
		gr[i][j] = a;	
		if(a == 'C')
		{
			c.f=i;
			c.s=j;
		}
		else if(a == 'D')
		{
			d.f=i;
			d.s=j;
		}
	}
	// find each bfs state with bfs
	bool wjf = floodfill(fall(c, 1), 1);
	if(wjf)
	{
		cout << 0 << endl;
		return;
	}
	while(!q.empty())
	{
		pii tp = q.front();
		q.pop();
		if(tp.f < 0) continue;
		pii x = flip(tp, (ans[tp.f][tp.s]%2 ? 1 : -1));
		if(floodfill(x, (ans[tp.f][tp.s] + 1))) break;
	}
	cout << ans[d.f][d.s] - 1 << endl;
}

signed main()
{
	fileio("gravity");
	DUEHOANG;
	int t = 1;
	// cin >> t; // uncomment if it's multitest
	while(t--)
	{
		solve();
	}
	
}
