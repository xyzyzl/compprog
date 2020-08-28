#include <bits/stdc++.h>

#define int long long
using namespace std;

int n,k,a[200005],dep[200005],sub[200005];
vector<int> adj[200005];

void dfs(int v, int p)
{
	sub[v] = 1;
	for(int x : adj[v])
	{
		if(x == p) continue;
		dep[x] = dep[v]+1;
		dfs(x,v);
		sub[v] += sub[x];
	}
}

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> k;
	for(int i = 0; i < n-1; i++)
	{
		int a,b;
		cin >> a >> b;
		--a; --b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs(0, -1);
	for(int i = 0; i < n; i++)
	{
		a[i] = dep[i]-sub[i]+1;
	}
	sort(a,a+n);
	reverse(a,a+n);
	int ans = 0;
	for(int i = 0; i < k; i++)
	{
		ans += a[i];
	}
	cout << ans << endl;
}
