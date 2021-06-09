#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
 
const int MAXN = 505;
const ll INF = 1e15+7;
 
int n, m, par[MAXN];
ll C[MAXN][MAXN];
 
ll bfs(int s, int t)
{
	fill(par, par+MAXN, -1);
	par[s] = -2;
	queue<pair<int, ll> > q;
	q.push({s, INF});
	while(!q.empty())
	{
		int u = q.front().first;
		ll f = q.front().second;
		q.pop();
 
		for(int v = 0; v < n; v++)
		{
			if(par[v] == -1 && C[u][v])
			{
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
 
int main()
{
	cin >> n >> m;
	for(int i = 0; i < m; i++)
	{
		int a, b, c; cin >> a >> b >> c;
		--a; --b;
		C[a][b] += c;
	}
	cout << mf(0, n-1) << endl;
}
