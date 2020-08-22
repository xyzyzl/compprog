#include <bits/stdc++.h>
 
#define MOD (long long)(1e9+7)
#define int long long
using namespace std;
 
int n, m, p[100005];
typedef pair<int, int> pii;
#define f first
#define s second
vector<pii> adj[100005];
 
int sz[100005];
int dfs(int v, int p)
{
	sz[v] = 1;
	for(pii x : adj[v]) 
	{
		if(x.f == p) continue;
		sz[v] += dfs(x.f, v);
	}
	return sz[v];
}
 
long long num[100005], val[100005];
signed main()
{
	int t;
	cin >> t;
	while(t--)
	{
		cin >> n;
		for(int i = 0; i < n; i++) adj[i].clear();
		for(int i = 0; i < n-1; i++)
		{
			int a,b;
			cin >> a >> b;
			--a; --b;
			adj[a].push_back({b, i});
			adj[b].push_back({a, i});
		}
		cin >> m;
		for(int i = 0; i < m; i++) cin >> p[i];
		sort(p, p+m);
		if(m >= n)
		{
			for(int i = n-1; i < m; i++) p[n-2] = (p[n-2] * p[i]) % MOD;
		} else
		{
			for(int i = m; i < n-1; i++) p[i] = 1;
		}
		sort(p, p+n-1);
		dfs(0, -1);
		for(int i = 0; i < n; i++)
		{
			for(pii x : adj[i])
			{
				int k = min(sz[i], sz[x.f]);
				num[x.s] = (k * (long long)(n-k)) % MOD;
			}
		}
		sort(num, num+n-1);
		for(int i = 0; i < n-1; i++)
		{
			val[i] = p[i];
		}
		long long ans = 0;
		for(int i = 0; i < n-1; i++)
		{
			ans += (val[i] * num[i]) % MOD;
			ans %= MOD;
		}
		cout << ans % MOD << endl;
	}
}
