#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll n, x, v[200005], dp[200005];

int main()
{
	cin >> n >> x;
	for (int i = 0; i < n; i++)
		cin >> v[i];
	vector<ll> lis(n);
	fill(lis.begin(), lis.end(), INT_MAX);
	ll k = 0;
	// longest increasing subsequence ending at i
	for(int i = 0; i < n; i++)
	{
		int j = lower_bound(lis.begin(), lis.end(), v[i])-lis.begin();
		lis[j] = v[i];
		dp[i] = j+1;
		k = max(k, dp[i]);
	}
	fill(lis.begin(), lis.end(), INT_MAX);
	// longest decreasing subsequence ending at i = longest increasing subsequence starting at i
	for(int i = n-1; i >= 0; i--)
	{
		int j = lower_bound(lis.begin(), lis.end(), -v[i]+x)-lis.begin();
		int jj = lower_bound(lis.begin(), lis.end(), -v[i])-lis.begin();
		lis[jj] = -v[i];
		k = max(k, dp[i]+j); // minus one because i would be included twice
	}
	cout << k << endl;
}