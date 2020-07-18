#include <bits/stdc++.h>

using namespace std;

int n, dep[200005], ans[200005];
vector<int> adj[200005];

void dfs(int v, int p)
{
	for(int x : adj[v])
	{
		if(x == p) continue;
		dfs(x, v);
		dep[v] = max(dep[v], 1 + dep[x]);
	}
}

void dfs2(int v, int p, int a)
{
	vector<int> pre, suf;
	for(int x : adj[v])
	{
		if(x == p) continue;
		pre.push_back(dep[x]);
		suf.push_back(dep[x]);
	}
	int m = pre.size();
	for(int i = 1; i < m; i++)
	{
		pre[i] = max(pre[i], pre[i-1]);
	}
	for(int i = m-2; i >= 0; i--)
	{
		suf[i] = max(suf[i], suf[i+1]);
	}
	int i = 0;
	for(int x : adj[v])
	{
		if(x == p) continue;
		int pr = (i == 0   ? INT_MIN : pre[i-1]);
		int su = (i == m-1 ? INT_MIN : suf[i+1]);
		int b = 1 + max(a, max(pr, su));
		dfs2(x, v, b);
		i++;
	}
	ans[v] = 1 + max(a, (m == 0 ? -1 : pre.back()));
}

int main()
{
	cin >> n;
	for(int i = 1; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		--a; --b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs(0, -1);
	dfs2(0, -1, -1);
	for(int i = 0; i < n; i++)
	{
		cout << ans[i] << " ";
	}
	cout << endl;
}
