#include <bits/stdc++.h>

using namespace std;

int n, ch[200005], dp[200005];
vector<int> adj[200005];

void dfs(int v, int p)
{
	for(int x : adj[v])
	{
		if(x == p) continue;
		dp[x] = dp[v]+ch[x]-2;
		dfs(x,v);
	}
}

int main()
{
	cin >> n;
	for(int i = 0; i < n-1; i++)
	{
		int a, b; cin >> a >> b;
		--a; --b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	for(int i = 0; i < n; i++)
	{
		for(int k : adj[i])
		{
			ch[i]++;
		}
	}
	int rans = 0;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++) dp[j]=0;
		dp[i] = ch[i];
		dfs(i, -1);
		int ans = 0;
		for(int j = 0; j < n; j++) if(j != i) ans = max(ans, dp[j]);
		rans = max(rans, ans);
	}
	cout << rans << endl;
}
