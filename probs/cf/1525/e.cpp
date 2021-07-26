/*input
3 5
1 4 4 3 4
1 4 1 4 2
1 4 4 4 3
*/

#include <bits/stdc++.h>

const int MOD = 998244353;
using ll = long long;

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

using namespace std;

const int MAXN = 25;
const int MAXM = 50005;

int n, m, d[MAXN][MAXM];
int ev, den;
int main()
{
	cin >> n >> m;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			cin >> d[i][j];
		}
	}
	
	den = 1;
	for(int i = 2; i <= n; i++)
		MUL(den, i);
	den = inv(den);

	for(int j = 0; j < m; j++)
	{
		vector<int> cnt(n+1);
		for(int i = 0; i < n; i++)
		{
			cnt[n - d[i][j] + 1]++; // city i becomes invalid for point j at this time
		}
		vector<int> dp(n+1);
		dp[0] = 1;
		int invalid = 0;
		for(int i = 0; i < n; i++)
		{
			invalid += cnt[i];
			AD(dp[i+1],mul(dp[i],invalid));
			invalid = max(0, invalid-1);
		}

		AD(ev, sub(1, mul(dp[n], den)));
	}
	cout << ev << endl;
}