#include <stdio.h>
#include <string.h>

#define ll long long
#define MAX(a, b) ((a > b) ? a : b)

int n, m, k, i, j;
ll a[5005], psum[5005], dp[5005][5005];
signed main()
{
	scanf("%d %d %d", &n, &m, &k);
	for(i = 1; i <= n; i++)
	{
		scanf("%lld", &a[i]);
		psum[i] = psum[i-1] + a[i];
	}
	memset(dp, -0x7f, sizeof dp);
	for(i = 0; i <= n; i++) dp[i][0] = 0;
	for(i = 1; i <= n; i++) for(j = 1; j <= k; j++)
	{
		dp[i][j] = dp[i-1][j];
		if(i >= m)
		{
			if(dp[i-m][j-1] < 0) continue;
			dp[i][j] = MAX(dp[i][j], dp[i-m][j-1] + psum[i] - psum[i-m]);
		}
	}
	printf("%lld\n", dp[n][k]);
}