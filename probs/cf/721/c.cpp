#include <bits/stdc++.h>

using namespace std;

const int MAXN = 5005;

int n, m, T, a[MAXN], b[MAXN], w[MAXN], p[MAXN][MAXN], dp[MAXN][MAXN];
int main()
{
	cin >> n >> m >> T;
	for(int i = 0; i < m; i++)
	{
		cin >> a[i] >> b[i] >> w[i];
	}
	for(int i = 0; i < MAXN; i++) for(int j = 0; j < MAXN; j++) dp[i][j] = T+1;
	dp[1][1] = 0;
	int ans = 1;
	for(int i = 2; i <= n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			if(dp[a[j]][i-1] + w[j] < dp[b[j]][i])
			{
				dp[b[j]][i] = dp[a[j]][i-1] + w[j];
				p[i][b[j]] = a[j]; // best way to get to b[j] in i steps.
			}
		}
		if(dp[n][i] <= T) ans = i;
	}
	cout << ans << endl;
	vector<int> v;
	int q = n;
	for(int i = 0; i < ans; i++)
	{
		v.push_back(q);
		q = p[ans-i][q];
	}
	reverse(v.begin(), v.end());
	for(int x : v) cout << x << " ";
	cout << endl;
}