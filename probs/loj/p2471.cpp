#include <bits/stdc++.h>

#define int long long
using namespace std;

int n, m, k, A[11][11], B[11][11], dp[1100000][11], v[1100000][11];

int rec(int msk, int ind)
{
	if(v[msk][ind])
	{
		return dp[msk][ind];
	}
	v[msk][ind] = 1;
	if(msk==(1<<n)-1) return 0; // everything on the top is enabled
	int c0 = 0, c1 = 0;
	if(!ind) // feifei
	{
		dp[msk][ind] = -INT_MAX;
		for(int i = 1; i <= m+n; i++)
		{
			int j = m+n-i+1;
			if(msk & (1 << (j-1))) c1++; // move to the left
			else
			{
				// move down
				c0++;
				if(j < m+n && ((1 << j) & msk))
				{
					// wants to maximize feifei-niuniu
					// change the player each time
					dp[msk][ind] = max(dp[msk][ind], rec(msk ^ (3 << (j-1)), !ind) + A[n-c1+1][c0]); // add j-1, remove j
				}
			}
		}
	} else // niuniu
	{
		dp[msk][ind] = INT_MAX;
		for(int i = 1; i <= m+n; i++)
		{
			int j = m+n-i+1;
			if(msk & (1 << (j-1))) c1++;
			else
			{
				c0++;
				if(j < m+n && ((1 << j) & msk))
				{
					// wants to minimize feifei-niuniu
					dp[msk][ind] = min(dp[msk][ind], rec(msk ^ (3 << (j-1)), !ind) - B[n-c1+1][c0]);
				}
			}
		}
	}
	return dp[msk][ind];
}

signed main()
{
	cin >> n >> m;
	for(int i = 1; i <= n; i++) for(int j = 1; j <= m; j++) cin >> A[i][j];
	for(int i = 1; i <= n; i++) for(int j = 1; j <= m; j++) cin >> B[i][j];
	// the actual end node is n 1's + m 0's
	cout << rec((((1 << n)-1) << m), 0) << endl;
}