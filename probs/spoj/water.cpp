#include <bits/stdc++.h>

using namespace std;

#define int long long
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
using pii=pair<int, int>;
using iii=pair<int, pii>;
#define f first
#define s second
int gr[105][105], vis[105][105], ans[105][105];
signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	int t; cin >> t;
	while(t--)
	{
		memset(vis, 0, sizeof vis);
		memset(ans, 0, sizeof ans);
		int n, m; cin >> n >> m;
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < m; j++)
			{
				cin >> gr[i][j];
			}
		}
		priority_queue<iii, vector<iii>, greater<iii> > q;
		vis[0][0] = 1;
		vis[0][m-1] = 1;
		vis[n-1][0] = 1;
		vis[n-1][m-1] = 1;
		for(int i = 1; i < n-1; i++)
		{
			q.push({gr[i][0], {i, 0}});
			vis[i][0] = 1;
			q.push({gr[i][m-1], {i, m-1}});
			vis[i][m-1] = 1;
		}
		for(int i = 1; i < m-1; i++)
		{
			q.push({gr[0][i], {0, i}});
			vis[0][i] = 1;
			q.push({gr[n-1][i], {n-1, i}});
			vis[n-1][i] = 1;
		}
		while(!q.empty())
		{
			iii tp = q.top();
			q.pop();
			for(int i = 0; i < 4; i++)
			{
				int nx = tp.s.f + dx[i];
				int ny = tp.s.s + dy[i];
				if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
				if(vis[nx][ny]) continue;
				vis[nx][ny] = 1;
				ans[nx][ny] = max(gr[nx][ny], tp.f);
				q.push({max(gr[nx][ny], tp.f), {nx, ny}});
			}
		}
		long long ret = 0;
		for(int i = 1; i < n-1; i++) for(int j = 1; j < m-1; j++)
		{
			ret += ans[i][j] - gr[i][j];
		}
		cout << ret << endl;
	}
}