#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MOD 1e9+7

// due to Benjamin Qi

namespace modOp
{
    int ad(int a, int b, int mod = MOD) { return (a+b)%mod; }
    int sub(int a, int b, int mod = MOD) { return (a-b+mod)%mod; }
    int mul(int a, int b, int mod = MOD) { return (ll)a*b%mod; }
 
    int AD(int& a, int b, int mod = MOD) { return a = ad(a,b,mod); }
    int SUB(int& a, int b, int mod = MOD) { return a = sub(a,b,mod); }
    int MUL(int& a, int b, int mod = MOD) { return a = mul(a,b,mod); }
 
    int po (int b, int p, int mod = MOD) { return !p?1:mul(po(mul(b,b,mod),p/2,mod),p&1?b:1,mod); }
    int inv (int b, int mod = MOD) { return po(b,mod-2,mod); }
 
    int invGeneral(int a, int b) { // 0 < a < b, gcd(a,b) = 1
        if (a == 0) return b == 1 ? 0 : -1;
        int x = invGeneral(b%a,a);
        return x == -1 ? -1 : ((1-(ll)b*x)/a+b)%b;
    }
}
 
using namespace modOp;

int main()
{
	int n,q; cin >> n >> q;
	vector<int> p0, p1;
	p0.resize(n);
	p1.resize(n);
	for(int i = 0; i < n; i++)
	{
		char c; cin >> c;
		if(c == '0') p0[i]++;
		else         p1[i]++;
		if(i)
		{
			p0[i]+=p0[i-1];
			p1[i]+=p1[i-1];
		}
	}
	for(int i = 0; i < q; i++)
	{
		int l,r; cin >> l >> r; --l; --r;
		int x = p1[r] - (l > 0 ? p1[l-1] : 0);
		int y = p0[r] - (l > 0 ? p0[l-1] : 0);
		cout << mul(sub(po(2, x),1), po(2, y)) << endl;
	}
}