
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define int ll

const int MOD = 1e9+7;

int mul(int a, int b, int mod=MOD)
{
	return (ll)a*b % mod;
}

int po(int a, int b, int mod=MOD)
{
	return (!b ? 1 : mul(po(mul(a,a,mod),b/2,mod), (b%2)?a:1, mod));
}


signed main()
{
	int t; cin >> t;
	while(t--)
	{
		int a, b, c; cin >> a >> b >> c;
		int d = po(b,c,MOD-1);
		cout << po(a,d) << endl;
	}
}
