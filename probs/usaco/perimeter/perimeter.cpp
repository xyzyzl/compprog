#include <bits/stdc++.h>

using namespace std;

int n, grid[1005][1005], vis[1005][1005];
int area[1000005], peri[1000005];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

void dfs(int i, int j, int col)
{
	if(vis[i][j]) return;
	vis[i][j] = col;
	area[col]++;
	for(int k = 0; k < 4; k++)
	{
		if(grid[i+dx[k]][j+dy[k]]) dfs(i+dx[k], j+dy[k], col);
		else peri[col]++;
	}
}

int main()
{
	freopen("perimeter.in", "r", stdin);
	freopen("perimeter.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i++) for(int j = 1; j <= n; j++)
	{
		char c;
		cin >> c;
		if(c == '#') grid[i][j] = 1;
	}
	int col = 0;
	for(int i = 1; i <= n; i++) for(int j = 1; j <= n; j++)
	{
		if(vis[i][j] || !grid[i][j]) continue;
		dfs(i, j, ++col);
	}
	int mxa = 0, mnp = 0;
	for(int i = 1; i <= col; i++)
	{
		if(mxa < area[i])
		{
			mxa = area[i];
			mnp = peri[i];
		} else if(mxa == area[i])
		{
			mnp = min(mnp, peri[i]);
		}
	}
	cout << mxa << " " << mnp << endl;
}
