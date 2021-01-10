#include <bits/stdc++.h>

using namespace std;

#define ll long long
int n;
ll w, wt[255], ta[255];

bool ok(ll ratio)
{
	vector<ll> dp(w+1, -1e18); // stores total talent - (ratio)*total width
	dp[0] = 0;
	for(int c = 0; c < n; c++)
	{
		for(int i = w; i >= 0; i--)
		{
			dp[min(i+wt[c], w)] = max(dp[min(i+wt[c], w)], dp[i]+1000ll*ta[c]-ratio*wt[c]); // we multiplied everything by 1000
		}
	}
	return dp[w] >= 0; // if the ratio is not too big for all the cows to collectively reach
}

int main()
{
	freopen("talent.in", "r", stdin);
	freopen("talent.out", "w", stdout);
	cin >> n >> w;
	for(int i = 0; i < n; i++) cin >> wt[i] >> ta[i];
	// bsearch on the total ratio
	ll lo = 0, hi = 250*1000*1000+1;
	while(lo < hi-1)
	{
		ll mid = (lo+hi)/2ll;
		if(ok(mid)) lo = mid;
		else hi = mid;
	}
	cout << lo << endl;
}