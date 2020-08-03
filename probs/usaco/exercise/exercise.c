#include <stdio.h>

#define ll long long

int n, m, primes[1500], nprimes, vis[10005], i, j;
ll dp[1500][10005];
int main()
{
	freopen("exercise.in", "r", stdin);
	freopen("exercise.out", "w", stdout);
	scanf("%d %d", &n, &m);
	primes[0] = 1;
	nprimes = 0;
	for(i = 2; i <= n; i++)
	{
		if(vis[i]) continue;
		primes[++nprimes] = i;
		for(j = i; j <= n; j+=i) vis[j] = 1;
	}
	for(i = 0; i < nprimes; i++)
	{
		dp[i][0] = 1;
	}
	for(i = 0; i <= n; i++)
	{
		dp[0][i] = 1;
	}
	for(i = 1; i <= nprimes; i++)
	{
		for(j = 1; j <= n; j++)
		{
			dp[i][j] = dp[i-1][j]; // use previous primes and just add 1
			int p = primes[i];
			while(p <= j)
			{
				dp[i][j] = (dp[i][j] + (p*dp[i-1][j-p]) % m) % m;
				p *= primes[i];
			}
		}
	}
	printf("%lld\n", (dp[nprimes][n] % m));
}
