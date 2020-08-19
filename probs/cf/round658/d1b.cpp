#include <bits/stdc++.h>
#define MAXN 2005
using namespace std;

int n, p[2*MAXN], dp[2*MAXN][2*MAXN];
void solve()
{
	cin >> n;
	for(int i = 0; i < 2*n; i++)
		cin >> p[i];
	int mx = p[0], ct = 0;
	vector<int> v;
	for(int i = 0; i < 2*n; i++)
	{
		if(mx < p[i])
		{
			mx = p[i];
			v.push_back(ct);
			ct = 0;
		}
		ct++;
	}
	v.push_back(ct);
	v.push_back(0);
	sort(v.begin(), v.end());
	int m = v.size();
	for(int i = 0; i < m; i++)
		dp[i][0] = 1;
	for(int i = 1; i <= 2*n; i++)
	{
		dp[0][i] = 0;
	}
	for(int i = 1; i < m; i++) for(int j = 1; j <= 2*n; j++)
	{
		dp[i][j] = dp[i-1][j];
		if(j >= v[i-1])
		{
			dp[i][j] |= dp[i-1][j-v[i-1]];
		}
	}
	cout << (dp[m-1][n] ? "YES" : "NO") << endl;
}

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		solve();
	}
}
