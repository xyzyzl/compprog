#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define int ll

const int MAXN = 1005;

// due to Benjamin Qi
const int MOD = 1e9+7;
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

int n;
int dp[MAXN][MAXN][2];
signed main()
{
	cin >> n;
	dp[0][0][0] = dp[1][0][0] = 1;
	for(int i = 2; i <= n; i++) for(int j = 0; j < i; j++)
	{
		dp[i][j][0] = ad(mul(max(0ll,i-2-j),(dp[i-1][j][0])), mul(max(0ll,i-1-j),(dp[i-1][j][1]))); // do nothing
		if(j) dp[i][j][1] = ad(ad(mul(2,dp[i-1][j-1][0]), dp[i-1][j-1][1]), dp[i-1][j][1]); // add one
		if(j < i-1) AD(dp[i][j][0], ad((j+1)*dp[i-1][j+1][0], j*dp[i-1][j+1][1])); // delete one
		// cerr << i << " " << j << " " << dp[i][j][0] << " " << dp[i][j][1] << endl;
	}
	cout << dp[n][0][0] << endl;
}
