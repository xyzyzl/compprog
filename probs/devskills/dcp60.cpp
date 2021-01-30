#include <bits/stdc++.h>

using namespace std;

int n, m;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int gr[1005][1005], vis[1005][1005], dist[1005][1005];
int solve()
{
	memset(gr, 0, sizeof gr);
	memset(vis, 0, sizeof vis);
	memset(dist, 0x7f, sizeof dist);
	cin >> n >> m;
	for(int i = 0; i < n; i++) for(int j = 0; j < m; j++)
	{
		char c; cin >> c;
		gr[i][j] = c - '1';
	}
	queue<pair<int, int> > q;
	q.push({0, 0});
	dist[0][0] = 0;
	while(!q.empty())
	{
		pair<int, int> tp = q.front(); q.pop();
		for(int i = 0; i < 4; i++)
		{
			int nx = tp.first + dx[i];
			int ny = tp.second + dy[i];
			if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			int w = dist[tp.first][tp.second] + (gr[nx][ny]!=gr[tp.first][tp.second]);
			if(dist[nx][ny] <= w) continue;
			dist[nx][ny] = w;
			q.push({nx, ny});
		}
	}
	return dist[n-1][m-1];
}

int main()
{
	int t; cin >> t;
	for(int i = 0; i < t; i++) cout << "Case " << i+1 << ": " << solve() << endl;
}