#include <bits/stdc++.h>

#define MOD 1000000007

using namespace std;

int n, a[25][25], dp[25][2222222];
int main()
{
	cin >> n;
	for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) cin >> a[i][j];
	for(int i = 0; i < n; i++)
	{
		int pre = 0;
		for(int k = 0; k < (1 << n); k++)
		{
			if(__builtin_popcount(k) != i) continue;
			if(!i) pre = 1;
			else pre = dp[i-1][k];
			for(int j = 0; j < n; j++)
			{
				if(k & (1 << j) || !a[i][j])
				{
					continue; // invalid j
				}
				dp[i][k|(1 << j)] = (dp[i][k|(1 << j)] + pre) % MOD;
			}
		}
	}
	cout << dp[n-1][(1 << n)-1] << endl;
}
