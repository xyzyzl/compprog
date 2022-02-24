#include <bits/stdc++.h>

using namespace std;

using ll = long long;
const int MOD = 1e9+7;

// due to Benjamin Qi

namespace modOp
{
	int ad(int a, int b, int mod = MOD) { return (a + b) % mod; }
	int sub(int a, int b, int mod = MOD) { return (a - b + mod) % mod; }
	int mul(int a, int b, int mod = MOD) { return (ll)a * b % mod; }

	int AD(int &a, int b, int mod = MOD) { return a = ad(a, b, mod); }
	int SUB(int &a, int b, int mod = MOD) { return a = sub(a, b, mod); }
	int MUL(int &a, int b, int mod = MOD) { return a = mul(a, b, mod); }

	int po(int b, int p, int mod = MOD) { return !p ? 1 : mul(po(mul(b, b, mod), p / 2, mod), p & 1 ? b : 1, mod); }
	int inv(int b, int mod = MOD) { return po(b, mod - 2, mod); }

	int invGeneral(int a, int b)
	{ // 0 < a < b, gcd(a,b) = 1
		if (a == 0)
			return b == 1 ? 0 : -1;
		int x = invGeneral(b % a, a);
		return x == -1 ? -1 : ((1 - (ll)b * x) / a + b) % b;
	}
} // namespace modOp

using namespace modOp;

const int D = inv(1000000);

void solve()
{
	int n, q; cin >> n >> q;
	int k; cin >> k;
	vector<vector<int>> par(n, vector<int>(20)), pa(n, vector<int>(20)), pb(n, vector<int>(20));
	vector<vector<int>> adj(n);
	for(int i = 1; i < n; i++)
	{
		int a,b;
		cin >> par[i][0] >> a >> b;
		--par[i][0];
		adj[par[i][0]].push_back(i);
		adj[i].push_back(par[i][0]);
		pa[i][0] = (mul(a, D));
		pb[i][0] = (mul(b, D));
	}
	vector<int> p(n+1), dep(n+1), vis(n+1);
	p[0] = mul(k, D);

	function<void(int)> dfs = [&](int v)
	{
		vis[v] = 1;
		dep[v] = dep[par[v][0]]+1;
		for(int x : adj[v])
		{
			if(vis[x]) continue;
			for(int i = 1; i < 20; i++)
			{
				par[x][i] = par[par[x][i-1]][i-1];
				pa[x][i] = ad(mul(pa[x][i-1], pa[par[x][i-1]][i-1]), mul(pb[x][i-1], sub(1,pa[par[x][i-1]][i-1])));
				pb[x][i] = ad(mul(pa[x][i-1], pb[par[x][i-1]][i-1]), mul(pb[x][i-1], sub(1,pb[par[x][i-1]][i-1])));
			}
			p[x] = ad(mul(pa[x][0], p[par[x][0]]), mul(pb[x][0], sub(1, p[par[x][0]])));
			dfs(x);
		}
	};
	dfs(0); // initializes the binary jump parents, as well as the fixed probabilities of each node

	function<int(int,int)> lca = [&](int u, int v)
	{
		if(dep[u] < dep[v]) swap(u,v);
		int ua=1, ub=0, va=1, vb=0;
		for(int i = 19; i >= 0; i--)
		{
			if(dep[u] - dep[v] >= (1 << i))
			{
				int t1 = ua, t2 = ub;
				ua = ad(mul(t1,pa[u][i]) , mul(t2,(sub(1,pa[u][i]))));
				ub = ad(mul(t1,pb[u][i]) , mul(t2,(sub(1,pb[u][i]))));
				u = par[u][i];
			}
		}
		if(u == v)
		{
			MUL(ua, p[v]);
			return ua;
		}
		int t1, t2;
		for(int i = 19; i >= 0; i--)
		{
			if(par[v][i] != par[u][i])
			{
				t1 = ua; t2 = ub;
				ua = ad(mul(t1,pa[u][i]) , mul(t2,(sub(1,pa[u][i]))));
				ub = ad(mul(t1,pb[u][i]) , mul(t2,(sub(1,pb[u][i]))));
				t1 = va; t2 = vb;
				va = ad(mul(t1,pa[v][i]) , mul(t2,(sub(1,pa[v][i]))));
				vb = ad(mul(t1,pb[v][i]) , mul(t2,(sub(1,pb[v][i]))));
				v = par[v][i];
				u = par[u][i];
			}
		}
		t1 = ua; t2 = ub;
		ua = ad(mul(t1,pa[u][0]) , mul(t2,(sub(1,pa[u][0]))));
		ub = ad(mul(t1,pb[u][0]) , mul(t2,(sub(1,pb[u][0]))));
		t1 = va; t2 = vb;
		va = ad(mul(t1,pa[v][0]) , mul(t2,(sub(1,pa[v][0]))));
		vb = ad(mul(t1,pb[v][0]) , mul(t2,(sub(1,pb[v][0]))));

		t1 = mul(ua,va);
		t2 = mul(ub,vb);
		t1 = ad(mul(t1, p[par[u][0]]), mul(t2, sub(1,p[par[u][0]])));
		return t1;
	};

	for(int i = 0; i < q; i++)
	{
		int u, v; cin >> u >> v;
		--u; --v;
		int x = lca(u,v);
		cout << x << ' ';
	}
	cout << endl;
}

int main()
{
	int t; cin >> t;
	for(int i = 1; i <= t; i++)
	{
		cout << "Case #" << i << ": ";
		solve();
	}
}