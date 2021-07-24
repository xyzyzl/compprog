#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int MOD = 998244353;

int n, fact[100005];

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

void solve()
{
	cin >> n;
	string s; cin >> s;
	
	vector<int> vis(n);
	int ng = 0, nz = 0;
	for(int i = 0; i < n; i++)
	{
		if(s[i] == '0') nz++;
		if(s[i] == '1' && s[i-1] == '1' && !vis[i-1])
		{
			vis[i] = 1;
			vis[i-1] = 1;
			++ng;
		}
	}

	int C = mul(fact[nz+ng], inv(mul(fact[nz], fact[ng])));
	cout << C << endl;
}

int main()
{
	int t; cin >> t;
	fact[0] = 1;
	for(int i = 1; i <= 1e5; i++)
	{
		fact[i] = mul(fact[i-1], i);
	}
	while(t--) solve();
}
