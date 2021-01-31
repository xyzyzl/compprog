#include <bits/stdc++.h>

using namespace std;

int n;
int w[1005][1005];
int pw[1005][1005];
int main()
{
	int q;
	cin >> n >> q;
	for(int i = 1; i <= n; i++) for(int j = 1; j <= n; j++)
	{
		char c; cin >> c;
		w[i][j] = (c == '*');
	}
	pw[0][0] = w[0][0];
	for(int i = 1; i <= n; i++) for(int j = 1; j <= n; j++)
	{
		pw[i][j] += w[i][j];
		if(i > 1) pw[i][j] += pw[i-1][j];
		if(j > 1) pw[i][j] += pw[i][j-1];
		if(i > 1 && j > 1) pw[i][j] -= pw[i-1][j-1];
	}
	while(q--)
	{
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		--x1; --y1;
		cout << pw[x2][y2] - pw[x1][y2] - pw[x2][y1] + pw[x1][y1] << endl;
	}
}
