#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve()
{
	ll x, y, a, b;
	cin >> x >> y >> a >> b;
	if(a == b)
	{
		cout << min(x, y)/a << endl;
		return;
	}
	if(a < b) swap(a, b);
	ll lo = 0, hi = 1e9+7;
	while(lo+1 < hi)
	{
		ll mid = (lo+hi)/2;
		ll sm = ceil(1.0*(y-a*mid)/(b-a));
		ll bi = floor(1.0*(x-b*mid)/(a-b));
		if(max(sm, 0ll) <= min(bi, mid))
		{
			lo = mid;
		} else 
		{
			hi = mid;
		}
	}
	cout << lo << endl;
}

int main()
{
	int t; cin >> t;
	while(t--) solve();
}