// I tried solving it a while in, but there were quite a few technicalities
// I made an incorrect submission with T=1 hour, but it went wrong
// I went to other questions to try and debug
// I went back here at T=2 minutes, and realized why it went wrong
// Tried to code it and got it to work at T=-1 minutes, but then I couldn't submit.
#include <bits/stdc++.h>

using namespace std;

const int MAXN = 305;

int n, a[MAXN], dp[MAXN][MAXN];
int main()
{
	cin >> n;
	for(int i = 0; i < n; i++) cin >> a[i];
	memset(dp, 0x7f, sizeof dp);
	for(int i = 0; i < n; i++) dp[i][i] = 1;
	for(int i = 0; i < n; i++) for(int j = i+1; j < n; j++) dp[j][i] = 0;
	for(int i = n-1; i >= 0; i--)
	{
		for(int j = i+1; j < n; j++)
		{
			dp[i][j] = dp[i][j-1] + 1;
			for(int k = i; k <= j; k++)
			{
				// paint [i, k] then [k+1, j]
				if(a[j] == a[k])
				{
					dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j-1]);
				}
			}
		}
	}
	cout << dp[0][n-1] << endl;
}
