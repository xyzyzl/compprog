#include <stdio.h>
#include <limits.h>

#define MAXN 200005
#define INF 998244353

#define ll long long int
#define MIN(a,b) ((a > b) ? b : a)

int n;
ll a[MAXN];
ll st[4*MAXN], lz[4*MAXN];

void build(int nd, int i, int j)
{
	if(i == j)
	{
		st[nd] = a[i];
		return;
	}
	int d = (i+j)/2;
	build( 2 * nd    , i  , d);
	build( 2 * nd + 1, d+1, j);
	lz[nd] = 0;
	st[nd] = MIN(st[2*nd], st[2*nd+1]);
}

void debug(int nd, int i, int j)
{
	if(i == j)
	{
		printf("%d ", st[nd]);
		return;
	}
	int d = (i+j)/2;
	debug( 2 * nd    , i  , d);
	debug( 2 * nd + 1, d+1, j);
}
// increment
void upd(int nd, int i, int j, int l, int r, ll v)
{
	if(lz[nd] != 0)
	{
		st[nd] += lz[nd];
		if(i != j) 
		{
			lz[ 2 * nd     ] += lz[nd]; // update children
			lz[ 2 * nd + 1 ] += lz[nd]; // of node nd
		}
		lz[nd] = 0; // finished updates on node nd
	}
	if(i > r || j < l) return; // not in range
	if(i >= l && j <= r) // completely in range
	{
		st[nd] += v;
		if(i != j)
		{
			lz[ 2 * nd     ] += v; // update children
			lz[ 2 * nd + 1 ] += v; // of node nd
		}
		return;
	}
	int d = (i+j)/2;
	upd( 2 * nd    , i  , d, l, r, v);
	upd( 2 * nd + 1, d+1, j, l, r, v);
	st[nd] = MIN(st[2 * nd], st[2 * nd + 1]);
}

ll rmq(int nd, int i, int j, int l, int r)
{
	if(i > r || j < l) return INF;
	if(lz[nd] != 0)
	{
		st[nd] += lz[nd];
		if(i != j)
		{
			lz[ 2 * nd     ] += lz[nd];
			lz[ 2 * nd + 1 ] += lz[nd];
		}
		lz[nd] = 0;
	}
	if(i >= l && j <= r) return st[nd];
	int d = (i+j)/2;
	int p = rmq( 2 * nd    , i  , d, l, r);
	int q = rmq( 2 * nd + 1, d+1, j, l, r);
	return MIN(p,q);
}

int main()
{
	scanf("%d", &n);
	for(int i = 0; i < n; i++) scanf("%lld", &a[i]);
	build(1, 0, n-1);
	int q;
	scanf("%d", &q);
	while(q--)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		char c = getchar();
		if(c == ' ')
		{
			ll v;
			scanf("%lld", &v);
			if(a > b)
			{
				upd(1, 0, n-1, a, n-1, v);
				upd(1, 0, n-1, 0, b  , v);
			} else upd(1, 0, n-1, a, b, v);
		} else 
		{
			if(a > b)
			{
				ll k = rmq(1, 0, n-1, a, n-1);
				ll l = rmq(1, 0, n-1, 0, b  );
				printf("%lld\n", MIN(k,l));
			} else printf("%lld\n", rmq(1, 0, n-1, a, b));
		}
	}	
}
