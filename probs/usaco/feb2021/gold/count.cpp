// Found a grid pattern immediately after reading it
// Managed to solve Subtask 2 at time T=2 hours left
// Tried to but couldn't make progress on the rest
#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int q;
ll p3[40];
int main()
{
	cin >> q;
	p3[0] = 1;
	for(int i = 1; i < 39; i++)
	{
		p3[i] = p3[i-1]*3;
	}
	while(q--)
	{
		ll d,x,y;
		ll dp[3][2][2], dp2[3][2][2];
		memset(dp, 0, sizeof dp);
		dp[1][0][0] = 1;
		cin >> d >> x >> y;
		for(int i = 0; i < 39; i++)
		{
			memset(dp2, 0, sizeof dp2);
			int l = (d/p3[i])%3;
			int x_d = (x/p3[i])%3;
			int y_d = (y/p3[i])%3;
			for(int c = 0; c < 3; c++) for(int x_cr = 0; x_cr < 2; x_cr++) for(int y_cr = 0; y_cr < 2; y_cr++) for(int dig = 0; dig < 3; dig++)
			{
				int nx_d = (x_d + x_cr + dig)%3, nx_c = (x_d + x_cr + dig)/3;
				int ny_d = (y_d + y_cr + dig)%3, ny_c = (y_d + y_cr + dig)/3;
				int nc = c;
				if(dig > l) nc = 2;
				if(dig < l) nc = 0;
				if(nx_d%2 == ny_d%2)
				{
					dp2[nc][nx_c][ny_c]+=dp[c][x_cr][y_cr];
				}
			}
			swap(dp2,dp);
		}
		cout << dp[0][0][0] + dp[1][0][0] << endl;
	}
}