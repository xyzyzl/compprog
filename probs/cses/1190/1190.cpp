#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MAXN = 200005;

struct Node 
{
	ll rs; // range sum
	ll maxl, maxr; // max left, max right
	ll ans;
} st[4*MAXN];

int n, m, a[MAXN];

void build(int node, int l, int r)
{
	if(l == r)
	{
		st[node].rs = st[node].maxl = st[node].maxr = st[node].ans = a[l];
		return;
	}
	int mid = (l+r)/2;
	build(2*node, l, mid);
	build(2*node+1, mid+1, r);
	st[node].rs = st[2*node].rs + st[2*node+1].rs;
	st[node].maxl = max(st[2*node].maxl, st[2*node].rs + st[2*node+1].maxl);
	st[node].maxr = max(st[2*node+1].maxr, st[2*node+1].rs + st[2*node].maxr);
	st[node].ans = max(st[2*node].maxr + st[2*node+1].maxl, max(st[2*node].ans, st[2*node+1].ans));
}

void upd(int node, int l, int r, int k, ll x)
{
	if(l == r)
	{
		st[node].rs = x;
		st[node].maxl = max(x, 0ll);
		st[node].maxr = max(x, 0ll);
		st[node].ans = max(x, 0ll);
		return;
	}
	int mid = (l+r)/2;
	if(k <= mid) upd(2*node, l, mid, k, x);
	else upd(2*node+1, mid+1, r, k, x);
	st[node].rs = st[2*node].rs + st[2*node+1].rs;
	st[node].maxl = max(st[2*node].maxl, st[2*node].rs + st[2*node+1].maxl);
	st[node].maxr = max(st[2*node+1].maxr, st[2*node+1].rs + st[2*node].maxr);
	st[node].ans = max(st[2*node].maxr + st[2*node+1].maxl, max(st[2*node].ans, st[2*node+1].ans));
}

int main()
{
	cin >> n >> m;
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	build(1, 0, n-1);
	for(int i = 0; i < m; i++)
	{
		int k, x; cin >> k >> x;
		--k;
		upd(1, 0, n-1, k, x);
		cout << st[1].ans << endl;
	}
}