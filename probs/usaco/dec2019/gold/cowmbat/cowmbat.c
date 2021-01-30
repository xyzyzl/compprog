#include <stdio.h>
#include <string.h>

#define min(a, b) ((a < b) ? a : b)
#define MAXN 100005

int n, m, k, a[MAXN], c[26][26], p[MAXN][26], dp[MAXN][26];
int i, j, jj;
int main()
{
	freopen("cowmbat.in", "r", stdin);
	freopen("cowmbat.out", "w", stdout);
	scanf("%d %d %d", &n, &m, &k);
	getchar();
	for(i = 1; i <= n; i++)
	{
		char x;
		scanf("%c", &x);
		// printf("char: %c\n", x);
		a[i] = x - 'a';
	}
	for(i = 0; i < m; i++)
		for(j = 0; j < m; j++)
		{
			scanf("%d", &c[i][j]);
		}
	for(jj = 0; jj < m; jj++) for(i = 0; i < m; i++) for(j = 0; j < m; j++)
	{
		if(c[i][jj] + c[jj][j] < c[i][j]) c[i][j] = c[i][jj]+c[jj][j];
	}
	for(i = 0; i < m; i++)
	{
		for(j = 1; j <= n; j++)
		{
			p[j][i] = p[j-1][i] + c[a[j]][i];
		}
	}
	memset(dp, 63, sizeof dp);
	for(i = 0; i < m; i++) dp[0][i] = 0;
	for(i = 1; i <= n; i++)
	{
		for(j = 0; j < m; j++)
		{
			if(i > 1) dp[i][j] = min(dp[i][j], dp[i-1][j] + c[a[i]][j]);
			for(jj = 0; jj < m; jj++)
			{
				if(i >= k) dp[i][j] = min(dp[i][j], dp[i-k][jj] + (p[i][j] - p[i-k][j]));
			}
		}
	}
	int mn = (1 << 30) + 7;
	for(i = 0; i < m; i++)
	{
		mn = min(mn, dp[n][i]); 
	}
	printf("%d\n", mn);
}
