#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int R,G,B,r[205],g[205],b[205];
long long dp[205][205][205];
int main()
{
	cin >> R >> G >> B;
	for(int i = 1; i <= R; i++) cin >> r[i];
	for(int i = 1; i <= G; i++) cin >> g[i];
	for(int i = 1; i <= B; i++) cin >> b[i];
	// forces largest to go w/ largest, smallest w/ smallest, etc.
	sort(r+1,r+R+1);
	sort(g+1,g+G+1);
	sort(b+1,b+B+1);
	for(int i = 0; i <= R; i++)
	{
		for(int j = 0; j <= G; j++)
		{
			for(int k = 0; k <= B; k++)
			{
				if(i&&j)
					dp[i][j][k] = max(dp[i][j][k], dp[i-1][j-1][k] + r[i]*g[j]);
				if(j&&k)
					dp[i][j][k] = max(dp[i][j][k], dp[i][j-1][k-1] + g[j]*b[k]);
				if(i&&k)
					dp[i][j][k] = max(dp[i][j][k], dp[i-1][j][k-1] + r[i]*b[k]);
			}
		}
	}
	long long mx = 0;
	for(int i = 1; i <= R; i++)
	{
		for(int j = 1; j <= G; j++)
		{
			for(int k = 1; k <= B; k++)
			{
				mx = max(mx, dp[i][j][k]);
			}
		}
	}
	cout << mx << endl;
}
