#include <bits/stdc++.h>

using namespace std;

int n, dS[1005][1005], dR[1005][1005], vs[1005][1005];
double D;
char gr[1005][1005];
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };
typedef pair<int, int> pii;
#define f first
#define s second
vector<pii> ok[1000005];
int main()
{
	cin >> n >> D;
	for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) cin >> gr[i][j];
	queue<pii> q;
	memset(dS, 0x7f, sizeof dS);
	memset(dR, 0x7f, sizeof dR);
	for(int i = 0; i < n; i++) for(int j = 0; j < n; j++)
	{
		if(gr[i][j] == '#')
		{
			q.push({i,j});
			dR[i][j] = 0;
		}
	}
	while(!q.empty())
	{
		pii tp = q.front();
		q.pop();
		int x = tp.f;
		int y = tp.s;
		for(int k = 0; k < 4; k++)
		{
			int nx = x+dx[k];
			int ny = y+dy[k];
			if(nx < 0 || nx >= n || ny < 0 || ny >= n || gr[nx][ny] == '#') continue;
			if(dR[nx][ny] > dR[x][y]+1)
			{
				dR[nx][ny] = min(dR[nx][ny], dR[x][y] + 1);
				q.push({nx,ny});
			}
		}
	}
	for(int i = 0; i < n; i++) for(int j = 0; j < n; j++)
	{
		if(gr[i][j] == 'S')
		{
			q.push({i,j});
			dS[i][j] = 0;
		}
	}
	while(!q.empty())
	{
		pii tp = q.front();
		q.pop();
		int x = tp.f;
		int y = tp.s;
		ok[dR[x][y]-1].push_back({x,y});
		vs[x][y] = 1;
		if(dS[x][y] >= D*dR[x][y]) continue;
		for(int k = 0; k < 4; k++)
		{
			int nx = x+dx[k];
			int ny = y+dy[k];
			if(nx < 0 || nx >= n || ny < 0 || ny >= n || gr[nx][ny] == '#') continue;
			if(dS[nx][ny] > dS[x][y]+1)
			{
				dS[nx][ny] = min(dS[nx][ny], dS[x][y] + 1);
				q.push({nx,ny});
			}
		}
	}
	// do bfs smartly from highest distance to lowest distance
	queue<pii> last;
	queue<pii> cur;
	for(int i = n*n-1; i >= 0; i--)
	{
		swap(last, cur);
		while(!last.empty()) last.pop();
		while(!cur.empty())
		{
			// put everything in cur
			pii tp = cur.front();
			cur.pop();
			for(int k = 0; k < 4; k++)
			{
				if(gr[tp.f+dx[k]][tp.s+dy[k]] == '#') continue;
				if(tp.f + dx[k] < 0 || tp.f + dx[k] >= n || tp.s + dy[k] < 0 || tp.f + dy[k] >= n) continue;
				if(vs[tp.f+dx[k]][tp.s+dy[k]]) continue;
				last.push(make_pair(tp.f + dx[k], tp.s + dy[k]));
				vs[tp.f+dx[k]][tp.s+dy[k]] = 1;
			}
		}
		for(pii x : ok[i]) last.push(x);
	}
	int ans = 0;
	for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) ans+=vs[i][j];
	cout << ans << endl;
}