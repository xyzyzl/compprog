#include <bits/stdc++.h>

using namespace std;

int n, a[550], dp[550][550];
int main()
{
	freopen("248.in", "r", stdin);
	freopen("248.out", "w", stdout);
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> a[i];
	for(int i = 0; i < n; i++)
	{
		dp[i][i] = a[i];
	}
	for(int l = 1; l < n; l++)
	{
		for(int i = 0; i < n; i++)
		{
			int j = i+l;
			for(int k = 0; k < l; k++)
			{
				if(dp[i][i+k] && dp[i][i+k] == dp[i+k+1][j]) dp[i][j] = dp[i][i+k]+1;
			}
		}
	}
	int ans = 0;
	for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) ans = max(ans, dp[i][j]);
	cout << ans << endl;
}