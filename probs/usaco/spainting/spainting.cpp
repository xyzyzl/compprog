#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MOD 1000000007

int n,m,k;
// keep psums of dp[i] to get constant time for 
// originally O(N) part
ll dp_S[1000005];
int main()
{
	freopen("spainting.in", "r", stdin);
	freopen("spainting.out","w",stdout);
	cin >> n >> m >> k;
	for(int i = 1; i < k; i++)
	{
		// dp_S[i] = sum of all previous dp[i]
		dp_S[i] = (m*dp_S[i-1]+m)%MOD;
	}
	for(int i = k; i <= n; i++)
	{
		// everything goes except for ones with k consecutive equal digits.
		// there are m-1 different usable colors.
		dp_S[i] = (m*dp_S[i-1]-(m-1)*dp_S[i-k]+MOD)%MOD;
	}
	// find m^n.
	ll all = 1;
	for(int i = 0; i < n; i++) all = (all * m) % MOD;
	// remove dp[n] = (dp_S[n] - dp_s[n-1])
	cout << (all-(dp_S[n]-dp_S[n-1])+MOD)%MOD << endl;
}