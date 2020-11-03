#include <bits/stdc++.h>

using namespace std;

int n, ch[200005], dp[200005], as[200005];
vector<int> adj[200005];

void dfs(int v, int p)
{
	multiset<int> ms;
	for(int x : adj[v])
	{
		if(x == p) continue;
		dfs(x,v);
		ms.insert(dp[x]);
	}
	dp[v] = ch[v];
	if(ms.size() == 0)
	{
		return;
	}
	int k = *ms.rbegin();
	dp[v] += k-2;
	if(ms.size() > 1)
	{
		int dv = ch[v];
		auto it = ms.rbegin();
		int k1 = *it;
		it++;
		int k2 = *it;
		dv += k1-2 + k2-2;
		dp[v] = max(dp[v], dv);
	}
	as[v] = dp[v];
	dp[v] = max(dp[v], ch[v]);
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
	dfs(0, -1);
	int ans = 0;
	for(int i = 0; i < n; i++) ans = max(ans, as[i]);
	cout << ans << endl;
}
