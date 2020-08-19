#include <stdio.h>

#define MIN(a, b) ((a<b)?a:b)
#define MAX(a, b) ((a>b)?a:b)

long long gcd(long long a, long long b)
{
	if(a==0) return b;
	return gcd(b%a, a);
}

int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		long long m, d, w;
		scanf("%lld %lld %lld", &m, &d, &w);
		long long c = w/(gcd(MIN(w, d-1), MAX(w, d-1)));
		// find all pairs (x,y) s.t. c | x-y
		long long x = MIN(d,m)/c;
		long long y = MIN(d,m);
		long long z = y*x - c*(x*(x+1)/2);
		printf("%lld\n", z);
	}
}
