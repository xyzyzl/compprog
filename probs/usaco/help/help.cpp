#include <iostream>

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

int n, p[200005];
int main()
{
	freopen("help.in", "r", stdin);
	freopen("help.out", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		int l,r;
		cin >> l >> r;
		p[l]++;
		p[r]--;
	}
	// all l,r are distinct
	// so line begins whenever 1 is found and ends whenever -1 is found
	int cur = 0, ans = 0;
	for(int i = 0; i <= 2*n; i++)
	{
		cur += p[i];
		if(p[i]>0) 
		{
			AD(ans, po(2, n-cur));
		}
	}
	cout << ans << endl;
}
