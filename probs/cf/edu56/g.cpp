#include <bits/stdc++.h>

#define MAX(a, b) ((a > b) ? a : b)
#define MIN(a, b) ((a < b) ? a : b)
#define ABS(a) ((a < 0) ? (-a) : a)
#define INF 1e9+7

#define MAXN 200005
using namespace std;
int n, k, pr[MAXN][5];
int a[MAXN];
struct maxq {
	int st[4*MAXN];
	void build(int nd, int i, int j)
	{
		if(i == j)
		{
			st[nd] = a[i];
			return;
		}
		int d = (i+j)/2;
		build(2*nd  , i  , d);
		build(2*nd+1, d+1, j); 
		st[nd] = MAX(st[2*nd], st[2*nd+1]);
	}
	int rmq(int nd, int i, int j, int l, int r)
	{
		if(i > j || i > r || j < l) return -INF;
		if(i >= l && j <= r) return st[nd];
		int d = (i+j)/2;
		int q1 = rmq(2*nd  , i  , d, l, r);
		int q2 = rmq(2*nd+1, d+1, j, l, r);
		return MAX(q1, q2);
	}
	void upd(int nd, int i, int j, int k, int v)
	{
		if(i == j) 
		{
			st[nd] = v;
			return;
		}
		int d = (i+j)/2;
		if(k <= d) upd(2*nd  , i  , d, k, v);
		else       upd(2*nd+1, d+1, j, k, v);
		st[nd] = MAX(st[2*nd], st[2*nd+1]);
	}
} mx;

struct minq {
	int st[4*MAXN];
	void build(int nd, int i, int j)
	{
		if(i == j)
		{
			st[nd] = a[i];
			return;
		}
		int d = (i+j)/2;
		build(2*nd  , i  , d);
		build(2*nd+1, d+1, j); 
		st[nd] = MIN(st[2*nd], st[2*nd+1]);
	}
	int rmq(int nd, int i, int j, int l, int r)
	{
		if(i > j || i > r || j < l) return INF;
		if(i >= l && j <= r) return st[nd];
		int d = (i+j)/2;
		int q1 = rmq(2*nd  , i  , d, l, r);
		int q2 = rmq(2*nd+1, d+1, j, l, r);
		return MIN(q1, q2);
	}
	void upd(int nd, int i, int j, int k, int v)
	{
		if(i == j) 
		{
			st[nd] = v;
			return;
		}
		int d = (i+j)/2;
		if(k <= d) upd(2*nd  , i  , d, k, v);
		else       upd(2*nd+1, d+1, j, k, v);
		st[nd] = MIN(st[2*nd], st[2*nd+1]);
	}
} mn;

struct query
{
	void init(int t, int a, int b)
	{
		type = t;
		if(t == 1) 
		{
			k = a;
			l = -1;
			r = -1;
			val = -1;
		} else 
		{
			k = -1;
			l = a;
			r = b;
		}
	}
	int type;
	int l, r;
	int k, v[5];
	int val;
} qrs[MAXN];

int q;
void trying(int msk)
{
	for(int i = 0; i < n; i++)
	{
		a[i] = 0;
		for(int j = 0; j < k; j++)
		{
			int w = ((msk & (1 << j)) ? pr[i][j] : -pr[i][j]);
			a[i] += w;
		}
	}
	mx.build(1, 0, n-1);
	mn.build(1, 0, n-1);
	for(int m = 0; m < q; m++)
	{
		if(qrs[m].type == 1)
		{
			int x = 0;
			for(int i = 0; i < k; i++)
			{
				int w = ((msk & (1 << i)) ? qrs[m].v[i] : -qrs[m].v[i]);
				x += w;
			}
			a[qrs[m].k] = x;
			mx.upd(1, 0, n-1, qrs[m].k, x);
			mn.upd(1, 0, n-1, qrs[m].k, x);
		} else 
		{
			int ma = mx.rmq(1, 0, n-1, qrs[m].l, qrs[m].r);
			int mi = mn.rmq(1, 0, n-1, qrs[m].l, qrs[m].r);
			qrs[m].val = MAX(qrs[m].val, ma - mi);
		}
	}
}

int main()
{
	scanf("%d %d", &n, &k);
	for(int i = 0; i < n; i++)
	{
		a[i] = 0;
		for(int j = 0; j < k; j++)
		{
			scanf("%d", &pr[i][j]);
			a[i] += pr[i][j];
		}
	}
	scanf("%d", &q);
	for(int m = 0; m < q; m++)
	{
		int o;
		scanf("%d", &o);
		if(o == 1)
		{
			int ind;
			scanf("%d", &ind);
			--ind;
			int w = 0;
			for(int i = 0; i < k; i++) 
			{
				int x;
				scanf("%d", &x);
				qrs[m].v[i] = x;
				w += x;
			}
			a[ind] = w;
			qrs[m].init(o, ind, 1);
			mx.upd(1, 0, n-1, qrs[m].k, w);
			mn.upd(1, 0, n-1, qrs[m].k, w);
		} else 
		{
			int l, r;
			scanf("%d %d", &l, &r);
			--l; --r;
			qrs[m].init(o, l, r);
			int ma = mx.rmq(1, 0, n-1, qrs[m].l, qrs[m].r);
			int mi = mn.rmq(1, 0, n-1, qrs[m].l, qrs[m].r);
			qrs[m].val = ma-mi;
		}
	}
	for(int msk = 0; msk < (1 << k); msk++)
	{
		trying(msk);
	}
	for(int m = 0; m < q; m++)
	{
		if(qrs[m].type == 2) printf("%d\n", qrs[m].val);
	}
}
