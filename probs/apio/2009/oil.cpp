#include <bits/stdc++.h>

using namespace std;

#define MAXN 1505

int m,n,k,dp[MAXN][MAXN][2],pp[MAXN][MAXN][4],pq[MAXN][MAXN],ar[MAXN][MAXN];
int main()
{
	ios_base::sync_with_stdio(0);
	cin >> m >> n >> k;
	for(int i = 0; i < m; i++) for(int j = 0; j < n; j++) cin >> ar[i][j];
	for(int i = 0; i < m; i++)
	{
		for(int j = 0; j < n; j++)
		{
			pq[i][j] = ar[i][j];
			if(i) pq[i][j] += pq[i-1][j];
			if(j) pq[i][j] += pq[i][j-1];
			if(i && j) pq[i][j] -= pq[i-1][j-1];
		}
	}
	for(int i = k-1; i < m; i++) for(int j = k-1; j < n; j++)
	{
		pp[i][j][0] = pq[i][j];
		if(i > k-1) pp[i][j][0] -= pq[i-k][j];
		if(j > k-1) pp[i][j][0] -= pq[i][j-k];
		if(i > k-1 && j > k-1) pp[i][j][0] += pq[i-k][j-k];
	}
	for(int i = m-1; i >= 0; i--)
	{
		for(int j = 0; j < n; j++)
		{
			pq[i][j] = ar[i][j];
			if(i<m-1) pq[i][j] += pq[i+1][j];
			if(j) pq[i][j] += pq[i][j-1];
			if(i<m-1 && j) pq[i][j] -= pq[i+1][j-1];
		}
	}
	for(int i = m-k; i >= 0; i--) for(int j = k-1; j < n; j++)
	{
		pp[i][j][1] = pq[i][j];
		if(i < m-k) pp[i][j][1] -= pq[i+k][j];
		if(j > k-1) pp[i][j][1] -= pq[i][j-k];
		if(i < m-k && j > k-1) pp[i][j][1] += pq[i+k][j-k];
	}
	for(int i = 0; i < m; i++)
	{
		for(int j = n-1; j >= 0; j--)
		{
			pq[i][j] = ar[i][j];
			if(i) pq[i][j] += pq[i-1][j];
			if(j<n-1) pq[i][j] += pq[i][j+1];
			if(i && j<n-1) pq[i][j] -= pq[i-1][j+1];
		}
	}
	for(int i = k-1; i < m; i++) for(int j = n-k; j >= 0; j--)
	{
		pp[i][j][2] = pq[i][j];
		if(i > k-1) pp[i][j][2] -= pq[i-k][j];
		if(j < n-k) pp[i][j][2] -= pq[i][j+k];
		if(i > k-1 && j < n-k) pp[i][j][2] += pq[i-k][j+k];
	}
	for(int i = m-1; i >= 0; i--)
	{
		for(int j = n-1; j >= 0; j--)
		{
			pq[i][j] = ar[i][j];
			if(i<m-1) pq[i][j] += pq[i+1][j];
			if(j<n-1) pq[i][j] += pq[i][j+1];
			if(i<m-1 && j<n-1) pq[i][j] -= pq[i+1][j+1];
		}
	}
	for(int i = m-k; i >= 0; i--) for(int j = n-k; j >= 0; j--)
	{
		pp[i][j][3] = pq[i][j];
		if(i < m-k) pp[i][j][3] -= pq[i+k][j];
		if(j < n-k) pp[i][j][3] -= pq[i][j+k];
		if(i < m-k && j < n-k) pp[i][j][3] += pq[i+k][j+k];
	}
	for(int i = k-1; i < m; i++)
	{
		int mx = 0;
		for(int j = 0; j < n; j++)
		{
			mx = max(mx, pp[i][j][0]);
		}
		dp[i-k+1][i][0] = mx;
	}
	for(int l = k; l < m; l++)
	{
		for(int i = 0; i < m-l; i++)
		{
			dp[i][i+l][0] = max(max(dp[i+1][i+l][0],dp[i][i+k-1][0]), max(dp[i][i+l-1][0],dp[i+l-k+1][i+l][0]));
		}
	}
	for(int i = k-1; i < n; i++)
	{
		int mx = 0;
		for(int j = 0; j < m; j++)
		{
			mx = max(mx, pp[j][i][0]);
		}
		dp[i-k+1][i][1] = mx;
	}
	for(int l = k; l < n; l++)
	{
		for(int i = 0; i < n-l; i++)
		{
			dp[i][i+l][1] = max(max(dp[i+1][i+l][1],dp[i][i+k-1][1]), max(dp[i][i+l-1][1],dp[i+l-k+1][i+l][1]));
		}
	}
	for(int i = 0; i < m; i++) for(int j = 0; j < n; j++)
	{
		if(i) pp[i][j][0] = max(pp[i][j][0], pp[i-1][j][0]);
		if(j) pp[i][j][0] = max(pp[i][j][0], pp[i][j-1][0]);
	}
	for(int i = m-1; i >= 0; i--) for(int j = 0; j < n; j++)
	{
		if(i < m-1) pp[i][j][1] = max(pp[i][j][1], pp[i+1][j][1]);
		if(j) pp[i][j][1] = max(pp[i][j][1], pp[i][j-1][1]);
	}
	for(int i = 0; i < m; i++) for(int j = n-1; j >= 0; j--)
	{
		if(i) pp[i][j][2] = max(pp[i][j][2], pp[i-1][j][2]);
		if(j < n-1) pp[i][j][2] = max(pp[i][j][2], pp[i][j+1][2]);
	}
	for(int i = m-1; i >= 0; i--) for(int j = n-1; j >= 0; j--)
	{
		if(i < m-1) pp[i][j][3] = max(pp[i][j][3], pp[i+1][j][3]);
		if(j < n-1) pp[i][j][3] = max(pp[i][j][3], pp[i][j+1][3]);
	}
	// do three rectangles not all aligned.
	int ans = 0;
	for(int i = k; i < m-k; i++)
	{
		for(int j = k; j < n-k; j++)
		{
			ans = max(ans, pp[i-1][n-1][0]+pp[i][j-1][1]+pp[i][j][3]);
			ans = max(ans, pp[i-1][j-1][0]+pp[i-1][j][2]+pp[i][n-1][1]);
			ans = max(ans, pp[i-1][j-1][0]+pp[i][j-1][1]+pp[m-1][j][2]);
			ans = max(ans, pp[m-1][j-1][0]+pp[i-1][j][2]+pp[i][j][3]);
		}
	}
	// do three rectangles all aligned.
	for(int i = 1; i < m; i++) for(int j = i+k; j < m; j++)
	{
		ans = max(ans, pp[i-1][n-1][0]+dp[i][j-1][0]+pp[j][n-1][1]);
	}
	for(int i = 1; i < n; i++) for(int j = i+k; j < n; j++)
	{
		ans = max(ans, pp[m-1][i-1][0]+dp[i][j-1][1]+pp[m-1][j][2]);
	}
	cout << ans << endl;
}