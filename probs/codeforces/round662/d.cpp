#include <bits/stdc++.h>

using namespace std;

int n, m, a[2005][2005], dp[2005][2005], vis[2005][2005];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

bool chk(int p, int q, int r, int s)
{
	return (p >= 0 && q >= 0 && r >= 0 && s >= 0
			&& p < n && q < m && r < n && s < m
			&& a[p][q] == a[r][s]);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
		{
			char c;
			cin >> c;
			a[i][j] = c-'a'+1;
		}
	memset(dp, 63, sizeof dp);
	queue<pair<int, int> > q;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
		{
			bool one = 0;
			for(int dir = 0; dir < 4; dir++)
			{
				if(!chk(i, j, i+dx[dir], j+dy[dir]))
				{
					one = 1;
				}
			}
			if(one)
			{
				dp[i][j] = 1;
				q.push(make_pair(i, j));
			}
		}
	while(!q.empty())
	{
		pair<int, int> t = q.front();
		q.pop();
		int i = t.first;
		int j = t.second;
		if(vis[i][j]) continue;
		vis[i][j] = 1;
		for(int dir = 0; dir < 4; dir++)
		{
			if(chk(i, j, i+dx[dir], j+dy[dir]) && !vis[i+dx[dir]][j+dy[dir]])
			{
				dp[i+dx[dir]][j+dy[dir]] = min(dp[i+dx[dir]][j+dy[dir]], dp[i][j] + 1);
				if(vis[i+dx[dir]][j+dy[dir]]) continue;
				q.push({i+dx[dir], j+dy[dir]});
			}
		}
	}
	long long ret = 0;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			ret += (long long) dp[i][j];
	cout << ret << endl;	
}
