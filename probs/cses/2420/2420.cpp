#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
#define int ll
 
const int A = 101;
const int MOD = 998244353;
 
const int MAXN = 200005;
 
int n, m;
 
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
 
#define bitinc(x) (x & -x)
 
struct BIT
{
	int n; vector<int> bit;
	BIT()
	{
	}
	BIT(int n)
	{
		this->n=n;
		bit.resize(2*n);
	}
 
	int sum(int ind)
	{
		int sm = 0;
		while(ind > 0)
		{
			sm += bit[ind];
			sm %= MOD;
			ind -= bitinc(ind);
		}
		return sm;
	}
 
	void upd(int ind, int val)
	{
		while(ind <= n)
		{
			bit[ind] += val;
			bit[ind] %= MOD;
			ind += bitinc(ind);
		}
	}
 
	int sum(int i1, int i2)
	{
		return sum(i2)-sum(i1-1);
	}
} bit, rbit;
 
int apo[MAXN], iapo[MAXN];
signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cin >> n >> m;
	apo[0] = iapo[0] = 1;
	int iA = inv(A);
	for(int i = 1; i <= n; i++)
	{
		apo[i] = mul(apo[i-1], A);
		iapo[i] = mul(iapo[i-1], iA);
	}
	bit = BIT(n);
	rbit = BIT(n);
	string s; cin >> s;
	// perform hashes and update bit and rbit accordingly
	// if it's a palindrome, scaling the hashes bit and rbit will lead to an equal sum
	// polynomial hash will suffice here
	int h = 0, p = 1;
	for(int i = 0; i < n; i++)
	{
		int k = s[i] - 'a';
		h = mul(k,p);	
		bit.upd(i+1, h);
		MUL(p,A);
	}
	int rh = 0;
	p = 1;
	for(int i = n-1; i >= 0; i--)
	{
		int k = s[i] - 'a';
		rh = mul(k,p);
		rbit.upd(i+1, rh);
		MUL(p,A);
	}
 
	while(m--)
	{
		int ty; cin >> ty;
		if(ty == 1)
		{
			// update
			int x; char v; cin >> x >> v;
			v -= 'a';
			--x;
			char u = s[x];
			u -= 'a';
			bit.upd(x+1, MOD-mul(u,apo[x]));
			rbit.upd(x+1, MOD-mul(u,apo[n-x-1]));
			bit.upd(x+1, mul(v,apo[x]));
			rbit.upd(x+1, mul(v,apo[n-x-1]));
		} else 
		{
			// check
			int a, b; cin >> a >> b;
			int s1 = sub(bit.sum(b),bit.sum(a-1));
			s1 = (s1+MOD)%MOD;
			int k1 = mul(s1, iapo[a-1]);
			int s2 = sub(rbit.sum(b),rbit.sum(a-1));
			s2 = (s2+MOD)%MOD;
			int k2 = mul(s2, iapo[n-b]);
			cout << (k1==k2 ? "YES" : "NO") << endl;
		}
	}
}
