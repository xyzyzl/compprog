#include <stdio.h>
#define MAX(a,b) ((a>b)?a:b)

int deg[100005];
int main()
{
	freopen("planting.in", "r", stdin);
	freopen("planting.out", "w", stdout);
	int n;
	scanf("%d", &n);
	int i;
	for(i = 1; i < n; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		deg[a]++;
		deg[b]++;
	}
	int md = 0;
	for(i = 1; i <= n; i++)
	{
		md = MAX(md, deg[i]);
	}
	printf("%d\n", md+1);
}
		
