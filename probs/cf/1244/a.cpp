#include <bits/stdc++.h>

using namespace std;

void solve()
{
	double a, b, c, d, k; cin >> a >> b >> c >> d >> k;
	if((int)(ceil(a/c)+ceil(b/d)) > k)
	{
		cout << -1 << endl;
		return;
	}
	cout << (int)(ceil(a/c)) << " " << (int)(ceil(b/d)) << endl;
}

int main()
{
	int t; cin >> t;
	while(t--) solve();
}
