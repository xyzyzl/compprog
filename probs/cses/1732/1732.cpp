#include <bits/stdc++.h>

using namespace std;

using ll = long long;
const int MOD = 1e9+9;
const int B = 31;
const int MAXN = 1000005;

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

string s;
int n, pre[MAXN], pw[MAXN];

int main()
{
	cin >> s;
	n = s.length();
	for(int i = 0; i < n; i++) s[i] -= 'a';
	// calculate hashes
	pw[0] = 1;
	for(int i = 0; i < n; i++)
	{
		pre[i+1] = ad(mul(pre[i], B), s[i]);
		if(i) pw[i] = mul(pw[i-1], B);
	}
	for(int i = 1; i < n; i++)
	{
		int a = sub(pre[i], mul(pre[0]   , pw[i]));
		int b = sub(pre[n], mul(pre[n-i] , pw[i]));
		if(a == b) cout << i << " ";
	}
	cout << endl;
}