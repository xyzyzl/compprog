#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
	int n;
	cin >> n;
	vector<ll> a(n);
	for(int i = 0; i < n; i++)
		cin >> a[i];
	ll sm = 0;
	for(int i = 0; i < n; i++) sm += a[i];
	
	ll ans = 1e18;
	for(int msk = 0; msk < (1 << n); msk++)
	{
		ll sm2 = 0;
		for(int i = 0; i < n; i++)
			if((1 << i) & msk)
			{
				sm2+=a[i];
			}
		ans = min(ans, abs(sm2-(sm-sm2)));
	}
	cout << ans << endl;
}