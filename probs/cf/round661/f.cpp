// memset takes O(size) or O(lg size) time instead of O(1) time as I originally thought
// thus it would obviously TLE :(((((
#include <bits/stdc++.h>

using namespace std;

int n;
pair<int, int> sg[3005];
vector<vector<int> > R, dp;

int rc(int l, int r)
{
	if(dp[l][r] != -1) return dp[l][r];
	dp[l][r] = count(R[l].begin(), R[l].end(), r);
	if(l > r) return 0;
	int mx = ((l+1 > r) ? 0 : rc(l+1, r));
	for(int k : R[l])
	{
		if(k >= r) continue;
		mx = max(mx, rc(l, k) + ((k+1 > r) ? 0 : rc(k+1, r)));
	}
	dp[l][r] += mx;
	return dp[l][r];
}

int solve()
{
	cin >> n;
	vector<int> s;
	for(int i = 0; i < n; i++)
	{
		cin >> sg[i].first >> sg[i].second;
		s.push_back(sg[i].first);
		s.push_back(sg[i].second);
	}
	sort(s.begin(), s.end());
	unique(s.begin(), s.end());
	int y = s.size();
	for(int i = 0; i < n; i++)
	{
		sg[i].first = lower_bound(s.begin(), s.end(), sg[i].first) - s.begin();
		sg[i].second = lower_bound(s.begin(), s.end(), sg[i].second) - s.begin();
	}
	R  = vector<vector<int> >(y);
	dp = vector<vector<int> >(y, vector<int>(y, -1));
	for(int i = 0; i < n; i++)
	{
		R [sg[i].first].push_back(sg[i].second);
	}
	return rc(0, y-1);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while(t--) cout << solve() << endl;
}
