#include <bits/stdc++.h>
#define int long long

using namespace std;

bool solve()
{
	int n, a, b; cin >> n >> a >> b;
	if(a == 1)
	{
		// degenerate case
		return ((n-1) % b == 0);
	}
	long long k = 1;
	while(k <= n)
	{
		if(k%b == n%b) return 1;
		k *= a;
	}
	return 0;
}

signed main()
{
	int t; cin >> t; while(t--) cout << (solve() ? "YES" : "NO") << endl;
}
