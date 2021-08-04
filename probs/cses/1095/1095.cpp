#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MOD = 1e9+7;

int mul(int a, int b)
{
	return (ll)a*b % MOD;
}

int po(int a, int b)
{
	return (!b ? 1 : mul(po(mul(a,a),b/2), (b%2)?a:1));
}

int main()
{
	int t; cin >> t;
	while(t--)
	{
		int a, b; cin >> a >> b;
		cout << po(a,b) << endl;
	}
}
