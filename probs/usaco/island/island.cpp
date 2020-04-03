#include <bits/stdc++.h>
#pragma GCC optimize("O3")

using namespace std;

#define MAXN 17
#define MAXR 55
#define MAXS 140000

#define ll long long

typedef pair<int, int> pii;
typedef pair<int, pii> iii; // dist, (r,c)
#define f first
#define s second
#define mp make_pair

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int r, c, grid[MAXR][MAXR], n;
int col[MAXR][MAXR], dist[MAXN][MAXN], dist_from_src[MAXR][MAXR];
// each island, distance between two islands, distance from source to some node
const int INF = 2000000000;
bool ok(int i, int j)
{
	return ((i >= 0) && (i < r) && (j >= 0) && (j < c));
}
void floodfill(int i, int j)
{
	// if(i < 0 || j < 0) cerr << "aye" << endl;
	col[i][j] = n;
	for(int a = 0; a < 4; a++)
	{
		// cerr << a << endl;
		if(!ok(i+dx[a], j+dy[a])) continue;
		if(grid[i+dx[a]][j+dy[a]] == 2 && !col[i+dx[a]][j+dy[a]])
			floodfill(i + dx[a], j + dy[a]);
	}
}

int subs[MAXS], dp[MAXN][MAXS];

bool comp(int a, int b)
{
	return __builtin_popcount(a) < __builtin_popcount(b); // process
	// vertices from smallest subset to biggest
}

int tsp()
{
	memset(dp, 0x7f, sizeof dp);
	// clearly if only one point is included the
	// total distance should be 0
	for(int i = 1; i <= n; i++)
	{
		dp[i][(1 << (i-1))] = 0;
	}
	// generate all subsets of vertices
	int m=0;
	for(int i = 0; i < (1 << n); i++) subs[m++] = i;
	sort(subs, subs+(1<<n), comp);
	for(int a = 0; a < m; a++)
	{
		int x = subs[a];
		for(int i = 0; i < n; i++)
		{
			if(dp[i+1][x] < INF)
			{
				for(int j = 0; j < n; j++)
				{
					dp[j+1][x | (1 << j)] = min(dp[j+1][x | (1 << j)], dp[i+1][x] + dist[i+1][j+1]);
				}
			}
		}
	}
	int ans = INF;
	for(int i = 1; i <= n; i++)
	{
		ans = min(ans, dp[i][(1 << n)-1]);
	}
	return ans;
}

int main()
{
	freopen("island.in", "r", stdin);
	freopen("island.out", "w", stdout);
	cin >> r >> c;
	// cout << "this is broken" << endl;
	for(int i = 0; i < r; i++)
	{
		for(int j = 0; j < c; j++)
		{
			char c;
			cin >> c;
			if(c == 'X')
			{
				grid[i][j] = 2;
			} else if(c == 'S')
			{
				grid[i][j] = 1;
			} else grid[i][j] = 0;
		}
	}
	// find all of the islands
	for(int i = 0; i < r; i++) for(int j = 0; j < c; j++)
	{
		if(!col[i][j] && grid[i][j] == 2)
		{
			++n;
			floodfill(i, j);
		}
	}

	/*
	for(int i = 0; i < r; i++)
	{
		for(int j = 0; j < c; j++)
		{
			cout << col[i][j] << " ";
		}
		cout << endl;
	}
	*/

	// cerr << "bruh" << endl;
	// cout << n << endl;
	// return 0;
	// for each island find the total distance between island and other islands
	memset(dist, 63, sizeof dist);
	// cout << dist[0][0] << endl;
	for(int i = 1; i <= n; i++)
	{
		int x_i = -1, y_i = -1;
		for(int x = 0; x < r; x++)
		{
			for(int y = 0; y < c; y++)
			{
				if(col[x][y] == i)
				{
					x_i = x;
					y_i = y;
					break;
				}
			}
		}
		memset(dist_from_src, 63, sizeof dist_from_src);
		queue<iii> q;
		q.push(mp(0, mp(x_i, y_i)));
		while(!q.empty())
		{
			iii top = q.front();
			q.pop();
			// if(i == 4) cerr << top.s.f << " " << top.s.s << endl;
			if(!ok(top.s.f, top.s.s)) continue;
			if(col[top.s.f][top.s.s]) // at some other island
			{
				dist[i][col[top.s.f][top.s.s]] = 
					min(top.f, dist[i][col[top.s.f][top.s.s]]);
			}
			int x = top.s.f, y = top.s.s;
			for(int a = 0; a < 4; a++)
			{
				int nx = x+dx[a];
				int ny = y+dy[a];
				// if(!ok(nx, ny)) continue;
				if(grid[nx][ny] == 2)
				{
					if(dist_from_src[nx][ny] > top.f) // over land
					{
						dist_from_src[nx][ny] = top.f;
						q.push(mp(top.f, mp(nx, ny)));
					}
				} else if(grid[nx][ny] == 1) // over shallow water
				{
					if(dist_from_src[nx][ny] > top.f + 1)
					{
						dist_from_src[nx][ny] = top.f+1;
						q.push(mp(top.f + 1, mp(nx, ny)));
					}
				}
			}
		}
	}
	// cout << dist[1][2] << endl;
	// run the tsp problem to find the best hamiltonian path
	/*
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= n; j++) cout << dist[i][j] << " ";
		cout << endl;
	}
	*/
	cout << tsp() << endl;
}
