#include <bits/stdc++.h>

#define EPS (1e-6)

using namespace std;

int n, k, dp[500005], sz[500005];
vector<int> adj[500005];

void dfs1(int v) { sz[v]=1; for(int x : adj[v]) { dfs1(x); sz[v] += sz[x]; } }

double lo, hi, mid;
void dfs2(int v)
{
	if(adj[v].empty())
	{
		dp[v] = 1;
		return;
	}
	int mx = 0;
	for(int x : adj[v])
	{
		dfs2(x);
		mx = max(mx, dp[x]);
	}
	bool can = ((double)mx/(double)(sz[v]-1) > mid);
	dp[v] = can ? sz[v] : mx;
}

int main()
{
	cin >> n >> k;
	for(int i = 1; i < n; i++)
	{
		int j; cin >> j;
		--j;
		adj[j].push_back(i);
	}
	lo=0, hi=1, dfs1(0);
	while(hi - lo > EPS)
	{
		mid = (lo+hi)/2.0;
		memset(dp, 0, sizeof dp); dfs2(0);
		if(dp[0] <= k) hi = mid;
		else lo = mid;
	}
	cout << setprecision(10) << fixed << hi << endl;
}