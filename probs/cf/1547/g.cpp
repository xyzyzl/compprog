#include <bits/stdc++.h>

using namespace std;

const int MAXN = 400005;

int n, m, vis[MAXN], ans[MAXN];
vector<int> adj[MAXN];

vector<int> cy, pa;
void dfs(int v)
{
	vis[v] = 1;
	for(int x : adj[v])
	{
		if(vis[x] == 1)
		{
			cy.push_back(x);
		}
		else if(ans[x] > -1 && vis[x] == 2)
		{
			pa.push_back(x);
		}
		else dfs(x);
	}
	vis[v] = 2;
}

void solve()
{
	cy.clear();
	pa.clear();
	cin >> n >> m;
	for(int i = 0; i < n; i++) 
	{
		ans[i] = 1;
		vis[i] = 0;
	}
	for(int i = 0; i < n; i++) adj[i].clear();
	for(int i = 0; i < m; i++)
	{
		int u, v; cin >> u >> v; --u; --v;
		adj[u].push_back(v);
	}
	dfs(0);
	for(int i = 0; i < n; i++)
	{
		if(vis[i] == 0) ans[i] = 0;
	}
	queue<int> q;
	for(int i = 0; i < n; i++) vis[i] = 0;
	for(int x : cy) 
	{
		q.push(x);
	}
	while(!q.empty())
	{
		int t = q.front();
		q.pop();
		vis[t] = 1;
		for(int x : adj[t])
		{
			if(!vis[x])
				q.push(x);
		}
	}
	for(int i = 0; i < n; i++) if(vis[i] == 1)
	{
		ans[i] = -1;
		++vis[i];
	}
	for(int x : pa) 
	{
		q.push(x);
	}
	while(!q.empty())
	{
		int t = q.front();
		q.pop();
		if(vis[t] == 2) continue;
		vis[t] = 1;
		for(int x : adj[t])
		{
			if(!vis[x])
				q.push(x);
		}
	}
	for(int i = 0; i < n; i++) if(vis[i] == 1)
	{
		ans[i] = 2;
		++vis[i];
	}
	for(int i = 0; i < n; i++) cout << ans[i] << ' ';
	cout << endl;
}

int main()
{
	int t; cin >> t;
	while(t--) solve();
}
