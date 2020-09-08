#include <bits/stdc++.h>

using namespace std;

int n, grid[25][25], dist[4][25][25][4][25][25], vis[4][25][25][4][25][25];
struct state
{
	int da, xa, ya, db, xb, yb;
	state(int da, int xa, int ya, int db, int xb, int yb)
	{
		this->da = da;
		this->xa = xa;
		this->ya = ya;
		this->db = db;
		this->xb = xb;
		this->yb = yb;
	}
};

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
state forward(state cur)
{
	int nxa = cur.xa;
	int nya = cur.ya;
	if(nxa < n-1 || nya < n-1)
	{
		nxa += dx[cur.da];
		nya += dy[cur.da];
	}
	if(nxa < 0 || nya < 0 || nxa >= n || nya >= n || grid[nxa][nya])
	{
		nxa = cur.xa;
		nya = cur.ya;
	}
	int nxb = cur.xb;
	int nyb = cur.yb;
	if(nxb < n-1 || nyb < n-1)
	{
		nxb += dx[cur.db];
		nyb += dy[cur.db];
	}
	if(nxb < 0 || nyb < 0 || nxb >= n || nyb >= n || grid[nxb][nyb])
	{
		nxb = cur.xb;
		nyb = cur.yb;
	}
	return state(cur.da, nxa, nya, cur.db, nxb, nyb);
}

state left(state cur)
{
	return state((cur.da + 3) % 4, cur.xa, cur.ya, (cur.db + 3) % 4, cur.xb, cur.yb);
}

state right(state cur)
{
	return state((cur.da + 1) % 4, cur.xa, cur.ya, (cur.db + 1) % 4, cur.xb, cur.yb);
}

int main()
{
	freopen("cownav.in", "r", stdin);
	freopen("cownav.out", "w", stdout);
	cin >> n;
	for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) 
	{
		char c;
		cin >> c;
		grid[n-1-i][j] = (c == 'H');
	}
	queue<state> q;
	q.push(state(0,0,0,1,0,0));
	while(!q.empty())
	{
		// can go left, right, or straight
		state x = q.front();
		q.pop();
		if(x.xa == n-1 && x.ya == n-1 && x.xb == n-1 && x.yb == n-1)
		{
			cout << dist[x.da][x.xa][x.ya][x.db][x.xb][x.yb] << endl;
			break;
		}
		vector<state> v;
		v.push_back(left(x));
		v.push_back(right(x));
		v.push_back(forward(x));
		for(state nx : v)
		{
			if(vis[nx.da][nx.xa][nx.ya][nx.db][nx.xb][nx.yb]) continue;
			vis[nx.da][nx.xa][nx.ya][nx.db][nx.xb][nx.yb] = 1;
			dist[nx.da][nx.xa][nx.ya][nx.db][nx.xb][nx.yb] = dist[x.da][x.xa][x.ya][x.db][x.xb][x.yb] + 1;
			q.push(nx);
		}
	}
}