#include <stdio.h>

#define ll long long int
#define MIN(x, y) ((x < y)?x : y)
#define MAXN 200005
const ll INF = 1e15+7;

int n, q;
ll a[MAXN], st[4*MAXN], lz[4*MAXN];

void build(int nd, int l, int r)
{
	if(l == r)
	{
		st[nd] = a[l];
		return;
	}
	int mid = (l+r)/2;
	build(2*nd, l, mid);
	build(2*nd+1, mid+1, r);
	lz[nd] = 0;
	st[nd] = MIN(st[2*nd], st[2*nd+1]);
}

void upd(int nd, int l, int r, int a, int b, ll u)
{
	if(lz[nd] != 0)
	{
		st[nd] += lz[nd];
		if(l != r)
		{
			lz[2*nd] += lz[nd];
			lz[2*nd+1] += lz[nd];
		}
		lz[nd] = 0;
	}
	if(l > b || r < a) return;
	if(l >= a && r <= b)
	{
		st[nd] += u;
		if(l != r)
		{
			lz[2*nd] += u;
			lz[2*nd+1] += u;
		}
		return;
	}
	int mid = (l+r)/2;
	upd(2*nd, l, mid, a, b, u);
	upd(2*nd+1, mid+1, r, a, b, u);
	st[nd] = MIN(st[2*nd], st[2*nd]+1);
}

ll rmq(int nd, int l, int r, int a)
{
	int b = a;
	if(l > b || r < a) return INF;
	if(lz[nd] != 0)
	{
		st[nd] += lz[nd];
		if(l != r)
		{
			lz[2*nd] += lz[nd];
			lz[2*nd+1] += lz[nd];
		}
		lz[nd] = 0;
	}
	if(l >= a && r <= b) return st[nd];
	int mid = (l+r)/2;
	ll q1 = rmq(2*nd, l, mid, a);
	ll q2 = rmq(2*nd+1, mid+1, r, a);
	return MIN(q1, q2);
}

int main()
{
	scanf("%d %d", &n, &q);
	for(int i = 0; i < n; i++) scanf("%lld", &a[i]);
	build(1, 0, n-1);
	while(q--)
	{
		int type; scanf("%d", &type);
		if(type == 1)
		{
			int a, b, u;
			scanf("%d %d %d", &a, &b, &u);
			--a; --b;
			upd(1, 0, n-1, a, b, u);
		} else 
		{
			int k;
			scanf("%d", &k);
			--k;
			printf("%lld\n", rmq(1, 0, n-1, k));
		}
	}
}