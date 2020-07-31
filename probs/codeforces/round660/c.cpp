#include <bits/stdc++.h>

using namespace std;

int n, m, p[100005], f[100005], h[100005], a[100005];
vector<int> adj[100005];
int dfs(int v, int par)
{
	int ret = p[v];
	for(int x : adj[v])
	{
		if(x==par) continue;
		ret += dfs(x, v);
	}
	return f[v] = ret;
}

bool dfs2(int v, int par)
{
	int sm = 0;
	for(int x : adj[v])
	{
		if(x==par) continue;
		if(!dfs2(x, v)) return 0;
		sm += a[x];
	}
	return (a[v] >= sm);
}

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		cin >> n >> m;
		for(int i = 0; i < n; i++) adj[i].clear();
		for(int i = 0; i < n; i++) cin >> p[i];
		for(int i = 0; i < n; i++) cin >> h[i];
		for(int i = 1; i < n; i++)
		{
			int a, b;
			cin >> a >> b;
			--a; --b;
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
		dfs(0, -1);
		for(int i = 0; i < n; i++)
		{
			if((f[i] - h[i]) % 2)
			{
				goto here;
			}
			a[i] = (f[i] + h[i])/2;
			if(a[i] > f[i] || a[i] < 0) goto here;
		}
		if(!dfs2(0, -1)) goto here;
		cout << "YES" << endl;
		continue;
here:
		cout << "NO" << endl;
	}
}
