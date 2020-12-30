#include <stdio.h>

#define MAX(a, b) ((a > b) ? a : b)

int n, arr[255], dp[255][255], i, l, r, m;
int main()
{
	scanf("%d", &n);
	for(i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
		arr[i+n] = arr[i];
	}
	for(r = 0; r < 2*n; r++)
	{
		for(l = r; l >= 0 && l > r-n; l--)
		{
			for(m = l; m < r; m++)
			{
				dp[l][r] = MAX(dp[l][r], dp[l][m] + dp[m+1][r] + arr[l]*arr[m+1]*arr[r+1]);
			}
		}
	}
	int ans = 0;
	for(i = 0; i < n; i++)
	{
		ans = MAX(ans, dp[i][i+n-1]);
	}	
	printf("%d\n", ans);
}