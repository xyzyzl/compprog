#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1005;

int n, bit[MAXN][MAXN];

void updy(int x, int y, int val)
{
	while(y <= n)
	{
		bit[x][y] += val;
		y += (y&-y);
	}
}

void upd(int x, int y, int val)
{
	while(x <= n)
	{
		updy(x, y, val);
		x += (x&-x);
	}
}

int quey(int x, int y)
{
	int ret = 0;
	while(y > 0)
	{
		ret += bit[x][y];
		y -= (y & -y);
	}
	return ret;
}

int que(int x, int y)
{
	int ret = 0;
	while(x > 0)
	{
		ret += quey(x, y);
		x -= (x & -x);
	}
	return ret;
}

int que(int x0, int y0, int x1, int y1)
{
	int b1 = que(max(x0, x1), max(y0, y1));
	int b2 = que(min(x0, x1)-1, max(y0, y1));
	int b3 = que(max(x0, x1), min(y0, y1)-1);
	int b4 = que(min(x0, x1)-1, min(y0, y1)-1);
	return b1-b2-b3+b4;
}

bool has[MAXN][MAXN];

int main()
{
	int t;
	cin >> n >> t;
	for(int i = 1; i <= n; i++) for(int j = 1; j <= n; j++)
	{
		char k;
		cin >> k;
		if(k == '*') upd(i, j, 1);
		has[i][j] = (k=='*');
	}
	while(t--)
	{
		int ty; cin >> ty;
		if(ty == 1)
		{
			int x, y; cin >> x >> y;
			upd(x, y, (has[x][y] ? -1 : 1));
			has[x][y] = !has[x][y];
		} else 
		{
			int x0, x1, y0, y1;
			cin >> x0 >> y0 >> x1 >> y1;
			cout << que(x0, y0, x1, y1) << endl;
		}
	}
}