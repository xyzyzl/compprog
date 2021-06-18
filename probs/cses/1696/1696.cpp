#include <bits/stdc++.h>

using namespace std;

const int MAXN = 505;

int n, m, k, N;
vector<int> adj[MAXN*2], match, vis;

bool kuhn(int v)
{
	if(vis[v]) return 0;
	vis[v]=1;
	for(int x : adj[v])
	{
		if(match[x] == -1 || kuhn(match[x]))
		{
			match[x] = v;
			return 1;
		}
	}
	return 0;
}

int main()
{
	cin >> n >> m >> k;
	for(int i = 0; i < k; i++)
	{
		int a, b; cin >> a >> b;
		--a; --b;
		adj[a].push_back(b+n);
		adj[b+n].push_back(a);
	}
	N=n+m;
	match.assign(m, -1);
	for(int i = 0; i < N; i++)
	{
		vis.assign(N, 0);
		kuhn(i);
	}
	int ans = 0;
	for(int i = 0; i < m; i++)
	{
		if(match[i] != -1) ans++;
	}
	cout << ans << endl;
	for(int i = 0; i < m; i++)
	{
		if(match[i] != -1)
		{
			cout << i+1 << " " << match[i]+1-n << endl;
		}
	}
}