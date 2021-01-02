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
int main()
{
	cin >> n >> D;
	for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) cin >> gr[i][j];
	queue<pii> q;
	memset(dS, 0x7f, sizeof dS);
	memset(dR, 0x7f, sizeof dR);
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
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			cout << dS[i][j] << ' ';
		}
		cout << endl;
	}
	for(int i = 0; i < n; i++) for(int j = 0; j < n; j++)
	{
		if((double)dS[i][j]/D <= (double)dR[i][j])
		{
			// cerr << i << " " << j << " " << dS[i][j]/D << endl;
			// this is a reachable location by the *original* bot
			int tD = dR[i][j];
			q.push({i,j});
			while(!q.empty())
			{
				pii x = q.front();
				vs[x.f][x.s] = 1;
				q.pop();
				bool no = 0;
				for(int k = 0; k < 4; k++)
				{
					int nx = x.f+dx[k];
					int ny = x.s+dy[k];
					if(gr[nx][ny] == '#')
					{
						no = 1;
					}
				}
				if(no) continue;
				for(int k = 0; k < 4; k++) 
				{
					int nx = x.f+dx[k];
					int ny = x.s+dy[k];
					if(gr[nx][ny] == '#')
					{
						continue;
					}
					if((double)dS[nx][ny]/D > (double)dR[i][j]) continue;
					if(vs[nx][ny] || abs(nx-i)+abs(ny-j) > tD) continue;
					q.push({nx,ny});
				}
			}
		}
	}
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++) cerr << vs[i][j];
		cerr << endl;
	}
	int ans = 0;
	for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) ans += vs[i][j];
	cout << ans << endl;
}