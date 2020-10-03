#include <bits/stdc++.h>

using namespace std;

int n, m;

#define ll long long
#define MOD 1e9 + 7

// due to Benjamin Qi

int ad(int a, int b, int mod = m) { return (a + b) % mod; }
int sub(int a, int b, int mod = m) { return (a - b + mod) % mod; }
int mul(int a, int b, int mod = m) { return (ll)a * b % mod; }

int AD(int &a, int b, int mod = m) { return a = ad(a, b, mod); }
int SUB(int &a, int b, int mod = m) { return a = sub(a, b, mod); }
int MUL(int &a, int b, int mod = m) { return a = mul(a, b, mod); }

int po(int b, int p, int mod = MOD) { return !p ? 1 : mul(po(mul(b, b, mod), p / 2, mod), p & 1 ? b : 1, mod); }
int inv(int b, int mod = MOD) { return po(b, mod - 2, mod); }

int invGeneral(int a, int b)
{ // 0 < a < b, gcd(a,b) = 1
	if (a == 0)
		return b == 1 ? 0 : -1;
	int x = invGeneral(b % a, a);
	return x == -1 ? -1 : ((1 - (ll)b * x) / a + b) % b;
}

vector<int> adj[100005];
int dp[2][100005];

void dfs1(int v = 0, int p = -1)
{
	dp[0][v] = 1;
	for(int x : adj[v])
	{
		if(x == p) continue;
		dfs1(x, v);
		MUL(dp[0][v], dp[0][x]+1);
	}
}

void dfs2(int v = 0, int p = -1)
{
	{
		int pr = dp[1][v]+1;
		for(int i = 0; i < adj[v].size(); i++)
		{
			int x = adj[v][i];
			if(x == p) continue;
			MUL(dp[1][x], pr);
			MUL(pr, dp[0][x]+1);
		}
	}
	{
		int pr = 1;
		for(int i = adj[v].size()-1; i >= 0; i--)
		{
			int x = adj[v][i];
			if(x == p) continue;
			MUL(dp[1][x], pr);
			MUL(pr, dp[0][x]+1);
		}
	}
	for(int x : adj[v])
	{
		if(x == p) continue;
		dfs2(x, v);
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	for(int i = 1; i < n; i++)
	{
		int x, y; cin >> x >> y; --x; --y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	for(int i = 0; i < n; i++) dp[1][i] = 1;
	dp[1][0] = 0;
	dfs1(); dfs2();
	vector<int> ans(n);
	for(int i = 0; i < n; i++)
	{
		ans[i] = dp[0][i];
		AD(ans[i], mul(dp[1][i], dp[0][i]));
	}
	for(int x : ans) cout << x << endl;
}