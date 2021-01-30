#include <bits/stdc++.h>

using namespace std;

int n, m, q, dp[25][60000];
using pii=pair<int, int>;
using qii=pair<pii, pii>;
#define f first
#define s second
#define mp make_pair
#define pb push_back
vector<pii> adj[25];
qii qs[15];
int main()
{
	cin >> n >> m >> q;
	for(int i = 0; i < m; i++)
	{
		int u, v, c; cin >> u >> v >> c;
		--u; --v;
		adj[u].pb(mp(c, v));
	}
	memset(dp, -1, sizeof dp);
	int INF = dp[0][0];
	dp[0][0] = 0;
	for(int i = 0; i < q; i++)
	{
		cin >> qs[i].f.f >> qs[i].f.s >> qs[i].s.f >> qs[i].s.s;
		--qs[i].f.f; --qs[i].f.s;
	}
	vector<int> e3(q+1);
	for(int i = 0; i <= q; i++) e3[i] = pow(3, i);
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < e3[q]; j++)
		{
			if(dp[i][j] < 0) continue;
			for(int k = 0; k < q; k++)
			{
				int cur = (j / e3[k])%3;
				if(cur == 0 && i == qs[k].f.f)
				{
					dp[i][j+e3[k]] = qs[k].s.f;
				}
				for(pii x : adj[i]) if(x.s == qs[k].f.s || x.s == qs[k].f.f)
				{
					if(cur == 1 && x.s == qs[k].f.s) 
					{
						// cerr << i << " " << j << " " << dp[i][j] << " " << x.s << endl;
						if(dp[i][j] + x.f <= qs[k].s.s) dp[x.s][j+e3[k]] = max(dp[x.s][j+e3[k]], dp[i][j] + x.f);
					}
					if(cur == 0 && x.s == qs[k].f.f)
					{
						// cerr << i << " " << j << " " << dp[i][j] << " " << x.s << endl;
						dp[x.s][j+e3[k]] = max(dp[x.s][j+e3[k]], max(dp[i][j]+x.f, qs[k].s.f));
						cerr << dp[x.s][j+e3[k]] << endl;
					}
				}
			}
		}
	}
	int ans = 0;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < e3[q]; j++)
		{
			if(dp[i][j] >= 0)
			{
				// cerr << j << endl;
				int n2 = 0;
				for(int k = 0; k < q; k++)
				{
					if((j/e3[k])%3 == 2) n2++;
				}
				ans = max(ans, n2);
			}
		}
	}
	cout << ans << endl;
}
