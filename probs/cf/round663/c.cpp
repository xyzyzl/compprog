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

int n;
long long fact[1000005];

int gen()
{
	fact[0] = 1;
	for(int i = 1; i <= n; i++)
	{
		fact[i] = mul(fact[i-1], i);
	}
	return fact[n];
}
	
int main()
{
	cin >> n;
	if(n == 2)
	{
		cout << 1 << endl;
		return 0;
	}
	gen();
	long long ret = sub(fact[n], po(2, n-1));
	cout << ret << endl;
}

