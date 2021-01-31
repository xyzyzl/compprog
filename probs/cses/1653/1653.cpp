#include <bits/stdc++.h>

using namespace std;

int n, X, w[25];
int dp[(1 << 21)], L[(1 << 21)];
int main()
{
	cin >> n >> X;
	for(int i = 0; i < n; i++)
	{
		cin >> w[i];
	}
	dp[0] = 1;
	L [0] = 0;
	for(int msk = 1; msk < (1 << n); msk++)
	{
		dp[msk] = n+1;
		L[msk]  = 0;
		for(int i = 0; i < n; i++) if(msk & (1 << i))
		{
			int x = dp[msk ^ (1 << i)];
			int y = L [msk ^ (1 << i)];
			if(y + w[i] <= X)
			{
				y+=w[i];
			} else
			{
				x++; y=w[i];
			}
			if(dp[msk] > x || (dp[msk] == x && L[msk] > y))
			{
				dp[msk] = x;
				L [msk] = y;
			}
		}
	}
	cout << dp[(1 << n)-1] << endl;
}
