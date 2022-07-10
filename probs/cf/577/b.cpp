#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e6+5;
const int MAXM = 1e3+5;

int n, m;
int a[MAXN];
int psum[MAXN];
int freq[MAXM];

int dp[MAXM][MAXM];
int main()
{
	cin >> n >> m;
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
		a[i] %= m; // we don't really care about anything else
		if(a[i] == 0) a[i] = m;
	}
	if(n > m)
	{
		psum[0] = a[0];
		for(int i = 1; i < n; i++) psum[i] = (psum[i-1] + a[i]) % m;
		for(int i = 0; i < n; i++)
		{
			freq[psum[i]]++;
		}
		for(int i = 0; i < m; i++)
		{
			if(freq[i] >= 2)
			{
				cout << "YES" << endl;
				return 0;
			}
		}
		cout << "NO" << endl;
	} else 
	{
		// dp[i][j] = with first i numbers, can we reach a residue of j. this is OK because n > m
		dp[0][0] = 1;
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j <= m; j++)
			{
				int x = (j+a[i])%m;
				if(x == 0) x = m;
				dp[i+1][x] |= dp[i][j];
				dp[i+1][j] |= dp[i][j];
			}
		}
		cout << (dp[n][m] ? "YES" : "NO") << endl;
	}
}