#include <bits/stdc++.h>

using namespace std;
using ll=long long;

const int MAXN = 1005;
const int MAXA = 100005;
const int MOD = 998244353;

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

int n, k, a[MAXN], p[MAXA];
int F(int x)
{
	// the number of subsequences with beauty >= x for each x
	vector<vector<int> > dp(k+1, vector<int>(n+1, 0));
	vector<vector<int> > ps(k+1, vector<int>(n+1, 0));
	vector<int> pred(n+1);
	pred[0] = 0;
	for(int i = 1; i <= n; i++)
	{
		pred[i] = pred[i-1];
		while(a[i-1] - a[pred[i]] >= x) pred[i]++;
	}
	dp[0][0] = 1;
	for(int i = 0; i < k; i++)
	{
		ps[i][0] = dp[i][0];
		for(int j = 1; j <= n; j++)
		{
			ps[i][j] = ad(ps[i][j-1],dp[i][j]);
		}
		for(int j = 1; j <= n; j++)
		{
			dp[i+1][j] = ps[i][pred[j]];
		}
	}
	int ret = 0;
	for(int j = 1; j <= n; j++) AD(ret, dp[k][j]);
	return ret;
}

int main()
{
	cin >> n >> k;
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	sort(a, a+n);
	// need to find the number of subsequences with beauty x for each x
	int ans = 0;
	for(int i = 1; i*(k-1) <= a[n-1]+5; i++)
	{
		AD(ans, F(i));
	}
	cout << ans << endl;
}