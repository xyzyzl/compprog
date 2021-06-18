#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
 
const int MAXN = 505;
const ll INF = 1e15+7;
 
int n, m, par[MAXN], vis[MAXN];
ll C[MAXN][MAXN];
 
ll bfs(int s, int t)
{
	fill(par, par+MAXN, -1);
	fill(vis, vis+MAXN, 0);
	par[s] = -2;
	vis[s] = 1;
	queue<pair<int, ll> > q;
	q.push({s, INF});
	while(!q.empty())
	{
		int u = q.front().first;
		ll f = q.front().second;
		q.pop();
 
		for(int v = 0; v < n; v++)
		{
			if(!vis[v] && C[u][v])
			{
				vis[v] = 1;
				par[v] = u;
				ll nf = min(f, C[u][v]);
				if(v == t)
				{
					return nf;
				}
				q.push({v, nf});
			}
		}
	}
	return 0;
}
 
ll mf(int s, int t)
{
	ll f = 0, nf;
	while((nf = bfs(s, t)))
	{
		f += nf;
		int u = t;
		while(u != s)
		{
			int p = par[u];
			C[p][u] -= nf;
			C[u][p] += nf;
			u=p;
		}
	}
	return f;
}
 
int D[MAXN][MAXN];
int main()
{
	cin >> n >> m;
	for(int i = 0; i < m; i++)
	{
		int a, b; cin >> a >> b;
		--a; --b;
		D[a][b] += 1;
		D[b][a] += 1;
		C[a][b] += 1;
		C[b][a] += 1;
	}
	cout << mf(0, n-1) << endl;
	// do another bfs from 0
	bfs(0, n-1);
	vector<pair<int, int> > ans;
	for(int i = 0; i < n; i++) for(int j = 0; j < n; j++)
	{
		if(vis[i] && !vis[j] && D[i][j]) ans.push_back({i+1, j+1});
	}
	for(auto x : ans)
	{
		cout << x.first << " " << x.second << endl;
	}
}