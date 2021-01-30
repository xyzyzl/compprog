#include <bits/stdc++.h>

using namespace std;

int gr[8][8], vis[8][8], dist[8][8];
int dx[8] = {2, 2, 1, 1, -1, -1, -2, -2};
int dy[8] = {1, -1, 2, -2, 2, -2, 1, -1};
int main()
{
	int t; cin >> t; while(t--)
	{
		memset(gr, 0, sizeof gr);
		memset(vis, 0, sizeof vis);
		memset(dist, 0, sizeof dist);
		string p1, p2; cin >> p1 >> p2;
		pair<int, int> S = {p1[0]-'a', p1[1]-'1'};
		pair<int, int> E = {p2[0]-'a', p2[1]-'1'};
		queue<pair<int, int> > q;
		q.push({S.first, S.second});
		while(!q.empty())
		{
			pair<int, int> tp = q.front(); q.pop();
			vis[tp.first][tp.second] = 1;
			for(int i = 0; i < 8; i++)
			{
				int nx = tp.first + dx[i];
				int ny = tp.second + dy[i];
				if(nx < 0 || nx >= 8 || ny < 0 || ny >= 8) continue;
				if(vis[nx][ny]) continue;
				dist[nx][ny] = dist[tp.first][tp.second] + 1;
				q.push({nx, ny});
			}
		}
		cout << dist[E.first][E.second] << endl;
	}
}