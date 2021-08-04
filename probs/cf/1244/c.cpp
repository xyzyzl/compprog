#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve()
{
	ll n, p, w, d; cin >> n >> p >> w >> d;
	for(int i = 0; i < w; i++)
	{
		ll j = d*i;
		ll k = p-j;
		if(k < 0) continue;
		if(k%w) continue;
		if(k/w + i > n) continue;
		cout << (k/w) << " " << i << " " << (n-k/w-i) << endl;
		return;
	}
	cout << -1 << endl;
}

int main()
{
	int t=1;
	while(t--) solve();
}
