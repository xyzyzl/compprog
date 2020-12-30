#include <bits/stdc++.h>

using namespace std;

int n, dp[205][205];
string S;
int main()
{
	cin >> S;
	n = S.length();
	memset(dp, 0x7f, sizeof dp);
	for(int i = 0; i < n; i++)
	{
		dp[i][i] = 1;
	}
	for(int l = 1; l <= n; l++)
	{
		for(int i = 0; i < n-l+1; i++)
		{
			int j = i+l;
			if((S[i] == '(' && S[j] == ')') || (S[i] == '[' && S[j] == ']'))
			{
				if(i+1 <= j-1) dp[i][j] = dp[i+1][j-1];
				else dp[i][j] = 0;
			}
			for(int k = i; k < j; k++)
			{
				dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j]);
			}
		}
	}
	cout << dp[0][n-1] << endl;
}