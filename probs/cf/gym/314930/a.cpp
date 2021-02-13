#include <bits/stdc++.h>

using namespace std;
using ll = long long;

// number of ways to get a sum with x and j, with j < y
ll nw(ll x, ll y)
{
	int n = log2(y);
	ll ret = 0;
	ll df = 0;
	for(ll i = 0; i <= n; i++)
	{
		if(y & (1ll << i))
		{
			// do something
			y ^= (1ll << i);
			if(!(x&y))
			{
				ret+=(1 << df); // 2^(number of zeroes) bit manipulations lead to the same end
			}
		}
		if(!(x & (1 << i))) df++; // more zeroes = more free moves
	}
	return ret;
}

// find number of ways to get sums between [l, r-1]
ll dp(ll l, ll r)
{
	if(l == r) return 0;
	if(l == 0)
	{
		return 2*r-1+dp(1, r);
	}
	ll ret = 0;
	if(l%2)
	{
		ret += 2*(nw(l, r) - nw(l, l));
		++l;
	}
	if(r%2)
	{
		ret += 2*(nw(r-1, r) - nw(r-1, l));
		--r;
	}
	return ret+3*dp(l/2, r/2);
}

// want to find the total # of pairs (a, b) in [L, R] s.t. (a & b) = 0 where & is bitwise and.
void solve()
{
	ll L, R; cin >> L >> R;
	cout << dp(L, R+1) << endl;
}

int main()
{
	int t; cin >> t; while(t--)
	{
		solve();
	}
}