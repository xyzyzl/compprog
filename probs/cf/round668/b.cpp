#include <bits/stdc++.h>

using namespace std;

#define ll long long 

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		vector<ll> a(n);
		for(int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		// find # of negs after current index
		ll aft = 0;
		for(int i = n-1; i >= 0; i--)
		{
			if(a[i] > 0) 
			{
				ll rem = min(aft, a[i]);
				aft -= rem;
				a[i] -= rem;
			} else
			{
				aft -= a[i];
				a[i] = 0;
			}
		}
		ll ans = 0;
		for(int i = 0; i < n; i++)
		{
			ans += a[i];
		}
		cout << ans << endl;
	}
}
