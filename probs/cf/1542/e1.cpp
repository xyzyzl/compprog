#include <bits/stdc++.h>

using namespace std;

const int MAXN = 55;
const int MAXI = 55*54/2;

int n, MOD;
int ans[MAXN], dp[MAXN][MAXI], cum[MAXN][MAXI];
int main()
{
	for(int i = 0; i < MAXN; i++) for(int j = 0; j < MAXI; j++)
	{
		dp[i][j] = 1;
		cum[i][j] = 1;
	}
	cin >> n >> MOD;
	for(int i = 1; i <= n*(n-1)/2; i++)
	{
		cum[0][i] = 1;
	}
	for(int i = 1; i <= n; i++)
	{
		for(int j = 0; j <= n*(n-1)/2; j++)
		{
			if(j-i >= 0) dp[i][j] = (cum[i-1][j]-cum[i-1][j-i]+MOD)%MOD;
			else dp[i][j] = cum[i-1][j];
			cum[i][j] = ((j?cum[i][j-1]:0)+dp[i][j]) % MOD;
		}
	}
	for(int i = 1; i <= n; i++) for(int j = 1; j <= i; j++) for(int k = j+1; k <= i; k++) for(int l = 0; l <= (i-1)*(i-2)/2; l++)
	{
		int t = l-(k-j)-1;
		if(t < 0) continue;
		ans[i] = (ans[i]+1ll*dp[i-1][l]*cum[i-1][t]%MOD)%MOD;
	}
	for(int i = 2; i <= n; i++) ans[i] = (ans[i]+1ll*i*ans[i-1])%MOD;
	cout << ans[n] << endl;
}
