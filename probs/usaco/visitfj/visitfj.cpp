#include <bits/stdc++.h>

using namespace std;

#define int long long
#define mp make_pair
int n, T, gd[105][105], dist[105][105];
typedef pair<int,int> pii;
typedef pair<int,pii> iii;
#define f first
#define s second

int dx[] = {1, 0, -1, 0, -3, -2, -2, -1, -1, 0, 0, 1, 1, 2, 2, 3};
int dy[] = {0, 1, 0, -1, 0, 1, -1, 2, -2, 3, -3, 2, -2, 1, -1, 0};

main()
{
	freopen("visitfj.in", "r", stdin);
	freopen("visitfj.out", "w", stdout);
	cin >> n >> T;
	for(int i = 0; i < n; i++) for(int j = 0; j < n; j++)
	{
		cin >> gd[i][j];
	}
	memset(dist, 0x7f, sizeof dist);
	dist[0][0] = 0;
	queue<iii> q;
	q.push(mp(dist[0][0], mp(0,0)));
	long long ans = LLONG_MAX;
	while(!q.empty())
	{
		iii tp = q.front();
		q.pop();
		int d = tp.f;
		int i = tp.s.f;
		int j = tp.s.s;
		if(d > dist[i][j]) continue;
		if(abs(n-1-i)+abs(n-1-j) < 3)
		{
			ans = min(ans, d+T*(abs(n-1-i)+abs(n-1-j)));
		}
		for(int it = 0; it < 16; it++)
		{
			int ni = i+dx[it];
			int nj = j+dy[it];
			if(ni < 0 || ni >= n || nj < 0 || nj >= n) continue;
			if(d + gd[ni][nj] + 3*T > dist[ni][nj]) continue;
			dist[ni][nj] = d + gd[ni][nj] + 3*T;
			q.push(mp(dist[ni][nj], mp(ni,nj)));
		}
	}
	cout << ans << endl;
}