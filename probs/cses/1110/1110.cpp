/*input
aaaaaaaaaa
*/

#include <bits/stdc++.h>

const int A = 101;
const int MOD = 998244353;
const int MAXN = 1000005;

using namespace std;
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
}

using namespace modOp;

int H[2*MAXN], P[2*MAXN];
signed main()
{
	// freopen("bigtest.txt", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	string s;
	cin >> s;
	int n = s.length();
	s += s;
	int b = 1;
	for(int i = 0; i < s.length(); i++)
	{
		H[i+1] = ad(H[i], mul(b, s[i]));
		P[i] = b;
		MUL(b,A);
	}
	int p = 0;
	for(int i = 1; i < n; i++)
	{
		if(s[p] != s[i])
		{
			if(s[p] > s[i])
				p = i;
			continue;
		}
		int qi = mul(P[max(i,p)-i], sub(H[i+n], H[i]));
		int qp = mul(P[max(i,p)-p], sub(H[p+n], H[p]));
		if(qi == qp) continue;
		int lo = 0, hi = n;
		while(lo + 1 < hi)
		{
			int mid = (lo+hi)/2;
			int qi = mul(P[max(i,p)-i], sub(H[i+mid], H[i]));
			int qp = mul(P[max(i,p)-p], sub(H[p+mid], H[p]));
			if(qi == qp)
			{
				lo = mid;
			} else 
			{
				hi = mid;
			}
		}
		if(hi == n) continue;
		if(s[p+hi-1] > s[i+hi-1]) p=i;
	}
	cout << s.substr(p, n) << endl;
}