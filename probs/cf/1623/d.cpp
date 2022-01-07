#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MOD 1e9 + 7

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

void solve()
{
    int n, m, rb, cb, rd, cd, p; cin >> n >> m >> rb >> cb >> rd >> cd >> p;
    p = mul(p, inv(100));
    p = sub(1, p);
    int dr = -1, dc = -1;
    int u = 0, v = 1;
    pair<int, int> f = {rb,cb};
    for(int i = 0; i < 4*(n-1)*(m-1); i++)
    {
        if(f.first == 1 && dr == -1) dr = -dr;
        else if(f.first == n && dr == 1) dr = -dr;
        if(f.second == 1 && dc == -1) dc = -dc;
        else if(f.second == m && dc == 1) dc = -dc;

        f.first += dr;
        f.second += dc;
        AD(u, 1);
        if(f.first == rd || f.second == cd)
        {
            MUL(u,p);
            MUL(v,p);
        }
    }
    cout << mul(u,inv(sub(1,v))) << endl;
}

int main()
{
    int t; cin >> t;
    while(t--) solve();    
}