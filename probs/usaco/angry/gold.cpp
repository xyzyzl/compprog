#include <bits/stdc++.h>

#define ll long long
using namespace std;

int n, x[50005];

bool can_L(int R, int pos)
{
	if(x[0] >= pos-R) return 1;
	int p = *lower_bound(x, x+n, pos-R);
	int r = R-2;
	while(p != x[0])
	{
		int np = *lower_bound(x, x+n, p-r);
		if(np >= p) return 0;
		if(r <= 0) return 0;
		p = np;
		r -= 2;
	}
	return 1;
}

bool can_R(int R, int pos)
{
	if(x[n-1] <= pos+R) return 1;
	int p = *prev(upper_bound(x, x+n, pos+R));
	int r = R-2;
	while(p != x[n-1])
	{
		int np = *prev(upper_bound(x, x+n, p+r));
		if(np <= p) return 0;
		if(r <= 0) return 0;
		p = np;
		r -= 2;
	}
	return 1;
}

int main()
{
	freopen("angry.in", "r", stdin);
	freopen("angry.out", "w", stdout);
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		cin >> x[i];
		x[i] *= 2;
	}
	sort(x, x+n);
	ll lo = 1, hi = 1e9; // radius bsearch
	while(lo != hi)
	{
		ll m1 = (lo+hi)/2;
		ll p = x[0], q = x[n-1]; // position bsearch
		while(p < q)
		{
			int m2 = (p+q+1)/2;
			if(can_L(m1, m2)) // p down to left end works for this R
			{
				p=m2;
			} else
			{
				q=m2-1;
			}
		}
		if(can_R(m1, p))
		{
			hi = m1;
		} else
		{
			lo = m1+1;
		}	
	}
	cout << setprecision(1) << fixed << (double)(lo/2.0) << endl;
}