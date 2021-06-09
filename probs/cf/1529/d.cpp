#include <bits/stdc++.h>

using namespace std;

const int MOD = 998244353;

int n;
int dp[2*1000005];
int main()
{
	cin >> n;
	dp[0] = 1;	
	for(int i = 1; i <= n; i++)
	{
		for(int j = i*2; j <= n; j += i)
		{
			dp[j]++;
		}
	}
	int sm = 1;
	for(int i = 1; i <= n; i++)
	{
		dp[i] = (dp[i] + sm)%MOD;
		sm = (sm + dp[i])%MOD;
	}
	cout << dp[n] << endl;
}
