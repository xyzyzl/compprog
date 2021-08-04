#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int n;
ll k;
int main()
{
	cin >> n >> k;
	vector<ll> a(n);
	for(int i = 0; i < n; i++) cin >> a[i];
	sort(a.begin(), a.end());
	vector<ll> b(n);
	for(int i = 0; i < n-1; i++) b[i] = a[i+1]-a[i];
	ll ans = a[n-1] - a[0];
	int l = 0, r = n-2, cnt = 1;
	while(l < r)
	{
		ll rem = min(k, (b[l]+b[r])*cnt);
		ans -= rem/cnt;
		k -= rem;
		++cnt, ++l, --r;
	}
	if(l == r)
	{
		ll rem = min(k, b[l]*cnt);
		ans -= rem/cnt;
		k -= rem;
	}
	cout << ans << endl;
}
