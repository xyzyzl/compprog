#include <bits/stdc++.h>

using namespace std;

void solve()
{
	int k; cin >> k;
	cout << 100/(gcd(100,k)) << endl;
}

int main()
{
	int t; cin >> t;
	while(t--) solve();
}
