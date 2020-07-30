#include <bits/stdc++.h>

using namespace std;

int N;
// to prevent overflow if any
long long W, w[1005], t[1005];

// knapsack to check if X is a valid answer
bool ok(long long X)
{
	vector<long long> dp(W+1, -1e16);
	dp[0] = 0;
	// for all cows, add to all different positions
	for(int j = 0; j < N; j++)
	{
		// try all different positions. most of these will not have any effect
		for(int i = W; i >= 0; i--)
		{
			// we want 1000*t_total - X*w_total to be greater than 0.
			dp[min(i+w[j], W)] = max(dp[min(i+w[j], W)], dp[i] + 1000ll*t[j] -
					X*w[j]);
		}
	}
	// check if 1000*t_total - X*w_total >= 0
	return dp[W] >= 0;
}

int main()
{
	freopen("talent.in", "r", stdin);
	freopen("talent.out", "w", stdout);
	cin >> N >> W;
	for(int i = 0; i < N; i++)
	{
		cin >> w[i] >> t[i];
	}
	// bsearch
	long long lo = 0;
	// must be highest possible attainable ratio
	long long hi = 250*1000*1000+1;
	while(lo < hi-1)
	{
		long long X = (lo+hi)/2;
		if(ok(X))
		{
			lo = X;
		} else
		{
			hi = X;
		}
	}
	cout << lo << endl;
}
