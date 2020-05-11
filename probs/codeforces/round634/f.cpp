#include <bits/stdc++.h>

using namespace std;

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int n, m;
vector<bool> col, vis;
vector<int> dir;
vector<vector<int> > aft; // aft[i][j] = i after 2^j moves

bool good(int node)
{
	int x = node / m;
	int y = node % m;
	return (0 <= x && x < n && 0 <= y && y < m);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while(t--)
	{
		cin >> n >> m;
		int lgNM = 0;
		while((1 << lgNM) <= (n*m)) lgNM++;
		// cout << lgNM << endl;
		col = vector<bool>(n*m);
		dir = vector<int>(n*m);
		vis = vector<bool>(n*m);
		aft = vector<vector<int> >(n*m, vector<int>(lgNM));
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < m; j++)
			{
				char c;
				cin >> c;
				col[i*m+j] = c - '0';
			}
		}
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < m; j++)
			{
				char c;
				cin >> c;
				if(c == 'U')
					dir[i*m+j] = (i+dx[0])*m+(j+dy[0]);
				else if(c == 'R')
					dir[i*m+j] = (i+dx[1])*m+(j+dy[1]);
				else if(c == 'D')
					dir[i*m+j] = (i+dx[2])*m+(j+dy[2]);
				else
					dir[i*m+j] = (i+dx[3])*m+(j+dy[3]);
				aft[i*m+j][0] = dir[i*m+j];
			}
		}
		// cerr << "fdkldkljrkljnm sfda" << endl;
		for(int d = 1; d < lgNM; d++)
		{
			for(int i = 0; i < n; i++)
			{
				for(int j = 0; j < m; j++)
				{
					int v = i*m+j;
					aft[v][d] = aft[aft[v][d-1]][d-1];
				}
			}
		}
		// cerr << "dedede" << endl;
		// now find black,white things
		vector<int> pl_b, pl_w;
		pl_b = vector<int>(n*m);
		pl_w = vector<int>(n*m);
		for(int i = 0; i < n*m; i++)
		{
			int dst = i;
			for(int d = lgNM - 1; d >= 0; d--)
			{
				if(((n*m) >> d) & 1) dst = aft[dst][d];
			}
			if(col[i]) pl_w[dst]++;
			else pl_b[dst]++;
		}
		int a = 0, b = 0;
		for(int i = 0; i < n*m; i++)
		{
			if(pl_b[i])
			{
				a++; b++;
			} else if(pl_w[i]) a++;
		}
		cout << a << " " << b << endl;
	}
}

