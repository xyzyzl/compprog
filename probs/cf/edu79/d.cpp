#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MOD 998244353

// due to benjamin qi

namespace modop
{
    int ad(int a, int b, int mod = MOD) { return (a+b)%mod; }
    int sub(int a, int b, int mod = MOD) { return (a-b+mod)%mod; }
    int mul(int a, int b, int mod = MOD) { return (ll)a*b%mod; }
 
    int AD(int& a, int b, int mod = MOD) { return a = ad(a,b,mod); }
    int SUB(int& a, int b, int mod = MOD) { return a = sub(a,b,mod); }
    int MUL(int& a, int b, int mod = MOD) { return a = mul(a,b,mod); }
 
    int po (int b, int p, int mod = MOD) { return !p?1:mul(po(mul(b,b,mod),p/2,mod),p&1?b:1,mod); }
    int inv (int b, int mod = MOD) { return po(b,mod-2,mod); }
 
    int invgeneral(int a, int b) { // 0 < a < b, gcd(a,b) = 1
        if (a == 0) return b == 1 ? 0 : -1;
        int x = invgeneral(b%a,a);
        return x == -1 ? -1 : ((1-(ll)b*x)/a+b)%b;
    }
}
 
using namespace modop;

int main()
{
	int n;
	cin >> n;
	vector<int> freq(1000005);
	vector<vector<int> > a(n);
	vector<int> k(n);
	for(int i = 0; i < n; i++)
	{
		cin >> k[i];
		for(int j = 0; j < k[i]; j++)
		{
			int b;
			cin >> b;
			a[i].push_back(b);
			freq[b]++;
		}
	}
	int ans = 0;
	for(int i = 0; i < n; i++)
	{
		int sm = 0;
		for(int j = 0; j < k[i]; j++)
		{
			AD(sm, freq[a[i][j]]);
		}
		MUL(sm, inv(mul(k[i], mul(n, n))));
		AD(ans, sm);
	}
	cout << ans << endl;
}
