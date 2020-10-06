#include <bits/stdc++.h>

using namespace std;

int n, m, dp[505][505][505], arr[505][505][505];
int w[100005], l[100005], r[100005];
int main()
{
	cin >> n >> m;
	for(int i = 0; i < m; i++)
	{
		cin >> w[i] >> l[i] >> r[i];
	}
	
	for(int l = n-1; l >= 0; l--) for(int r = l; r < n; r++)
	{
		for(int i = l; i < r; i++)
		{
			dp[l][r] = max(dp[l][r], dp[l][i] + dp[i+1][r]);
		}
	}
}