#include <bits/stdc++.h>

using namespace std;

int n;
long long s, w[100005], f[100005];
vector<pair<int, int> > adj[100005];
int dfs(int v, int p)
{
	int ret = 0;
	int leaf = 1;
	for(pair<int, int> x : adj[v])
	{
		if(x.first == p) continue;
		int y = dfs(x.first, v);
		f[x.second] = y;
		ret += y;
		leaf = 0;
	}
	return leaf+ret;
}

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		cin >> n >> s;
		for(int i = 0; i < n; i++) adj[i].clear();
		for(int i = 1; i < n; i++)
		{
			int a, b;
			cin >> a >> b >> w[i];
			--a; --b;
			adj[a].push_back({b,i});
			adj[b].push_back({a,i});
		}
		dfs(0, -1);
		multiset<pair<long long, long long> > k;
		long long total=0;
		for(int i = 1; i < n; i++)
		{
			total += ((long long) w[i] * f[i]);
			k.insert(make_pair((long long)(w[i] - w[i]/2) * f[i], i));
		}
		int ans = 0;
		// greedy
		while(total > s)
		{
			long long x = k.rbegin() -> first;
			long long i = k.rbegin() -> second;
			k.erase(prev(k.end()));
			total -= x;
			w[i] /= 2;
			k.insert(make_pair((long long)(w[i] - w[i]/2) * f[i], i));
			++ans;
		}
		cout << ans << endl;
	}
}
