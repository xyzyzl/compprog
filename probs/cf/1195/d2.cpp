/*input
3
12 3 45
*/

#include <bits/stdc++.h>

using namespace std;
#define ll long long
const int MOD = 998244353;

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

int f(vector<int>& a, int len)
{
	int res = 0;
	int e = 1;
	for(int i = 0; i < max((int)a.size(), len); i++)
	{
		if(i < len) 
			MUL(e, 10);
		if(i < a.size())
		{
			AD(res, mul(a[i],e));
			MUL(e, 10);
		}
	}
	return res;
}

int f(int len, vector<int>& b)
{
	int res = 0;
	int e = 1;
	for(int i = 0; i < max((int)b.size(), len); i++)
	{
		if(i < b.size())
		{
			AD(res, mul(b[i],e));
			MUL(e, 10);
		}
		if(i < len)
			MUL(e,10);
	}
	return res;
}

int main()
{
	int n; cin >> n;
	vector<int> a(n);
	vector<int> L(11);
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
		int len = 0;
		int tmp = a[i];
		while(tmp) 
		{
			++len;
			tmp /= 10;
		}
		L[len]++;
	}
	int ans = 0;
	for(int i = 0; i < n; i++)
	{
		vector<int> digits;
		int tmp = a[i];
		while(tmp)
		{
			digits.push_back(tmp%10);
			tmp /= 10;
		}
		for(int len = 1; len < 11; len++)
		{
			int sum = f(digits, len);
			AD(ans, mul(sum, L[len]));
			sum = f(len, digits);
			AD(ans, mul(sum, L[len]));
		}
	}
	cout << ans << endl;
}