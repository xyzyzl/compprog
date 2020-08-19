// URL: https://codeforces.com/contest/1093/problem/F

#include <stdio.h>

#define ll long long
#define MOD 998244353

#define MAXN 100005
#define MAXK 105

int n, k, len;
int a[MAXN], frq[MAXN][MAXK], dp[MAXN][MAXK];
int aux[MAXN];
int SUM(int a, int b)
{
	ll c = a;
	ll d = b;
	return (c + d) % MOD;
}
int main()
{
	scanf("%d %d %d", &n, &k, &len);
	for(int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
	}
	for(int j = 1; j <= k; j++)
	{
		for(int i = 1; i <= n; i++)
		{
			frq[i][j] = frq[i-1][j] + (a[i] == j || a[i] == -1);
		}
	}
	aux[0] = 1;
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= k; j++)
		{
			if(a[i] != j && a[i] != -1) continue;
			int local = aux[i-1];

			if(i >= len && frq[i][j] - frq[i-len][j] == len)
			{
				if(i == len) local = SUM(local, MOD - 1);
				else local = SUM(local, SUM(dp[i-len][j], MOD - aux[i-len]));
			}
			dp[i][j] = SUM(dp[i][j], local);
		}
		for(int j = 1; j <= k; j++)
		{
			aux[i] = SUM(aux[i], dp[i][j]);
		}
	}
	printf("%d\n", aux[n]);
}
