#include <bits/stdc++.h>

using namespace std;

int n, m, mm[10005], vis[10005];
pair<int, int> p[105];
vector<pair<int, int> > V[10005];
vector<int> adj[10005];

bool kuhn(int v)
{
	for(auto x : adj[v])
	{
		if(vis[x]) continue;
		vis[x] = 1;
		if(!mm[x] || kuhn(mm[x]))
		{
			mm[x] = v;
			return 1;
		}
	}
	return 0;
}

int main()
{
	cin >> n >> m;
	int c=0;
	for(int i = 1; i <= n; i++)
	{
		int x; cin >> x;
		for(int j = 2; 1ll*j*j <= x; j++)
		{
			while(x%j == 0)
			{
				V[i].push_back({j, ++c});
				x /= j;
			}
		}
		if(x != 1) V[i].push_back({x, ++c});
	}
	// want to use *some* max matching algorithm such as Kuhn or Dinic
	// but first need to specify the edges.
	for(int i = 0; i < m; i++)
	{
		int u, v; cin >> u >> v;
		if(v%2) swap(u, v);
		for(auto p1 : V[u])
		{
			for(auto p2 : V[v])
			{
				if(p1.first == p2.first)
				{
					adj[p1.second].push_back(p2.second);
				}
			}
		}
	}
	int ans = 0;
	for(int i = 1; i <= c; i++)
	{
		memset(vis, 0, sizeof vis);
		if(kuhn(i)) ans++;
	}
	cout << ans << endl;
}
