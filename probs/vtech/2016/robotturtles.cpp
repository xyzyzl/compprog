#include <bits/stdc++.h>

using namespace std;

int n = 8, vis[8][8][4];
char gr[8][8];

struct state
{
	int x, y, d;
	vector<char> p;
	bool operator<(state s) const
	{
		return this->p.size() > s.p.size();
	}
};

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

bool is_in(int x, int y)
{
	return (0 <= x && x < n && 0 <= y && y < n);
}

int main()
{
	for(int i = 0; i < n; i++) for(int j = 0; j < n; j++)
	{
		cin >> gr[i][j]; if(gr[i][j] == 'C') vis[i][j][0] = vis[i][j][1] = vis[i][j][2] = vis[i][j][3] = 1;
	}
	vis[7][0][0] = 1;
	priority_queue<state> q;
	state init;
	init.x = 7;
	init.y = 0;
	init.d = 0;
	init.p = vector<char>();
	q.push(init);
	while(!q.empty())
	{
		state f = q.top();
		q.pop();
		// reached the end
		if(gr[f.x][f.y] == 'D')
		{
			for(char c : f.p) cout << c;
			cout << endl;
			return 0;
		}
		// otherwise, move forward or turn left/right
		// forward
		{
			int x = f.x+dx[f.d], y = f.y+dy[f.d];
			state nf;
			nf.x=x;
			nf.y=y;
			nf.d=f.d;
			nf.p=f.p;
			if(is_in(x,y) && !vis[x][y][f.d]) 
			{
				vis[x][y][f.d] = 1;
				// is ice castle
				if(gr[x][y] == 'I')
				{
					nf.p.push_back('X');
				}
				nf.p.push_back('F');
				q.push(nf);
			}
		}
		// turn left
		{
			int x = f.x, y = f.y, d = (f.d + 3)%4;
			state nf;
			nf.x=x;
			nf.y=y;
			nf.d=d;
			nf.p=f.p;
			if(!vis[x][y][d])
			{
				vis[x][y][d] = 1;
				nf.p.push_back('L');
				q.push(nf);
			}
		}
		// turn right
		{
			int x = f.x, y = f.y, d = (f.d + 1)%4;
			state nf;
			nf.x=x;
			nf.y=y;
			nf.d=d;
			nf.p=f.p;
			if(!vis[x][y][d])
			{
				vis[x][y][d] = 1;
				nf.p.push_back('R');
				q.push(nf);
			}
		}
	}
	// cannot reach the diamond
	cout << "no solution" << endl;
}