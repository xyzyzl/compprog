#include <bits/stdc++.h>

using namespace std;

#define ub upper_bound
#define lb lower_bound
#define ll long long

typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define f first
#define s second

int n;
ll S, w[100005], e[100005], c[100005];
vector<pii> adj[100005];

int dfs(int v, int p=-1)
{
	bool leaf = 1;
	int ret = 0;
	for(pii x : adj[v]) if(x.f != p)
	{
		ret += e[x.s] = dfs(x.f,v);
		leaf = 0;
	}
	return ret+leaf;
}

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		cin >> n >> S;
		for(int i = 0; i < n; i++) adj[i].clear();
		for(int i = 1; i < n; i++)
		{
			int a, b;
			cin >> a >> b >> w[i] >> c[i];
			--a; --b;
			adj[a].push_back({b,i});
			adj[b].push_back({a,i});
		}
		dfs(0);
		set<pll> x[2];
		x[0].clear(); x[1].clear();
		ll T = 0;
		for(int i = 1; i < n; i++)
		{
			x[c[i]-1].insert(make_pair(e[i]*(w[i]-w[i]/2), i));
			T += e[i]*w[i];
		}
		vector<ll> df[2];
		df[0].clear();
		df[1].clear();
		for(int it = 0; it < 2; it++)
		{
			ll total = 0;
			for(int i = 1; i < n; i++)
			{
				if(c[i] == it+1) total += e[i]*w[i];
			}
			df[it].push_back(total);
			while(total > 0 && !x[it].empty())
			{
				long long a = x[it].rbegin() -> f;
				long long i = x[it].rbegin() -> s;
				x[it].erase(prev(x[it].end()));
				total -= a;
				df[it].push_back(total);
				w[i] /= 2;
				x[it].insert(make_pair(e[i]*(w[i]-w[i]/2), i));
			}
		}
		/*
		for(int i = 0; i < df[0].size(); i++) cout << df[0][i] << " ";
		cout << endl;
		for(int i = 0; i < df[1].size(); i++) cout << df[1][i] << " ";
		cout << endl;
		*/
		ll ans = LLONG_MAX;
		int j = df[1].size()-1;
		for(int i = 0; i < df[0].size(); i++)
		{
			while(j > 0 && df[0][i] + df[1][j-1] <= S)
			{
				j--;
			}
			if(df[0][i] + df[1][j] <= S)
			{
				ans = min(ans, (ll)i+2*j);
			}
		}
		cout << ans << endl;
	}
}
