#include <bits/stdc++.h>

using namespace std;

int main()
{
	// freopen("e.in", "r", stdin);
	int t; cin >> t;
	while(t--)
	{
		int n, m; cin >> n >> m;
		vector<int> indeg(n), oudeg(n);
		vector<int> a(n);
		vector<int> sim(n);
		for(int i = 0; i < n; i++) cin >> a[i];
		vector<vector<int>> adj(n);
		for(int i = 0; i < m; i++)
		{
			int u, v; cin >> u >> v; --u; --v;
			indeg[v]++;
			oudeg[u]++;
			adj[u].push_back(v);
		}
		multiset<int> s;
		vector<int> res;
		for(int i = 0; i < n; i++)
		{
			if(!indeg[i]) s.insert(i);
		}
		for(int i = 0; i < n; i++)
		{
			int u = *s.begin();
			s.erase(s.begin());
			res.push_back(u);
			for(int v : adj[u]) 
			{
				indeg[v]--;
				if(!indeg[v]) s.insert(v);
			}
		}
		reverse(res.begin(), res.end());
		for(int i = 0; i < n; i++) sim[i] = a[i];
		int mx = n;
		vector<int> tmp(n);
		for(int i = 0; i < n; i++)
		{
			bool con = 0;
			for(int j = 0; j < n; j++)
			{
				if(sim[j]) con=1;
			}
			if(!con)
			{
				mx = i;
				break;
			}
			for(int j = 0; j < n; j++)
			{
				if(sim[j])
				{
					tmp[j] += sim[j]-1;
					for(auto it : adj[j]) tmp[it]++;
				}
			}
			for(int j = 0; j < n; j++)
			{
				if(tmp[j] >= 998244353)
				{
					sim[j] = tmp[j] % 998244353 + 998244353;
				} else 
				{
					sim[j] = tmp[j] % 998244353;
				}
				tmp[j] = 0;
			}
		}
		if(mx < n)
		{
			cout << mx << endl;
			continue;
		}
		vector<int> sinks;
		for(int i = 0; i < n; i++)
		{
			if(!oudeg[i]) sinks.push_back(i);
		}	
		// for each sink:
		long long ans = n;
		for(int d : sinks)
		{
			// run dp
			vector<int> dp(n);
			dp[d] = 1;
			for(int u : res)
			{
				for(int v : adj[u])
				{
					dp[u] += dp[v];
					dp[u] %= 998244353;
				}
			}
			for(int i = 0; i < n; i++) 
			{
				ans += (long long) sim[i] * dp[i];
				ans %= 998244353;
			}
		}
		cout << ans << endl;
	}
}