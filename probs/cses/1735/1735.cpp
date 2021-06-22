#include <bits/stdc++.h>

using namespace std;

#define MAXN 200005
#define INF 998244353

#define ll long long int
#define MIN(a,b) ((a > b) ? b : a)

int n;
ll a[MAXN];
ll st[4*MAXN], lz[4*MAXN], lz2[4*MAXN];

void pdown(int nd1, int nd2)
{
	if(lz2[nd1])
	{
		lz2[nd2] = lz2[nd1];
		lz[nd2] = lz[nd1];
	} else lz[nd2] += lz[nd1];
}

void move(int nd, int i, int j)
{
	if(lz2[nd]) st[nd] = (j-i+1)*lz2[nd];
	st[nd] += (j-i+1)*lz[nd];
	if(i != j)
	{
		pdown(nd, 2*nd);
		pdown(nd, 2*nd+1);
	}
	lz[nd] = lz2[nd] = 0;
}

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
	st[nd] = st[2*nd] + st[2*nd+1];
}

// increment
void upd(int nd, int i, int j, int l, int r, ll v)
{
	if(i > r || j < l) return; // not in range
	if(i >= l && j <= r) // completely in range
	{
		st[nd] += v*(j-i+1);
		if(i != j)
		{
			lz[ 2 * nd     ] += v; // update children
			lz[ 2 * nd + 1 ] += v; // of node nd
		}
		return;
	}
	move(nd, i, j);
	int d = (i+j)/2;
	upd( 2 * nd    , i  , d, l, r, v);
	upd( 2 * nd + 1, d+1, j, l, r, v);
	st[nd] = st[2 * nd] + st[2 * nd + 1];
}

// assign
void upd2(int nd, int i, int j, int l, int r, ll v)
{
	if(i > r || j < l) return; // not in range
	if(i >= l && j <= r) // completely in range
	{
		st[nd] = v*(j-i+1);
		if(i != j)
		{
			lz2[ 2 * nd     ] = v; // update children
			lz2[ 2 * nd + 1 ] = v; // of node nd
			lz [ 2 * nd     ] = 0;
			lz [ 2 * nd + 1 ] = 0;
		}
		return;
	}
	move(nd, i, j);
	int d = (i+j)/2;
	upd2( 2 * nd    , i  , d, l, r, v);
	upd2( 2 * nd + 1, d+1, j, l, r, v);
	move(2*nd, i, d);
	move(2*nd+1, d+1, j);
	st[nd] = st[2 * nd] + st[2 * nd + 1];
}

ll rmq(int nd, int i, int j, int l, int r)
{
	if(i > r || j < l) return 0;
	// first set
	if(lz2[nd] != 0)
	{
		st[nd] = lz2[nd]*(j-i+1);
		if(i != j)
		{
			lz2[2*nd] = lz2[nd];
			lz2[2*nd+1] = lz2[nd];
		}
		lz2[nd] = 0;
	}
	// then increase
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
	ll p = rmq( 2 * nd    , i  , d, l, r);
	ll q = rmq( 2 * nd + 1, d+1, j, l, r);
	// cerr << p << " " << q << endl;
	return p+q;
}

int main()
{
	int n, q; scanf("%d %d", &n, &q);
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	build(1, 0, n-1);
	while(q--)
	{
		int t; scanf("%d", &t);
		if(t == 1)
		{
			int l, r, v; scanf("%d %d %d", &l, &r, &v);
			--l; --r;
			upd(1, 0, n-1, l, r, v);
		}
		else if(t == 2)
		{
			int l, r, v; scanf("%d %d %d", &l, &r, &v);
			--l; --r;
			upd2(1, 0, n-1, l, r, v);
		}
		else
		{
			int l, r; scanf("%d %d", &l, &r);
			--l; --r;
			ll ret = rmq(1, 0, n-1, l, r);
			printf("%lld\n", ret);
		}
	}
}