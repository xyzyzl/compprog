#include <stdio.h>
#define MAX(a, b) ((a>b)?a:b)

int n, a[100005];
void solve()
{
	scanf("%d", &n);
	int max = 0;
	for(int i = 0; i < 100005; i++) a[i] = 0;
	for(int i = 0; i < n; i++)
	{
		int x;
		scanf("%d", &x);
		a[x]++;
		max = MAX(max,a[x]);
	}
	int num_occ = 0;
	for(int i = 1; i <= n; i++)
	{
		if(a[i] == max)
			num_occ++;
	}
	printf("%d\n", (n-max*num_occ)/(max-1)+num_occ-1);
}

int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		solve();
	}
}
