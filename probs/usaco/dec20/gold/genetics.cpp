#include <bits/stdc++.h>

using namespace std;

string S;
int n;
#define ll long long
ll dp[100005][4][4][4];
char dna[4] = {'A', 'C', 'G', 'T'};
const int MOD = 1000000007;
int main()
{
	cin >> S;
	n = S.length();
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (S[0] == '?' || S[0] == dna[j])
			{
				dp[0][i][j][j] = 1;
			}
		}
	}
	for (int i = 1; i < n; i++)
	{
		for (int nw = 0; nw < 4; nw++)
		{
			if (S[i] == '?' || S[i] == dna[nw])
			{
				for (int k0 = 0; k0 < 4; k0++)
					for (int k1 = 0; k1 < 4; k1++)
						for (int k2 = 0; k2 < 4; k2++)
						{
							if(k2 != nw) // add another character here
							{
								dp[i][k0][k1][nw] = (dp[i][k0][k1][nw] + dp[i-1][k0][k1][k2]) % MOD;
							}
							if(k0 == k2) // create a new part here
							{
								dp[i][k1][nw][nw] = (dp[i][k1][nw][nw] + dp[i-1][k0][k1][k2]) % MOD;
							}
						}
			}
		}
	}
	ll ans = 0;
	for(int i = 0; i < 4; i++) for(int j = 0; j < 4; j++)
	{
		ans = (ans + dp[n-1][j][i][j]) % MOD;
	}
	cout << ans << endl;
}