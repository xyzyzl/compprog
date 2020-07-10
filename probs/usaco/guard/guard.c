#include <stdio.h>
#include <limits.h>

#define MAX(a,b) ((a > b) ? a : b)
#define MIN(a,b) ((a < b) ? a : b)

#define MAXN 20
#define INF LLONG_MAX;
#define ll long long

int n;
ll h[MAXN], w[MAXN], s[MAXN], H, dp[(1<<MAXN)][3];
int main()
{
	freopen("guard.in", "r", stdin);
	freopen("guard.out", "w", stdout);
	scanf("%d %lld", &n, &H);
	for(int i = 0; i < n; i++)
	{
		scanf("%lld %lld %lld", &h[i], &w[i], &s[i]);
	}
	// if this isn't infinite then it can't add any cows lol
	dp[0][1] = INF;
	// do DP somehow
	ll ans = -1;
	int msk = 1;
	for(int msk = 1; msk < (1 << n); msk++)
	{
		dp[msk][0] = dp[msk][2] = 0;
		dp[msk][1] = -1;
		for(int i = 0; i < n; i++)
		{
			if(!(msk & (1 << i))) continue;
			dp[msk][0] += h[i];
			dp[msk][2] += w[i];
			dp[msk][1] = MAX(dp[msk][1], MIN(dp[msk - (1 << i)][1], s[i] - dp[msk - (1 << i)][2]));
		}
		if(dp[msk][0] >= H) ans = MAX(ans, dp[msk][1]);
	}
	if(ans < 0) puts("Mark is too tall");
	else printf("%lld\n", ans);
}
