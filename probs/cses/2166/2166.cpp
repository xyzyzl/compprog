#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MAXN = 200005;

int n, q;
int a[MAXN], p[MAXN];

struct Node 
{
	ll sm, ps;
	// node with a given sum and prefix sum
	Node(int sm, int ps)
	{
		this->sm = sm;
		this->ps = ps;
	}
	// totally new node
	Node(ll x = 0)
	{
		this->sm = x;
		this->ps = max(0ll, x);
	}
} st[4*MAXN];

void build(int node, int l, int r)
{
	if(l == r)
	{
		st[node] = Node(a[l]);
		return;
	}
	int mid = (l+r)/2;
	build(2*node, l, mid);
	build(2*node+1, mid+1, r);
	st[node].sm = st[2*node].sm + st[2*node+1].sm;
	st[node].ps = max(st[2*node].ps, st[2*node].sm + st[2*node+1].ps);
}

void upd(int node, int l, int r, int ind, int val)
{
	if(l == r)
	{
		st[node] = Node(val);
		return;
	}
	int mid = (l+r)/2;
	if(ind <= mid) upd(2*node, l, mid, ind, val);
	else upd(2*node+1, mid+1, r, ind, val);
	st[node].sm = st[2*node].sm + st[2*node+1].sm;
	st[node].ps = max(st[2*node].ps, st[2*node].sm + st[2*node+1].ps);
}

Node rmq(int node, int l, int r, int a, int b)
{
	if(a > r || b < l) return Node(0);
	if(a <= l && b >= r)
	{
		return st[node];
	}
	int mid = (l+r)/2;
	Node p = rmq(2*node, l, mid, a, b);
	Node q = rmq(2*node+1, mid+1, r, a, b);
	p.ps = max(p.ps, p.sm + q.ps);
	p.sm = p.sm + q.sm;
	return p;
}

int main()
{
	cin >> n >> q;
	for(int i = 0; i < n; i++) cin >> a[i];
	build(1, 0, n-1);
	for(int i = 0; i < q; i++)
	{
		int ty; cin >> ty;
		if(ty == 1)
		{
			int k, v; cin >> k >> v;
			--k;
			upd(1, 0, n-1, k, v);
		} else 
		{
			int u, v; cin >> u >> v;
			--u; --v;
			cout << rmq(1, 0, n-1, u, v).ps << endl;
		}
	}
}