#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n = 9;
		int grid[9][9];
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
			{
				char c;
				cin >> c;
				grid[i][j] = (c-'0');
			}
		// change 9 numbers
		grid[0][0] = grid[0][0]%9 + 1;
		grid[3][1] = grid[3][1]%9 + 1;
		grid[6][2] = grid[6][2]%9 + 1;
		grid[1][3] = grid[1][3]%9 + 1;
		grid[4][4] = grid[4][4]%9 + 1;
		grid[7][5] = grid[7][5]%9 + 1;
		grid[2][6] = grid[2][6]%9 + 1;
		grid[5][7] = grid[5][7]%9 + 1;
		grid[8][8] = grid[8][8]%9 + 1;
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < n; j++) cout << grid[i][j];
			cout << endl;
		}
	}
}