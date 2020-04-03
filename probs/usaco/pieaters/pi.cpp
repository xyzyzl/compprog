#include <bits/stdc++.h>

using namespace std;

#define MAXN 305

int n, m;
int dp[MAXN][MAXN], best[MAXN][MAXN][MAXN];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	freopen("pieaters.in", "r", stdin);
	freopen("pieaters.out", "w", stdout);
	cin >> n >> m;
	for(int i = 0; i < m; i++)
	{
		int w,l,r;
		cin>>w>>l>>r;
		l--;
		r--;
		for(int j = l; j <= r; j++)
		{
			best[j][l][r] = max(best[j][l][r], w);
		}
	}
	// propagate the best array to find the maximum weight for all intervals
	// even those w/o a cow taking all pies
	for(int i = 0; i < n; i++)
	{
		for(int l = i; l >= 0; l--) for(int r = i; r < n; r++)	
		{
			if(l > 0) best[i][l-1][r] = max(best[i][l-1][r], best[i][l][r]);
			if(r < n-1) best[i][l][r+1] = max(best[i][l][r+1], best[i][l][r]);
		}
	}
	// make the dp state. we have to find earlier computer dp values first
	// then we add transitions involving the best array
	for(int l = n-1; l >= 0; l--) for(int r = l; r < n; r++)
	{
		// propagate through all possible subsegment pairs of [l,r] (l <= i < r)
		for(int i = l; i < r; i++)
		{
			dp[l][r] = max(dp[l][r], dp[l][i] + dp[i+1][r]);
		}
		// propagate through all possible subsegment pairs excluding a point i
		// which we will try to find the best from
		//
		// i can be at either endpoint of the segment, but we need to make sure we don't
		// add more than we want
		for(int i = l; i <= r; i++) if(best[i][l][r])
		{
			int x = best[i][l][r];
			// if(!x) continue;
			if(i > l) x += dp[l][i-1];
			if(i < r) x += dp[i+1][r];
			dp[l][r] = max(dp[l][r], x);
		}
	}
	cout << dp[0][n-1] << endl;
}
