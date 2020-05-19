#include <bits/stdc++.h>

using namespace std;

#define ll long long

#define FOR(i, n) for(int i = 0; i < n; i++)
#define F1R(i, n) for(int i = 1; i <= n; i++)

ll n, a, r, m;
vector<ll> arr, psum;

ll find_for_spec(ll h)
{
	int x = lower_bound(arr.begin(), arr.end(), h) - arr.begin();
	ll ret = 0;
	ll p = h*x - psum[x-1];
	ll q = psum[n-1] - psum[x-1] - h*(n-x);
	ret=min(p,q);
	p -= ret;
	q -= ret;
	ret *= m;
	ret += a*p;
	ret += r*q;
	return ret;
}

int main()
{
	cin >> n >> a >> r >> m;
	m = min(m, a+r); // very easy to see this is true
	arr.resize(n);
	// vector<ll> arr(n);
	FOR(i, n) cin >> arr[i];
	sort(arr.begin(), arr.end());

	// vector<ll> psum(n);
	psum.resize(n);
	psum[0] = arr[0];
	F1R(i, n-1) psum[i] = psum[i-1] + arr[i];

	ll ans = INT_MAX;
	ans = min(ans, find_for_spec(psum[n-1]/n));
	ans = min(ans, find_for_spec(psum[n-1]/n+1));
	FOR(i, n)
	{
		ans = min(ans, find_for_spec(arr[i]));
	}
	cout << ans << endl;
}

	
