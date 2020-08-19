// Time:
// Algorithms: 

#include <bits/stdc++.h>

#pragma GCC optimize("O3")

using namespace std;

#define MAXN 1005

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

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

int n, m, t, dist[MAXN][MAXN], vis[MAXN][MAXN];
bool orig[MAXN][MAXN];
void read()
{
	cin >> n >> m >> t;
	FOR(i, n) FOR(j, m)
	{
		char c;
		cin >> c;
		orig[i][j] = c - '0';
	}
}

queue<pii> q;
void bfs()
{
	FOR(i, n) FOR(j, m)
	{
		FOR(x, 4)
		{
			if((0 <= i + dx[x]) && (i + dx[x] < n) && (0 <= j + dy[x])
					&& (j + dy[x] < m))
				if(orig[i][j] == orig[i+dx[x]][j+dy[x]])
				{
					q.push(mp(i, j));
					vis[i][j] = 1;
					dist[i][j] = 0;
					break; // to avoid overcount
				}
		}
	}
	while(!q.empty())
	{
		pii top = q.front();
		q.pop();
		int i = top.f;
		int j = top.s;
		// cerr << i << " " << j << endl;
		FOR(x, 4)
		{
			int ni = i + dx[x];
			int nj = j + dy[x];
			if(ni < 0 || ni >= n || nj < 0 || nj >= m || vis[ni][nj]) continue;
			dist[ni][nj] = dist[i][j] + 1;
			vis[ni][nj] = 1;
			q.push(mp(ni, nj));
		}
	}
}

void solve()
{
	bfs();
	while(t--)
	{
		int x, y;
		ll z;
		cin >> x >> y;
		cin >> z;
		--x; --y;
		if(vis[x][y])
		{
			cout << (orig[x][y] ^ (max(0ll ,z-dist[x][y]) & 1)) << endl;
		} else cout << orig[x][y] << endl;
	}
}

int main()
{
	DUEHOANG;
	int t = 1;
	// cin >> t; // uncomment if it's multitest
	while(t--)
	{
		read();
		solve();
	}
	
}
