#include <bits/stdc++.h>
#define int long long

using namespace std;

void solve()
{
	int n; cin >> n;
	vector<int> a(n+1);
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	// we keep a prefix sum for every value
	map<int, int> ct;
	vector<long long> dp(n+1);
	for(int i = 1; i <= n; i++)
	{
		dp[i] += dp[i-1];
		dp[i] += ct[a[i]];
		ct[a[i]]+=i;
	}
	long long sum = 0;
	for(int i = 1; i <= n; i++)
		sum += dp[i];
	cout << sum << endl;
}

signed main() { int t; cin >> t; while(t--) solve(); }