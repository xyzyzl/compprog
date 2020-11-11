#include <bits/stdc++.h>

using namespace std;

#define ll long long
int n;
ll L, d[25], c[25], a[25][1005];
ll dp[2000005];

int best_ind(int time, int mv)
{
	int lo = -1, hi = c[mv] - 1;
	while(lo < hi)
	{
		int md = (lo+hi+1)/2;
		if(a[mv][md] <= time)
		{
			lo = md;
		} else 
		{
			hi = md-1;
		}
	}
	return lo;
}

int main()
{
	freopen("movie.in", "r", stdin);
	freopen("movie.out", "w", stdout);
	cin >> n >> L;
	for(int i = 0; i < n; i++)
	{
		cin >> d[i] >> c[i];
		for(int j = 0; j < c[i]; j++)
		{
			cin >> a[i][j];
		}
	}
	for(int i = 0; i < (1 << n); i++) dp[i] = -1;
	dp[0] = 0;
	int ans=INT_MAX;
	for(int msk = 0; msk < (1 << n); msk++)
	{
		if(dp[msk] == -1) continue; // is impossible
		if(dp[msk] >= L) ans = min(ans, __builtin_popcount(msk));
		for(int i = 0; i < n; i++)
		{
			if(msk & (1 << i)) continue; // cannot watch same movie twice
			int k = best_ind(dp[msk], i); // binary search on best time to switch
			if(k == -1) continue;
			dp[(msk | (1 << i))] = max(dp[(msk | (1 << i))], a[i][k] + d[i]);
		}
	}
	if(ans == INT_MAX) cout << -1 << endl;
	else cout << ans << endl;
}
