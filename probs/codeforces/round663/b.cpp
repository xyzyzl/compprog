#include <bits/stdc++.h>

using namespace std;

int n, m;
char grid[105][105];
int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		cin >> n >> m;
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < m; j++)
			{
				cin >> grid[i][j];
			}
		}
		int ch = 0;
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < m; j++)
			{
				int sx = i;
				int sy = j;
				while(sx < n && sy < m)
				{
					if(grid[sx][sy] == 'C') break;
					int nx = sx + (grid[sx][sy] == 'R' ? 0 : 1);
					int ny = sy + (grid[sx][sy] == 'D' ? 0 : 1);
					if(nx < 0 || nx >= n || ny < 0 || ny >= m)
					{
						ch++;
						if(grid[sx][sy] == 'R') grid[sx][sy] = 'D';
						else                    grid[sx][sy] = 'R';
					}
					sx = sx + (grid[sx][sy] == 'R' ? 0 : 1);
					sy = sy + (grid[sx][sy] == 'D' ? 0 : 1);
				}
			}
		}
		cout << ch << endl;
	}
}

