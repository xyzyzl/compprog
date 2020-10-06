#include <bits/stdc++.h>

using namespace std;

int n, m, dp[305][305], arr[305][305][305];
int main()
{
	freopen("pieaters.in", "r", stdin);
	freopen("pieaters.out", "w", stdout);
	cin >> n >> m;
	for(int i = 0; i < m; i++)
	{
		int w,l,r;
		cin >> w >> l >> r;
		--l; --r;
		for(int k = l; k <= r; k++)
		{
			arr[k][l][r] = max(arr[k][l][r], w);
		}
	}

	for(int i = 0; i < n; i++)
	{
		for(int l = i; l >= 0; l--) for(int r = i; r < n; r++)
		{
			if(l > 0) arr[i][l-1][r] = max(arr[i][l][r], arr[i][l-1][r]);
			if(r < n-1) arr[i][l][r+1] = max(arr[i][l][r], arr[i][l][r+1]);
		}
	}

	for(int l = n-1; l >= 0; l--) for(int r = l; r < n; r++)
	{
		for(int i = l; i <= r; i++)
		{
			if(i < r) dp[l][r] = max(dp[l][r], dp[l][i] + dp[i+1][r]);
			if(arr[i][l][r])
			{
				dp[l][r] =
					max(dp[l][r], arr[i][l][r] + (i > l ? dp[l][i-1] : 0) + (i < r ? dp[i+1][r] : 0));
				int x = arr[i][l][r];
			}
		}
	}
	cout << dp[0][n-1] << endl;
}
