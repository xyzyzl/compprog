#include <bits/stdc++.h>

using namespace std;
const int MAXN = 1005;

int n, m, gr[MAXN][MAXN], d1[MAXN][MAXN], d2[MAXN][MAXN];
pair<int, int> P[MAXN][MAXN];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int main()
{
	memset(d1, 0x7f, sizeof d1);
	cin >> n >> m;
	int sx = 0, sy = 0;
	for(int i = 0; i < n; i++) for(int j = 0; j < m; j++)
	{
		char x; cin >> x;
		if(x=='.') gr[i][j] = 1;
		if(x=='#')
		{
			gr[i][j] = 0;
			d1[i][j] = 0;
		}
		if(x=='M') gr[i][j] = 2;
		if(x=='A')
		{
			sx = i, sy = j;
			gr[i][j] = 3;
		}
	}
	queue<pair<int, int> > q;
	for(int i = 0; i < n; i++) for(int j = 0; j < n; j++)
	{
		if(gr[i][j] == 2)
		{
			q.push({i, j});
			d1[i][j] = 0;
		}
	}
	while(!q.empty())
	{
		pair<int, int> tp = q.front();
		q.pop();
		int x = tp.first;
		int y = tp.second;
		for(int i = 0; i < 4; i++)
		{
			int nx = x+dx[i];
			int ny = y+dy[i];
			if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if(gr[nx][ny] == 0) continue;
			if(d1[nx][ny] > 1 + d1[x][y])
			{
				q.push({nx, ny});
				d1[nx][ny] = 1 + d1[x][y];
			}
		}
	}
	q.push({sx, sy});
	d1[sx][sy] = 0;
	int ex=-1, ey=-1;
	while(!q.empty())
	{
		pair<int, int> tp = q.front();
		q.pop();
		int x = tp.first;
		int y = tp.second;
		for(int i = 0; i < 4; i++)
		{
			int nx = x+dx[i];
			int ny = y+dy[i];
			if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if(gr[nx][ny] == 0) continue;
			if(d1[nx][ny] > 1 + d1[x][y])
			{
				q.push({nx, ny});
				d1[nx][ny] = 1 + d1[x][y];
				P[nx][ny] = {x, y};
			}
		}
		if(tp.first == 0 || tp.second == 0 || tp.first == n-1 || tp.second == m-1) 
		{
			ex = tp.first;
			ey = tp.second;
		}
	}
	if(ex == -1)
	{
		cout << "NO" << endl;
		return 0;
	}
	cout << "YES" << endl;
	vector<char> V;
	while(ex != sx || ey != sy)
	{
		int nex = P[ex][ey].first;
		int ney = P[ex][ey].second;
		if(nex > ex) V.push_back('U');
		else if(nex < ex) V.push_back('D');
		else if(ney > ey) V.push_back('L');
		else if(ney < ey) V.push_back('R');
		ex = nex;
		ey = ney;
		// cerr << ex << " " << ey << endl;
	}
	cout << V.size() << endl;
	reverse(V.begin(), V.end());
	for(char c : V) cout << c;
	cout << endl;
}
