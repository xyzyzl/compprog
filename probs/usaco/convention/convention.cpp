#include <bits/stdc++.h>

using namespace std;

int n, m, c, t[100005];

bool ok(int x)
{
	int bh = -1, bi = -1, bs = 0;
	for(int i = 0; i < n; i++)
	{
		if(bh == -1 || t[i] - bh > x || i-bi+1 > c)
		{
			bh = t[i];
			bi = i;
			bs++;
		} 
	}
	// cerr << bs << " " << x << endl;
	return bs <= m;
}

int main()
{
	freopen("convention.in", "r", stdin);
	freopen("convention.out", "w", stdout);
	cin >> n >> m >> c;
	for(int i = 0; i < n; i++) cin >> t[i];
	sort(t, t+n);
	int lo = 0, hi = 1e9;
	while(lo < hi)
	{
		int mid = (lo+hi)/2;
		if(ok(mid)) hi = mid;
		else lo = mid+1;
	}
	cout << hi << endl;
}
