#include <bits/stdc++.h>

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
using namespace std;

int fact[500005];

int C(int i, int j)
{
	if(i < j) return 0;
	return mul(fact[i], inv(mul(fact[j], fact[i-j])));
}

void solve()
{
	int n; cin >> n;
	vector<int> A(n+1);
	vector<int> F(n+1);
	vector<vector<int> > FF(n+1);
	for(int i = 1; i <= n; i++)
	{
		cin >> A[i];
		F[A[i]]++;
		FF[F[A[i]]].push_back(A[i]);
	}
	for(int i = 1; i <= n; i++)
	{
		sort(FF[i].begin(), FF[i].end());
		reverse(FF[i].begin(), FF[i].end());
	}
	vector<int> preC(n+1, 1), ans(n+1);
	int tot = 1;
	for(int i = 1; i <= n; i++)
	{
		// process in the order described; everything else is a working set.
		for(int x : FF[i])
		{
			int e = mul(tot, inv(preC[x]));
			AD(ans[x], mul(e, C(F[x], i)));
			MUL(tot, inv(preC[x]));
			AD(preC[x], C(F[x], i)); // increase i
			MUL(tot, preC[x]);
		}
	}
	for(int i = 1; i <= n; i++)
	{
		cout << ans[i] << (i < n ? ' ' : '\n');
	}
}

int main()
{
	fact[0] = 1;
	for(int i = 1; i < 500005; i++)
	{
		fact[i] = mul(fact[i-1], i);
	}
	int t; cin >> t;
	while(t--)
	{
		solve();
	}
}
