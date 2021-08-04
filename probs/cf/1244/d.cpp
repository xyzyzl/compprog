#include <bits/stdc++.h>

using namespace std;

#define int long long
const int MAXN = 100005;

int n, deg[MAXN];
long long c[4][MAXN];
vector<int> adj[MAXN];

long long co = 0;
// it's a path
void dfs(int v, int u, int fco, int sco, int tco, vector<int> &col)
{
	for(int k : adj[v]) if(k != u)
	{
		co += c[tco][k];
		col[k] = tco;
		dfs(k, v, sco, tco, fco, col);
	}
}

signed main()
{
	cin >> n;
	for(int i = 1; i <= 3; i++) for(int j = 0; j < n; j++) cin >> c[i][j];
	for(int i = 1; i < n; i++)
	{
		int u, v; cin >> u >> v;
		--u; --v;
		adj[u].push_back(v);
		adj[v].push_back(u);
		++deg[u];
		++deg[v];
	}
	for(int i = 0; i < n; i++) if(deg[i] > 2)
	{
		cout << -1 << endl;
		return 0;
	}
	int u = 0;
	int v = adj[0][0];
	for(int i = 0; i < n; i++) if(deg[i] == 1)
	{
		u = i;
		v = adj[i][0];
		break;
	}
	long long ans = LLONG_MAX;
	vector<int> fcol(n);
	for(int i = 1; i <= 3; i++) for(int j = 1; j <= 3; j++)
	{
		if(i==j) continue;
		vector<int> col(n);
		co = (c[i][u] + c[j][v]);
		col[u] = i;
		cerr << i << " " << j << " " << co << endl;
		col[v] = j;

		// check this color combo for (u, v) and traverse
		dfs(v, u, i, j, 6-i-j, col);
		if(ans > co)
		{
			ans = co;
			fcol = col;
		}
	}
	cout << ans << endl;
	for(int x : fcol) cout << x << " ";
	cout << endl;
}
