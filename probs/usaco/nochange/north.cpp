#include <bits/stdc++.h>

using namespace std;

int k, n;
int main()
{
	freopen("nochange.in", "r", stdin);
	freopen("nochange.out", "w", stdout);
	cin >> k >> n;
	vector<int> coin(k);
	for(int i = 0; i < k; i++) cin >> coin[i];
	vector<int> item(n+1);
	for(int i = 1; i <= n; i++) cin >> item[i];
	// dp state: dp[i] is the best # items using only the subset determined by i
	for(int i = 1; i <= n; i++) item[i] += item[i-1];
	vector<int> dp(1 << k);
	int ans = -1;
	for(int mask = 1; mask < (1 << k); mask++)
	{
		int best = 0;
		int unneeded = 0;
		for(int i = 0; i < k; i++)
		{
			int m = (1 << i);
			if(mask&m)
			{
				int last = item[dp[mask^m]]; // everything except m
				int x = upper_bound(item.begin(), item.end(), last + coin[i]) - item.begin() - 1;
				best = max(best, x);
			} else 
			{
				unneeded += coin[i];
			}
		}
		dp[mask] = best;
		// cout << unneeded << " " << best << endl;
		if(best == n) ans = max(ans, unneeded);
	}
	cout << ans << endl;
}
