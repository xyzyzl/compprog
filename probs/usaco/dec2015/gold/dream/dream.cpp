#include <bits/stdc++.h>

using namespace std;

#define int long long

int n, m, gr[1005][1005];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
bool vis[1005][1005][2][4];
struct state
{
	int x, y, smell, dir, dist;
	state(int x, int y, int smell, int dir, int dist)
	{
		this->x=x;
		this->y=y;
		this->smell=smell;
		this->dir=dir;
		this->dist=dist;
	}
};

signed main()
{
	freopen("dream.in", "r", stdin);
	freopen("dream.out", "w", stdout);
	cin >> n >> m;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++) cin >> gr[i][j];
	}
	deque<state> q;
	q.push_back(state(0, 0, 0, 0, 0));
	q.push_back(state(0, 0, 0, 1, 0));
	while(!q.empty())
	{
		state cur = q.front();
		q.pop_front();
		if(cur.x == n-1 && cur.y == m-1)
		{
			cout << cur.dist << endl;
			return 0;
		}
		if(vis[cur.x][cur.y][cur.smell][cur.dir]) continue;
		vis[cur.x][cur.y][cur.smell][cur.dir] = 1;
		if(gr[cur.x][cur.y] == 0) continue;
		else if(gr[cur.x][cur.y] == 1)
		{
			for(int i = 0; i < 4; i++)
			{
				if(cur.x + dx[i] < 0 || cur.x + dx[i] >= n || cur.y + dy[i] < 0 || cur.y + dy[i] >= m) continue;
				q.push_back(state(cur.x + dx[i], cur.y + dy[i], 
							(gr[cur.x+dx[i]][cur.y+dy[i]] == 2 ? 1 : 
							(gr[cur.x+dx[i]][cur.y+dy[i]] == 4 ? 0 : cur.smell)),
							i, cur.dist+1));
				state nex = q.back();
				if(vis[nex.x][nex.y][nex.smell][nex.dir] || gr[nex.x][nex.y] == 0 || (gr[nex.x][nex.y] == 3 && !nex.smell))
					q.pop_back();
			}
		}
		else if(gr[cur.x][cur.y] == 2)
		{
			for(int i = 0; i < 4; i++)
			{
				if(cur.x + dx[i] < 0 || cur.x + dx[i] >= n || cur.y + dy[i] < 0 || cur.y + dy[i] >= m) continue;
				q.push_back(state(cur.x + dx[i], cur.y + dy[i], 
							(gr[cur.x+dx[i]][cur.y+dy[i]] == 2 ? 1 : 
							(gr[cur.x+dx[i]][cur.y+dy[i]] == 4 ? 0 : cur.smell)),
							i, cur.dist+1));
				state nex = q.back();
				if(vis[nex.x][nex.y][nex.smell][nex.dir] || gr[nex.x][nex.y] == 0 || (gr[nex.x][nex.y] == 3 && !nex.smell))
					q.pop_back();
			}
		}
		else if(gr[cur.x][cur.y] == 3)
		{
			if(cur.smell == 0) continue;
			for(int i = 0; i < 4; i++)
			{
				if(cur.x + dx[i] < 0 || cur.x + dx[i] >= n || cur.y + dy[i] < 0 || cur.y + dy[i] >= m) continue;
				q.push_back(state(cur.x + dx[i], cur.y + dy[i], 
							(gr[cur.x+dx[i]][cur.y+dy[i]] == 2 ? 1 : 
							(gr[cur.x+dx[i]][cur.y+dy[i]] == 4 ? 0 : cur.smell)),
							i, cur.dist+1));
				state nex = q.back();
				if(vis[nex.x][nex.y][nex.smell][nex.dir] || gr[nex.x][nex.y] == 0 || (gr[nex.x][nex.y] == 3 && !nex.smell))
					q.pop_back();
			}
		} else
		{
			int i = cur.dir;
			if(cur.x + dx[i] < 0 || cur.x + dx[i] >= n || cur.y + dy[i] < 0 || cur.y + dy[i] >= m)
			{
				for(int i = 0; i < 4; i++)
				{
					if(cur.x + dx[i] < 0 || cur.x + dx[i] >= n || cur.y + dy[i] < 0 || cur.y + dy[i] >= m) continue;
					q.push_back(state(cur.x + dx[i], cur.y + dy[i], 
								(gr[cur.x+dx[i]][cur.y+dy[i]] == 2 ? 1 : 
								(gr[cur.x+dx[i]][cur.y+dy[i]] == 4 ? 0 : cur.smell)),
								i, cur.dist+1));
					state nex = q.back();
					if(vis[nex.x][nex.y][nex.smell][nex.dir] || gr[nex.x][nex.y] == 0 || (gr[nex.x][nex.y] == 3 && !nex.smell))
					{
						q.pop_back();
					}
				}
				continue;
			}
			q.push_back(state(cur.x + dx[i], cur.y + dy[i], 
						(gr[cur.x+dx[i]][cur.y+dy[i]] == 2 ? 1 : 
						(gr[cur.x+dx[i]][cur.y+dy[i]] == 4 ? 0 : cur.smell)),
						i, cur.dist+1));
			state nex = q.back();
			if(vis[nex.x][nex.y][nex.smell][nex.dir]) q.pop_back();
			else if(gr[nex.x][nex.y] == 0 || (gr[nex.x][nex.y] == 3 && !nex.smell))
			{
				q.pop_back();
				for(int i = 0; i < 4; i++)
				{
					if(cur.x + dx[i] < 0 || cur.x + dx[i] >= n || cur.y + dy[i] < 0 || cur.y + dy[i] >= m) continue;
					q.push_back(state(cur.x + dx[i], cur.y + dy[i], 
								(gr[cur.x+dx[i]][cur.y+dy[i]] == 2 ? 1 : 
								(gr[cur.x+dx[i]][cur.y+dy[i]] == 4 ? 0 : cur.smell)),
								i, cur.dist+1));
					state nex = q.back();
					if(vis[nex.x][nex.y][nex.smell][nex.dir] || gr[nex.x][nex.y] == 0 || (gr[nex.x][nex.y] == 3 && !nex.smell))
					{
						q.pop_back();
					}
				}
			}
		}
	}
	cout << -1 << endl;
}
