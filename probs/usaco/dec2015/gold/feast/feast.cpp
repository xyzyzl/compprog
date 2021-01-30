#include <bits/stdc++.h>

using namespace std;

int T, A, B, dp[5000005][2];
int main()
{
	freopen("feast.in", "r", stdin);
	freopen("feast.out", "w", stdout);
	cin >> T >> A >> B;
	// eat orange, eat lemon, or drink water
	dp[0][0] = 1;
	for(int i = 0; i <= T; i++)
	{
		if(i >= A) dp[i][0] |= dp[i-A][0];
		if(i >= B) dp[i][0] |= dp[i-B][0];
		dp[i/2][1] |= dp[i][0];
	}
	for(int i = 0; i <= T; i++)
	{
		if(i >= A) dp[i][1] |= dp[i-A][1];
		if(i >= B) dp[i][1] |= dp[i-B][1];
	}
	int mx = 0;
	for(int i = 0; i <= T; i++)
	{
		if(dp[i][0] || dp[i][1])
		{
			mx = i;
		}
	}
	cout << mx << endl;
}