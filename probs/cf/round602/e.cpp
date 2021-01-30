// Time:
// Algorithms: 

#include <bits/stdc++.h>

#pragma GCC optimize("O3")

using namespace std;

#define MAXN 1000005

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

int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1};
int dy[8] = {0, 1, 0, -1, 1, -1, 1, -1};

int n, m;
vector<vi> grid; // X = 1, . = 0
vector<vi> dist, test, vis;
void read()
{
	cin >> n >> m;
	grid.resize(n);
	dist.resize(n);
	vis.resize(n);
	FOR(i, n)
	{
		dist[i].resize(m);
		grid[i].resize(m);
		vis[i].resize(m);
		FOR(j, m)
		{
			vis[i][j] = 0;
			dist[i][j] = INF;
			char c;
			cin >> c;
			if(c == 'X') grid[i][j] = 1;
			else grid[i][j] = 0;
		}
	}
}

void bfs()
{
	queue<pii> q;
	FOR(i, n)
	{
		FOR(j, m)
		{
			// if they exist and they're next to some burnt tree
			// mark in queue
			FOR(k, 8)
			{
				if(0 <= i+dx[k] && i+dx[k] < n && 0 <= j+dy[k] && j+dy[k] < m)
				{
					if(!grid[i+dx[k]][j+dy[k]] && grid[i][j])
					{
						q.push(mp(i, j));
						dist[i][j] = 0;
					}
				}
			}
			if(i == 0 || i == n-1 || j == 0 || j == m-1)
				if(grid[i][j])
				{
					// cout << i << " " << j << endl;
					q.push(mp(i, j));
					dist[i][j] = 0;
				}
		}
	}
	// cerr << "hmm?" << endl;
	while(!q.empty())
	{
		pii top = q.front();
		q.pop();
		int i = top.f;
		int j = top.s;
		if(vis[i][j]) continue;
		vis[i][j] = 1;
		FOR(k, 8) if(0 <= i+dx[k] && i+dx[k] < n && 0 <= j+dy[k] && j+dy[k] < m)
		{
			if(grid[i+dx[k]][j+dy[k]])
			{
				dist[i+dx[k]][j+dy[k]] = min(dist[i+dx[k]][j+dy[k]], dist[i][j] + 1);
				q.push(mp(i+dx[k], j+dy[k]));
			}
		}
	}
}

void solve()
{
	bfs();
	int lo = 0;
	int hi = min(n,m);
	while(lo < hi-1)
	{
		// 	cerr << lo << " " << hi << endl;
		int mid = (lo+hi)/2;
		test = vector<vi>(n+5, vi(m+5, INF));
		// cerr << test[0][0] << endl;
		queue<pii> q;
		FOR(i, n) FOR(j, m)
		{
			vis[i][j] = 0;
			// cout << dist[i][j] << " " << mid << endl;
			if(grid[i][j] && dist[i][j] >= mid)
			{
				q.push(mp(i,j));
				test[i][j] = 0;
			}
		}
		bool bad = q.empty();
		while(!q.empty())
		{
			pii top = q.front();
			q.pop();
			int i = top.f;
			int j = top.s;
			if(vis[i][j]) continue;
			vis[i][j] = 1;
			FOR(k, 8) if(0 <= i+dx[k] && i+dx[k] < n && 0 <= j+dy[k] && j+dy[k] < m)
			{
				if(grid[i+dx[k]][j+dy[k]])
				{
					test[i+dx[k]][j+dy[k]] = min(test[i+dx[k]][j+dy[k]], test[i][j] + 1);
					q.push(mp(i+dx[k], j+dy[k]));
				}
			}
		}
		FOR(i, n) FOR(j, m)
		{
			if(grid[i][j] && test[i][j] > mid)
			{
				bad = 1;
			}
		}
		if(!bad)
		{
			lo = mid;
		} else hi = mid;
	}
	cout << lo << endl;
	vector<vi> ans(n);
	FOR(i, n) ans[i].resize(m);
	vii starts;
	FOR(i, n) FOR(j, m)
	{
		if(dist[i][j] >= lo && grid[i][j])
		{
			starts.pb(mp(i, j));
		}
	}
	for(pii x : starts)
	{
		ans[x.f][x.s] = 1;
	}
	FOR(i, n)
	{
		FOR(j, m) cout << (ans[i][j] ? 'X' : '.');
		cout << endl;
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
