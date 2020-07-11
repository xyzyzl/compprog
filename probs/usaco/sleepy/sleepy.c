#include <stdio.h>

int n, p[100005], i, bit[200005];
int sum(int x)
{
	int ret = 0;
	while(x > 0)
	{
		ret += bit[x];
		x -= (x & -x);
	}
	return ret;
}
void upd(int x, int v)
{
	while(x <= n)
	{
		bit[x] += v;
		x += (x & -x);
	}
}
int main()
{
	freopen("sleepy.in", "r", stdin);
	freopen("sleepy.out", "w", stdout);
	scanf("%d", &n);
	for(i = 0; i < n; i++)
	{
		scanf("%d", &p[i]);
	}
	int rem = 0;
	for(i = n-1; i >= 0; i--)
	{
		if(i < n-1 && p[i+1] < p[i])
		{
			rem = i+1;
			break;
		}
		upd(p[i], 1);
	}
	int rm = rem;
	printf("%d\n", rem);
	for(i = 0; i < rem; i++)
	{
		int x = 0;
		rm--;
		x += rm;
		x += sum(p[i]);
		if(i == rem-1)
		{
			printf("%d\n", x);
		} else
		{
			printf("%d ", x);
		}
		upd(p[i], 1);
	}
}

