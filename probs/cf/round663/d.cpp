#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	vector<string> v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
		for (int j = 0; j < m; j++)
		{
			v[i][j] -= '0';
		}
	}
	if (n > 3 && m > 3)
	{
		cout << -1 << endl;
		return 0;
	}
	else if (n == 1)
	{
		cout << 0 << endl;
		return 0;
	}
	else if (n == 2)
	{
		int ans = 0;
		for (int i = 0; i < m; i++)
		{
			if (v[0][i] != v[1][i] && !(i % 2))
				ans++;
			if (v[0][i] == v[1][i] && (i % 2))
				ans++;
		}
		int ans2 = 0;
		for (int i = 0; i < m; i++)
		{
			if (v[0][i] != v[1][i] && (i % 2))
				ans2++;
			if (v[0][i] == v[1][i] && !(i % 2))
				ans2++;
		}
		cout << min(ans, ans2) << endl;
		return 0;
	}
	else
	{
		vector<vector<int>> dp(m, vector<int>((1 << n)));
		vector<int> a(m);
		vector<vector<int>> pre(8);

		for (int i = 0; i < m; i++)
		{
			a[i] = v[2][i] + (v[1][i] << 1) + (v[0][i] << 2);
		}

		pre[0] = pre[7] = {2, 5};
		pre[1] = pre[6] = {3, 4};
		pre[2] = pre[5] = {0, 7};
		pre[3] = pre[4] = {1, 6};
		for (int i = 0; i < 8; i++)
		{
			dp[0][i] = __builtin_popcount(i ^ a[0]);
			// cerr << i << " " << a[0] << " " << (i^a[0]) << endl;
		}
		for (int i = 1; i < m; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				dp[i][j] = 1e9 + 7;
				// cerr << (j ^ a[i]) << " ";
				for (int ind = 0; ind < 2; ind++)
				{
					dp[i][j] = min(dp[i][j], dp[i - 1][pre[j][ind]] + __builtin_popcount(j ^ a[i]));
				}
			}
			// cerr << endl;
		}
		int ans = 1e9 + 7;
		for (int i = 0; i < 8; i++)
		{
			ans = min(ans, dp[m - 1][i]);
		}
		cout << ans << endl;
	}
}
