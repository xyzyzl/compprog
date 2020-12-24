#include <bits/stdc++.h>

using namespace std;

int m,n,arr[15];
int dp[15][5000];
int main()
{
	cin >> m >> n;
	for(int i = 0; i < m; i++)
	{
		for(int j = 0; j < n; j++)
		{
			int x; cin >> x;
			arr[i] |= (!x);
			arr[i] *= 2;
		}
		arr[i] /= 2;
	}
	for(int i = 0; i < (1 << n); i++)
	{
		dp[0][i] = 1;
		if(i&(2*i) || i&arr[0]) dp[0][i] = 0;
	}
	for(int k = 1; k < m; k++)
	{
		for(int i = 0; i < (1 << n); i++)
		{
			if(i&(2*i) || i&arr[k]) continue; // dp[k][i] = 0;
			for(int j = 0; j < (1 << n); j++)
			{
				if(i&j) continue; // cannot pair (k-1,j) and (k,i).
				dp[k][i] += dp[k-1][j];
				dp[k][i] %= (int)(1e8);
			}
		}
	}
	int ans = 0;
	for(int i = 0; i < (1 << n); i++)
	{
		ans = (ans + dp[m-1][i]) % (int)(1e8);
	}
	cout << ans << endl;
}