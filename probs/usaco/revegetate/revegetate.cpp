#include <bits/stdc++.h>

using namespace std;

int n, m, vis[100005], col[100005];
typedef pair<int, int> pii;
#define f first
#define s second
vector<pii> adj[100005];

bool dfs(int v, int p, int a)
{
	if(vis[v])
	{
		return (a == col[v]);
	}
	vis[v] = 1;
	col[v] = a;
	bool ret = 1;
	for(pii x : adj[v])
	{
		if(x.s)
		{
			ret = (ret && dfs(x.f,v,a));
		} else
		{
			ret = (ret && dfs(x.f,v,!a));
		}
	}
	return ret;
}

int main()
{
	freopen("revegetate.in", "r", stdin);
	freopen("revegetate.out", "w", stdout);
	cin >> n >> m;
	for(int i = 0; i < m; i++)
	{
		char c;
		int a,b;
		cin >> c >> a >> b;
		--a; --b;
		adj[a].push_back(make_pair(b, c=='S'));
		adj[b].push_back(make_pair(a, c=='S'));
	}
	memset(vis, 0, sizeof vis);
	int cc = 0;
	for(int i = 0; i < n; i++)
	{
		if(vis[i]) continue;
		cc++;
		bool can = dfs(i, -1, 0);
		if(!can)
		{
			cout << 0 << endl;
			return 0;
		}
	}
	cout << 1;
	for(int i = 0; i < cc; i++) cout << 0;
	cout << endl;
}
