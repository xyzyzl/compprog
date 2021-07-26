#include <bits/stdc++.h>
#define int long long

using namespace std;


bool bip(int n, vector<vector<int> > &adj, vector<int> &vis)
{
	bool k = 1;
	vis.assign(n, -1);
	queue<int> q;
	for(int i = 0; i < n; i++)
	{
		if(vis[i] != -1) continue;
		q.push(i);
		vis[i] = 0;
		while(!q.empty())
		{
			int tp = q.front();
			q.pop();
			for(int x : adj[tp])
			{
				if(vis[x] == -1)
				{
					vis[x] = !vis[tp];
					q.push(x);
				}
				else k &= (vis[x] != vis[tp]);
			}
		}
	}
	return k;
}

void solve()
{
	int n, m; cin >> n >> m;
	vector<int> v(n), t(n);
	vector<vector<int> > adj(n+5);
	for(int i = 0; i < n; i++) cin >> v[i];
	for(int i = 0; i < n; i++) cin >> t[i];
	for(int i = 0; i < m; i++)
	{
		int a, b; cin >> a >> b; --a; --b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	// first: find sum(v), sum(t). if the parity is unequal we're fucked
	int df = 0;
	for(int i = 0; i < n; i++)
	{
		df += v[i] - t[i];
	}
	if(df % 2)
	{
		cout << "NO" << endl;
		return;
	}
	// next, we need to check bipartiteness
	// if it is bipartite, then we also need to check to see if the t-v differences for each part sum to the same value
	// because the edges must add the same value to each side here. however, otherwise it is always ok
	vector<int> vis(n, -1);
	bool bi = bip(n, adj, vis);
	if(bi)
	{
		int s1 = 0, s2 = 0;
		for(int i = 0; i < n; i++)
		{
			if(vis[i]) s1 += (t[i] - v[i]);
			else s2 += (t[i] - v[i]);
		}
		if(s1 == s2) cout << "YES" << endl;
		else cout << "NO" << endl;
	} else 
	{
		cout << "YES" << endl;
	}
}

signed main() { int t; cin >> t; while(t--) solve(); }