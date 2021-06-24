#include <bits/stdc++.h>

using namespace std;
const int MAXN = 50005;

int n, a[MAXN];

struct node 
{
	int best_l, best_r, sum, best_sum;
	void mrg(node &a, node &b)
	{
		sum = a.sum + b.sum;
		best_l = max(a.best_l,a.sum+b.best_l);
		best_r = max(a.best_r+b.sum,b.best_r);
		best_sum = max(max(a.best_sum,b.best_sum), a.best_r+b.best_l);
	}
	void new_node(int val)
	{
		sum = best_l = best_r = best_sum = val;
	}
} st[MAXN*4];

void build(int nd, int l, int r)
{
	if(l == r)
	{
		st[nd].new_node(a[l]);
		return;
	}
	int mid = (l+r)/2;
	build(2*nd, l, mid);
	build(2*nd+1, mid+1, r);
	st[nd].mrg(st[2*nd], st[2*nd+1]);
}

node qry(int nd, int l, int r, int x, int y)
{
	if(x == l && y == r)
	{
		return st[nd];
	}
	int mid = (l+r)/2;
	if(mid >= y) return qry(2*nd, l, mid, x, y);
	else if(mid < x) return qry(2*nd+1, mid+1, r, x, y);
	else 
	{
		node ret, u, v;
		ret.mrg(u=qry(2*nd, l, mid, x, mid), v=qry(2*nd+1, mid+1, r, mid+1, y));
		return ret;
	}
}

int main()
{
	cin >> n;
	for(int i = 0; i < n; i++) cin >> a[i];
	build(1, 0, n-1);
	int m; cin >> m;
	for(int i = 0; i < m; i++) 
	{
		int x, y; cin >> x >> y;
		cout << qry(1, 0, n-1, x-1, y-1).best_sum << endl;
	}
}