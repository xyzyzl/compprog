#include <bits/stdc++.h>

#define MAXN 300005

using namespace std;

int n, root, dp[MAXN][2], deg[MAXN];
vector<int> adj[MAXN];
void dfs(int v, int p)
{
	vector<int> resp;
	dp[v][1] = deg[v] - 1;
	for(int x : adj[v])
	{
		if(x == p) continue;
		dfs(x, v);
		dp[v][0] = max(dp[v][0], dp[x][0]);
		dp[v][1] = max(dp[v][1], dp[x][1] + deg[v] - 1);
		resp.push_back(dp[x][1]);
	}
	sort(resp.begin(), resp.end());
	reverse(resp.begin(), resp.end());
	// cout << endl;
	int ans = deg[v] + 1;
	for(int i = 0; i < 2; i++)
	{
		if(i < resp.size())
		{
			ans += resp[i];
		}
	}
	dp[v][0] = max(dp[v][0], ans);
	// cout << "---" << ans+1 << "---" << endl;
}

int main()
{
	int Q;
	cin >> Q;
	while(Q--)
	{
		root = 0; // in case
		cin >> n;
		for(int i = 0; i < n+5; i++)
		{
			deg[i] = 0;
			dp[i][0] = dp[i][1] = 0;
			adj[i].clear();
		}
		for(int i = 0; i < n-1; i++)
		{
			int a, b;
			cin >> a >> b;
			--a; --b;
			deg[a]++;
			deg[b]++;
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
		if(n <= 2)
		{
			cout << n << endl;
			continue;
		}
		for(int i = 0; i < n; i++)
		{
			if(deg[i] > 1) 
			{
				root = i;
				break;
			}
		}
		dfs(root, -1);
		cout << dp[root][0] << endl;
	}
}
