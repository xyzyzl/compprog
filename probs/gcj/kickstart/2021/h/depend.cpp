#include <bits/stdc++.h>

using namespace std;

using ll = long long;
const int MOD = 1e9 + 7;

// template for int that supports mod operations
template <int MOD, int RT>
struct mint
{
	static const int mod = MOD;
	static constexpr mint rt() { return RT; } // primitive root for FFT
	int v;
	explicit operator int() const { return v; } // explicit -> don't silently convert to int
	mint() { v = 0; }
	mint(ll _v)
	{
		v = int((-MOD < _v && _v < MOD) ? _v : _v % MOD);
		if (v < 0)
			v += MOD;
	}
	friend bool operator==(const mint &a, const mint &b)
	{
		return a.v == b.v;
	}
	friend bool operator!=(const mint &a, const mint &b)
	{
		return !(a == b);
	}
	friend bool operator<(const mint &a, const mint &b)
	{
		return a.v < b.v;
	}

	mint &operator+=(const mint &m)
	{
		if ((v += m.v) >= MOD)
			v -= MOD;
		return *this;
	}
	mint &operator-=(const mint &m)
	{
		if ((v -= m.v) < 0)
			v += MOD;
		return *this;
	}
	mint &operator*=(const mint &m)
	{
		v = int((ll)v * m.v % MOD);
		return *this;
	}
	mint &operator/=(const mint &m) { return (*this) *= inv(m); }
	friend mint pow(mint a, ll p)
	{
		mint ans = 1;
		assert(p >= 0);
		for (; p; p /= 2, a *= a)
			if (p & 1)
				ans *= a;
		return ans;
	}
	friend mint inv(const mint &a)
	{
		assert(a.v != 0);
		return pow(a, MOD - 2);
	}

	mint operator-() const { return mint(-v); }
	mint &operator++() { return *this += 1; }
	mint &operator--() { return *this -= 1; }
	friend mint operator+(mint a, const mint &b) { return a += b; }
	friend mint operator-(mint a, const mint &b) { return a -= b; }
	friend mint operator*(mint a, const mint &b) { return a *= b; }
	friend mint operator/(mint a, const mint &b) { return a /= b; }
};

using mi = mint<MOD, 5>; // 5 is primitive root for both common mods
using vmi = vector<mi>;

// multiplying by D mod MOD is equivalent to dividing by 1000000. (this is a modular inverse)
const mi D = inv(mi(1000000));

void solve()
{
	int n, q;
	cin >> n >> q;
	int k;
	cin >> k;
	vector<vector<int>> par(n, vector<int>(20));
	vector<vmi> prob_a(n, vmi(20)), prob_b(n, vmi(20));
	vector<vector<int>> adj(n);
	for (int i = 1; i < n; i++)
	{
		int a, b;
		cin >> par[i][0] >> a >> b;
		--par[i][0];
		adj[par[i][0]].push_back(i);
		adj[i].push_back(par[i][0]);
		prob_a[i][0] = a * D;
		prob_b[i][0] = b * D;
	}
	vmi p(n + 1);
	vector<int> dep(n + 1), vis(n + 1);
	p[0] = k * D;

	function<void(int)> dfs = [&](int v)
	{
		vis[v] = 1;
		dep[v] = dep[par[v][0]] + 1;
		for (int x : adj[v])
		{
			if (vis[x])
				continue;
			for (int i = 1; i < 20; i++)
			{
				par[x][i] = par[par[x][i - 1]][i - 1];
				// as stated in the editorial, we can binary lift for probabilities as well.
				prob_a[x][i] = prob_a[x][i - 1] * prob_a[par[x][i - 1]][i - 1] + prob_b[x][i - 1] * (mi(1) - prob_a[par[x][i - 1]][i - 1]);
				prob_b[x][i] = prob_a[x][i - 1] * prob_b[par[x][i - 1]][i - 1] + prob_b[x][i - 1] * (1 - prob_b[par[x][i - 1]][i - 1]);
			}
			p[x] = prob_a[x][0] * p[par[x][0]] + prob_b[x][0] * (1 - p[par[x][0]]);
			dfs(x);
		}
	};
	dfs(0); // initializes the binary jump parents, as well as the fixed probabilities of each event happening

	function<mi(int, int)> lca = [&](int u, int v)
	{
		if (dep[u] < dep[v])
			swap(u, v);
		mi ua = 1, ub = 0, va = 1, vb = 0;
		for (int i = 19; i >= 0; i--)
		{
			if (dep[u] - dep[v] >= (1 << i))
			{
				mi t1 = ua, t2 = ub;
				ua = t1 * prob_a[u][i] + t2 * (1 - prob_a[u][i]);
				ub = t1 * prob_b[u][i] + t2 * (1 - prob_b[u][i]);
				u = par[u][i];
			}
		}
		if (u == v)
		{
			ua = ua * p[v];
			return ua;
		}
		mi t1, t2;
		for (int i = 19; i >= 0; i--)
		{
			if (par[v][i] != par[u][i])
			{
				t1 = ua;
				t2 = ub;
				ua = (t1 * prob_a[u][i]) + t2 * (1 - prob_a[u][i]);
				ub = t1 * prob_b[u][i] + t2 * ((1 - prob_b[u][i]));
				t1 = va;
				t2 = vb;
				va = t1 * prob_a[v][i] + t2 * (1 - prob_a[v][i]);
				vb = t1 * prob_b[v][i] + t2 * (1 - prob_b[v][i]);
				v = par[v][i];
				u = par[u][i];
			}
		}
		t1 = ua;
		t2 = ub;
		ua = t1 * prob_a[u][0] + t2 * (1 - prob_a[u][0]);
		ub = t1 * prob_b[u][0] + t2 * (1 - prob_b[u][0]);
		t1 = va;
		t2 = vb;
		va = t1 * prob_a[v][0] + t2 * (1 - prob_a[v][0]);
		vb = t1 * prob_b[v][0] + t2 * (1 - prob_b[v][0]);

		t1 = ua * va;
		t2 = ub * vb;
		t1 = t1 * p[par[u][0]] + t2 * (1 - p[par[u][0]]);
		return t1;
	};

	for (int i = 0; i < q; i++)
	{
		int u, v;
		cin >> u >> v;
		--u;
		--v;
		// find the LCA and return the probability that u and v both happen.
		mi x = lca(u, v);
		cout << x.v << ' ';
	}
	cout << endl;
}

int main()
{
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++)
	{
		cout << "Case #" << i << ": ";
		solve();
	}
}