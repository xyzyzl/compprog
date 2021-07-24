#include <bits/stdc++.h>

using namespace std;

string s;
int vis[8][8];
int ways = 0;

bool diag(int i, int j)
{
	// number of adjacent open positions
	int c = 0;
	// only for new squares
	if(vis[i][j]) return 0;
	if(i-1 >= 0 && !vis[i-1][j]) c++;
	if(i+1 < 7 && !vis[i+1][j]) c++;
	if(j-1 >= 0 && !vis[i][j-1]) c++;
	if(j+1 < 7 && !vis[i][j+1]) c++;
	if(i==6&&j==0&&c) return 0;
	return (c < 2);
}

bool noout(int i, int j)
{
	int inx = 0, iny = 0;
	if(i-1 >= 0 && !vis[i-1][j]) inx++;
	if(i+1 < 7 && !vis[i+1][j]) inx++;
	if(j-1 >= 0 && !vis[i][j-1]) iny++;
	if(j+1 < 7 && !vis[i][j+1]) iny++;
	return ((inx==0&&iny==2)||(iny==0&&inx==2));
}


void rec(int n, int i, int j)
{
	if(vis[i][j])
		return;
	vis[i][j]=n+1;

	int fail = 0;
	if(i == 6 && j == 0) 
	{
		vis[i][j] = 0;
		if(n == 48)
		{
			ways++;
		}
		return;
	}
	// check if diagonals are open
	if(i-1 >= 0 && j-1 >= 0) fail |= diag(i-1, j-1);
	if(i+1 < 7 && j-1 >= 0) fail |= diag(i+1, j-1);
	if(i-1 >= 0 && j+1 < 7) fail |= diag(i-1, j+1);
	if(i+1 < 7 && j+1 < 7) fail |= diag(i+1, j+1);

	// check if currently trapped
	fail |= noout(i,j);	

	if(fail)
	{
		vis[i][j]=0;
		return;
	}

	if(n < 48)
	{
		if(s[n]=='?')
		{
			if(i-1 >= 0) rec(n+1,i-1,j);
			if(i+1 < 7) rec(n+1,i+1,j);
			if(j-1 >= 0) rec(n+1,i,j-1);
			if(j+1 < 7) rec(n+1,i,j+1);
		} else 
		{
			if(s[n]=='L' && j-1 >= 0) rec(n+1, i, j-1);
			else if(s[n]=='R' && j+1 < 7) rec(n+1, i, j+1);
			else if(s[n]=='U' && i-1 >= 0) rec(n+1, i-1, j);
			else if(s[n]=='D' && i+1 < 7) rec(n+1, i+1, j);		
		}
	}
	vis[i][j] = 0;
}

int main()
{
	cin >> s;
	rec(0,0,0);
	cout << ways << endl;
}
