#include <bits/stdc++.h>

using namespace std;

const int MAXN = 505;
using ll = long long;

int n, m, q;
ll g[MAXN][MAXN];
int main()
{
	cin >> n >> m >> q;
	const ll INF = 1e15+7;
	for(int i = 0; i <= n; i++)
		for(int j = 0; j <= n; j++)
			g[i][j] = INF;
	for(int i = 0; i <= n; i++) g[i][i] = 0;
	for(int i = 0; i < m; i++)
	{
		int u, v;
		ll w;
		cin >> u >> v >> w;
		g[u][v] = g[v][u] = min(g[u][v], w);
	}
	for(int k = 1; k <= n; k++)
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= n; j++)
			 	if(g[i][k] != INF && g[k][j] != INF)
					g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
	while(q--)
	{
		int a, b; cin >> a >> b;
		if(g[a][b] >= INF) cout << -1 << endl;
		else cout << g[a][b] << endl;
	}
}
