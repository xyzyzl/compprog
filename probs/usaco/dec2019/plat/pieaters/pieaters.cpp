#include <bits/stdc++.h>

using namespace std;

const int MAXN = 305;

int n, m, dp[MAXN][MAXN], tr[MAXN][MAXN][MAXN]; // tr[x][i][j] = maximum weight in a transition from i -> j with pivot point x
int main()
{
	freopen("pieaters.in", "r", stdin);
	freopen("pieaters.out", "w", stdout);
	cin >> n >> m;
	for(int i = 0; i < m; i++)
	{
		int w, l, r; cin >> w >> l >> r;
		--l; --r;
		for(int k = l; k <= r; k++)
		{
			tr[k][l][r] = max(tr[k][l][r], w);
		}
	}
	// given each pivot point, you can try to extend things left or right
	for(int k = 0; k < n; k++)
	{
		for(int l = k; l >= 0; l--) for(int r = k; r < n; r++)
		{
			if(l > 0) tr[k][l-1][r] = max(tr[k][l][r], tr[k][l-1][r]);
			if(r < n-1) tr[k][l][r+1] = max(tr[k][l][r], tr[k][l][r+1]);
		}
	}
	for(int i = n-1; i >= 0; i--)
	{
		for(int j = i; j < n; j++)
		{
			// this is range dp: given an interval [i, j], you want to combine ranges [i, x] and [x+1, j]
			for(int x = i; x <= j; x++)
			{
				if(x < j) dp[i][j] = max(dp[i][j], dp[i][x] + dp[x+1][j]);
				if(tr[x][i][j])
				{
					dp[i][j] = max(dp[i][j], tr[x][i][j] + (x > i ? dp[i][x-1] : 0) + (x < j ? dp[x+1][j] : 0));
				}
			}
		}
	}
	cout << dp[0][n-1] << endl;
}