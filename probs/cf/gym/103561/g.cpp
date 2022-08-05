#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e6 + 5;

int n;
vector<int> adj[MAXN], lf;

void dfs(int v, int p)
{
	int c = 0;
	for(int x : adj[v])
		if(x != p)
		{
			c++;
			dfs(x, v);
		}
	if(c == 0)
	{
		lf.push_back(v);
	}
}

int main()
{
	cin >> n;	
	for(int i = 1; i < n; i++)
	{
		int u, v; cin >> u >> v;
		--u; --v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(0, 0);
	long long x = lf.size();
	cout << x*(x-1)/2 << endl;
}