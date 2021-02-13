#include <bits/stdc++.h>

using ll=long long;
using namespace std;
using pii=pair<ll, int>;
using pia=pair<ll, vector<int> >;
#define f first
#define s second
const int MAXN=200005;

int n, m;
ll wt[MAXN][2][2]; 
vector<pii> adj[MAXN];

void dijk(int src)
{
	for(int i = 0; i < n; i++) for(int j = 0; j < 2; j++) for(int k = 0; k < 2; k++) wt[i][j][k] = 1e18;
	wt[src][0][0] = 0;
	set<pia> pq;
	pq.insert({0, {src, 0, 0}});
	while(!pq.empty())
	{
		auto tp = *pq.begin();
		pq.erase(pq.begin());
		for(pii gu : adj[tp.s[0]])
		{
			ll w = gu.f;
			int ind = gu.s;
			for(int j = 0; j <= !tp.s[1]; j++) for(int k = 0; k <= !tp.s[2]; k++) if(wt[tp.s[0]][tp.s[1]][tp.s[2]] + w*(1-j+k) < wt[ind][tp.s[1]|j][tp.s[2]|k])
			{
				auto a = pq.find({wt[ind][tp.s[1]|j][tp.s[2]|k], {ind, tp.s[1]|j, tp.s[2]|k}});
				if(a != pq.end()) pq.erase(a);
				wt[ind][tp.s[1]|j][tp.s[2]|k] = wt[tp.s[0]][tp.s[1]][tp.s[2]] + w*(1-j+k);
				pq.insert({wt[ind][tp.s[1]|j][tp.s[2]|k], {ind, tp.s[1]|j, tp.s[2]|k}});
			}
		}
	}
}

int main()
{
	cin >> n >> m;
	for(int i = 0; i < m; i++)
	{
		int u, v, w; cin >> u >> v >> w;
		--u; --v;
		adj[u].push_back({w, v});
		adj[v].push_back({w, u});
	}
	dijk(0);
	// whoops that was wrong if there are multiple paths from 1 -> i
	// it cannot be determined which one would have the minimum -max+min.
	// but we note that -a+b is *minimized* overall in this condition, so
	// i *think* we can modify wt to support that
	for(int i = 1; i < n; i++)
	{
		cout << wt[i][1][1] << " ";
	}
	cout << endl;
}