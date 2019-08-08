#include <bits/stdc++.h>

using namespace std;

#define MAXN 1000005

int n;
int dp[MAXN];
int main()
{
	cin >> n;
	fill(dp, dp + n + 1, INT_MAX);
	dp[n] = 0;
	for (int i = n; i >= 0; i--)
	{
		if(dp[i] == INT_MAX) continue;
		string o = to_string(i);
		for (int j = 0; j < o.length(); j++)
		{
			int ta = o[j] - '0';
			if (i >= ta)
				dp[i - ta] = min(dp[i - ta], dp[i] + 1);
		}
	}
	cout << dp[0] << endl;
}