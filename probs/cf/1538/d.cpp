#include <bits/stdc++.h>

using namespace std;
using ll=long long;

int vis[200005];
int main()
{
	vector<int> primes;
	// sieve
	for(ll i = 2; i * i <= 1e9; i++)
	{
		if(vis[i]) continue;
		primes.push_back(i);
		for(ll j = i+i; j * j <= 1e9; j+= i)
		{
			vis[j] = 1;
		}
	}
	int t; cin >> t;
	while(t--)
	{
		ll a, b, k; cin >> a >> b >> k;
		ll g = __gcd(a, b);
		int mn = 0;
		ll mx = 0;
		ll _a = a, _b = b;
		for(int p : primes)
		{
			while(_a % p == 0)
			{
				_a /= p;
				mx++;
			}
		}
		if(_a != 1) 
			mx++;
		for(int p : primes)
		{
			while(_b % p == 0)
			{
				_b /= p;
				mx++;
			}
		}
		if(_b != 1) 
			mx++;
		
		if(a == b) 
		{
			mn = 0;
		} else if(g == a || g == b)
		{
			mn = 1;
		} else 
		{
			mn = 2;
		}
		// cerr << mn << " " << mx << endl;
		if(mn <= k && k <= mx)
		{
			if(k == 1) cout << (mn == 1 ? "YES" : "NO") << endl;
			else cout << "YES" << endl;
		} else cout << "NO" << endl;
	}
}