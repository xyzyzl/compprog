#include <stdio.h>
#include <string.h>
#define ll long long

int n, a[100005], i;
ll bit[200005], invc[100005];

ll sum(int x)
{
	ll ret = 0;
	while(x > 0)
	{
		ret += bit[x];
		x -= (x & -x);
	}
	return ret;
}

void upd(int x, int v)
{
	while(x <= n+1)
	{
		bit[x] += v;
		x += (x & -x);
	}
}

ll c2(int k)
{
	return k*(k-1)/2;
}

int main()
{
	scanf("%d", &n);
	for(i = 0; i < n; i++) scanf("%d", &a[i]);
	// find # inversions for each index. take the sum and take a nC2.
	ll ans = 0;
	for(i = 0; i < n; i++)
	{
		invc[i] = (sum(n+1)-sum(a[i]));
		upd(a[i], 1);
	}
	memset(bit, 0, sizeof bit);
	for(i = n-1; i >= 0; i--)
	{
		ans += invc[i] * sum(a[i]-1);
		upd(a[i], 1);
	}
	printf("%lld\n", ans);
}