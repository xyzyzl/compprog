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

