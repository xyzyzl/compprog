#include <bits/stdc++.h>

#define MAXN 100005

using namespace std;

int n, p, m, a[MAXN];
mii b;
int main()
{
	cin >> n >> p;
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
		m = max(m, a[i]);
	}
	for(int i = m-n; i <= m+n; i++)
	{
		// b_i = upper_bound(a, i) - a
		b[i] = upper_bound(a, a+n, i) - a;
	}
	// do this for x = m-n first
	b[i] = upper_bound(a, a+n, i) - a;
}
