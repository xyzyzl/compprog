#include <bits/stdc++.h>

using namespace std;

struct tup
{
	int t, p, i;
	tup(int t, int p, int i)
	{
		this->t = t;
		this->p = p;
		this->i = i;
	}
};

const int INF = INT_MAX/2;

vector<int> run_dp(vector<tup>& b)
{
	int m = b.size();
	// amount of time it takes to get i% with the first j activities
	vector<vector<int>> dp(101, vector<int>(m+1, INF));
	dp[0][0] = 0;
	for(int i = 1; i <= m; i++)
	{
		dp[0][i] = 0;
		for(int j = 100; j > 0; j--)
		{
			int pre = max(0, j-b[i-1].p);
			dp[j][i] = dp[j][i-1];
			dp[j][i] = min(dp[j][i], dp[pre][i-1] + b[i-1].t);
		}
	}
	vector<int> ans;
	int ret = dp[100][m]; // min amount of time to get all 100
	if(ret == INF)
	{
		return {-1};
	}
	for(int j = 100, i = m; i >= 1; i--)
	{
		if(dp[j][i] == dp[j][i-1])
		{
			continue;
		}
		ans.push_back(b[i-1].i);
		j = max(0, j-b[i-1].p);
	}
	reverse(ans.begin(), ans.end());
	ans.push_back(ret);
	return ans;
}

void solve()
{
	int n, m; cin >> n >> m;
	vector<int> a(n);
	for(int i = 0; i < n; i++) cin >> a[i];
	for(int i = n-1; i > 0; i--) a[i] -= a[i-1];
	vector<vector<tup>> b(n);
	for(int i = 0; i < m; i++)
	{
		int e, t, p; cin >> e >> t >> p;
		--e;
		b[e].push_back(tup(t, p, i+1));
	}

	vector<int> ans;
	for(int i = 0; i < n; i++)
	{
		vector<int> res_i = run_dp(b[i]);
		if((res_i.size() == 1 && res_i[0] == -1) || res_i.back() > a[i])
		{
			cout << -1 << endl;
			return;
		}
		if(i < n-1) a[i+1] += (a[i] - res_i.back());
		res_i.pop_back();
		for(int x : res_i) ans.push_back(x);
	}
	cout << ans.size() << endl;
	for(int x : ans) cout << x << " ";
	cout << endl;
}

int main()
{
	int t; cin >> t;
	while(t--) solve();
}