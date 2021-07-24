#include <bits/stdc++.h>

using namespace std;

char x[10][10];
int ans = 0;

bool l[15], r[15], u[15];

void rec(int j)
{
	if(j == 8)
	{
		ans++;
		return;
	}
	for(int i = 0; i < 8; i++)
	{
		if(x[i][j] == '.' && !l[i-j+7] && !r[i+j] && !u[i])
		{
			l[i-j+7] = 1;
			r[i+j] = 1;
			u[i] = 1;
			rec(j+1);
			l[i-j+7] = 0;
			r[i+j] = 0;
			u[i] = 0;
		}
	}
}

int main()
{
	for(int i = 0; i < 8; i++) for(int j = 0; j < 8; j++) cin >> x[i][j];
	rec(0);
	cout << ans << endl;
}