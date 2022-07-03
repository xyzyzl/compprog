#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main()
{
	int n, t; cin >> n >> t;
	vector<pair<pair<int, int>, pair<int, int> > > v(n);
	for(int i = 0; i < n; i++)
	{
		int ind, poi, cst, dea;
		cin >> ind >> poi >> cst >> dea;
		v[i] = (make_pair(make_pair(ind, poi), make_pair(cst, dea)));
	}
	sort(v.begin(), v.end());
	vector<int> dp(t+5);
	vector<int> vis(t+5);
	dp[0] = 0; // base case
	vis[0] = 1;
	for(int i = 0; i < n; i++)
	{
		vector<int> setto1;
		for(int j = v[i].second.second; j >= v[i].second.first; j--)
		{
			if(!vis[j-v[i].second.first]) continue;
			dp[j] = max(dp[j], dp[j-v[i].second.first] + v[i].first.second);
			setto1.push_back(j);
		}
		for(int x : setto1)
		{
			vis[x] = 1;
		}
	}
	int mx = 0;
	for(int i = 0; i <= t; i++)
	{
		mx = max(mx, dp[i]);
	}
	cout << mx << endl;
}