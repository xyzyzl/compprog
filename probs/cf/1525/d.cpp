#include <bits/stdc++.h>

using namespace std;

const int MAXN = 5005;
const int INF = 1e9;

int n, a[MAXN], dp[MAXN][MAXN];
int main()
{
	cin >> n;
	vector<int> sta;
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
		if(a[i]) sta.push_back(i);
	}
	int m = sta.size();
	for(int i = 0; i <= n; i++) for(int j = 0; j <= m; j++) dp[i][j] = INF;
	dp[0][0] = 0;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j <= m; j++)
		{
			if(dp[i][j] == INF) continue;
			dp[i+1][j] = min(dp[i+1][j], dp[i][j]);
			if(j < m && !a[i])
			{
				dp[i+1][j+1] = min(dp[i+1][j+1], dp[i][j] + abs(i-sta[j]));
			}
		}
	}
	cout << dp[n][m] << endl;
}
