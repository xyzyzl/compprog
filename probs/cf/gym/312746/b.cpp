#include <bits/stdc++.h>

using ll = long long;
using namespace std;

const int MOD = 1000000007;

int ad(int a, int b, int mod = MOD) { return (a + b) % mod; }
int sub(int a, int b, int mod = MOD) { return (a - b + mod) % mod; }
int mul(int a, int b, int mod = MOD) { return (ll)a * b % mod; }

int AD(int &a, int b, int mod = MOD) { return a = ad(a, b, mod); }
int SUB(int &a, int b, int mod = MOD) { return a = sub(a, b, mod); }
int MUL(int &a, int b, int mod = MOD) { return a = mul(a, b, mod); }

int po(int b, int p, int mod = MOD) { return !p ? 1 : mul(po(mul(b, b, mod), p / 2, mod), p & 1 ? b : 1, mod); }
int inv(int b, int mod = MOD) { return po(b, mod - 2, mod); }

int n, k, fact[1005];
int dp[1005][1005][2][2], f[1005], g[1005], h[1005];

inline int C(int a, int b)
{
	return mul(fact[a], inv(mul(fact[b], fact[a - b])));
}

int main()
{
	fact[0] = 1;
	for (int i = 1; i <= 1000; i++)
	{
		fact[i] = mul(i, fact[i - 1]);
	}
	cin >> n >> k;
	dp[0][0][0][0] = 1; // base case
	for (int i = 0; i < n; i++) for (int j = 0; j <= i; j++) for(int p = 0; p <= 1; p++) for(int q = 0; q <= 1; q++)
	{
		if(!dp[i][j][p][q]) continue;
		if(!p && i) AD(dp[i+1][j+1][q][0], dp[i][j][p][q]);
		AD(dp[i+1][j+1][q][1], dp[i][j][p][q]);
		AD(dp[i+1][j][q][0], dp[i][j][p][q]);
	}
	for (int j = k; j <= n; j++) g[j] = ad(dp[n][j][0][0], ad(0, ad(dp[n][j][1][0], 0)));
	for (int j = k; j <= n; j++) h[j] = mul(g[j], fact[n - j]);
	f[n] = h[n];
	for (int i = n - 1; i >= 0; i--)
	{
		int w = h[i];
		for (int j = n; j > i; j--) SUB(w, mul(C(j, i), f[j]));
		f[i] = w;
	}
	cout << f[k] << endl;
}