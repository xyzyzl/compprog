#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MOD 998244353

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

const int MAXN = 100005;

int n, fact[MAXN];
int C(int p, int q)
{
	int ans = fact[p];
	int den = mul(fact[q], fact[p-q]);
	return mul(ans, inv(den));
}

int main()
{
	cin >> n;
	fact[0] = 1;
	for(int i = 1; i <= n; i++)
		fact[i] = mul(fact[i-1],i);
	int ans = 0;
	for(int i = 0; i <= n/2; i++)
	{
		int ci = mul(C(2*i, i), inv(i+1));
		AD(ans, mul(ci, C(n, 2*i)));
	}
	cout << ans << endl;
}