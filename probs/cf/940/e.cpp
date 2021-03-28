#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int n, c;
ll a[100005], ps[100005];
ll dp[100005];
int main()
{
	cin >> n >> c;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		ps[i] = ps[i-1] + a[i];
		dp[i] = ps[i];
	}
	dp[0] = 0;
	multiset<ll> ms;
	for(int i = 1; i <= n; i++)
	{
		dp[i] = dp[i-1] + a[i]; // obviously you can just make another subarray here, and if it doesn't cover at least c it should be 1
		ms.insert(a[i]);
		
		// take by intervals of C, as opposed to by 1. we remove the smallest element in each, which we keep in a multiset.
		// we then update the multiset with sliding window. this is not a hard problem but STL is hard.
		if(i >= c)
		{
			dp[i] = min(dp[i], dp[i-c] + ps[i]-ps[i-c] - *ms.begin());
			ms.erase(ms.find(a[i-c+1])); // oh my god this should be ms.erase ms.find i not ms.erase i
			// holy i am such an idiot
		}
	}
	cout << dp[n] << endl;
}	
