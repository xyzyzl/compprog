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
	for(int i = n-1; i >= 0; i--)
	{
		for(int j = i+1; j < n; j++)
		{
			int w = 0, x = 0;
			if(a[i] == a[j]) w = 1+dp[i+1][j-1];
			for(int k = i+1; k < j; k++)
			{
				x = max(x, dp[i][k] + dp[k][j]);
			}
			dp[i][j] = max(w, x);
		}
	}
	cout << n-dp[0][n-1] << endl;
}