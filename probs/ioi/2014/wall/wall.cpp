#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e6+5;
const int INF  = 1e9+7;
int n, arr[MAXN], st[4*MAXN], lz1[4*MAXN], lz2[4*MAXN];

void upd(int node, int a, int b, int mn, int mx, int l, int r)
{
	if(l == a && r == b)
	{
		st[node] = max(st[node], mx);
		st[node] = min(st[node], mn);
		if(mx > lz1[node])
		{
			lz1[node] = lz2[node] = mx;
		} else if(mn < lz2[node])
		{
			lz1[node] = lz2[node] = mn;
		} else 
		{
			lz1[node] = min(lz1[node], mn);
			lz2[node] = max(lz2[node], mx);
		}
		return;
	}
	int mid = (l+r)/2;
	// nothing that could go wrong here, this is just checking the smaller intervals
	// individually with no deeper recursion
	upd(2*node, l, mid, lz1[node], lz2[node], l, mid);
	upd(2*node+1, mid+1, r, lz1[node], lz2[node], mid+1, r);
	lz1[node] = INF;
	lz2[node] = 0;
	// here is what is wrong
	// we are cutting our current interval into intervals based on mid, and then 
	// we process updates for each interval
	if(b <= mid)
	{
		upd(2*node, a, b, mn, mx, l, mid);
	} else if(a > mid)
	{
		upd(2*node+1, a, b, mn, mx, mid+1, r);
	} else 
	{
		upd(2*node, a, mid, mn, mx, l, mid);
		upd(2*node+1, mid+1, b, mn, mx, mid+1, r);
	}
	st[node] = min(st[2*node], st[2*node+1]);
}

void build(int node, int l, int r)
{
	if(l == r)
	{
		lz1[node] = INF;
		return;
	}
	int mid = (l+r)/2;
	build(node*2, l, mid);
	build(node*2+1, mid+1, r);
	lz1[node] = INF;
}

void convert(int node, int l, int r)
{
	if(l == r)
	{
		arr[l] = st[node];		
		return;
	}
	int mid = (l+r)/2;
	upd(2*node, l, mid, lz1[node], lz2[node], l, mid);
	upd(2*node+1, mid+1, r, lz1[node], lz2[node], mid+1, r);
	lz1[node] = INF;
	lz2[node] = 0;

	convert(2*node, l, mid);
	convert(2*node+1, mid+1, r);
}

void buildWall(int _n, int k, int op[], int left[], int right[], int height[], int finalHeight[])
{
	n = _n;
	build(1, 0, n-1);
	// perform updates for each query.
	for(int i = 0; i < k; i++)
	{
		if(op[i] == 1)
		{
			upd(1, left[i], right[i], INF, height[i], 0, n-1);
		} else 
		{
			upd(1, left[i], right[i], height[i], 0, 0, n-1);
		}
	}
	convert(1, 0, n-1);
	for(int i = 0; i < n; i++) finalHeight[i] = arr[i];
}

/*
int main()
{
	int op[6] = {1,2,2,1,1,2};
	int left[6] = {1,4,3,0,2,6};
	int right[6] = {8,9,6,5,2,7};
	int height[6] = {4,1,5,3,5,0};
	int finalHeight[10] = {0,0,0,0,0,0,0,0,0,0};
	buildWall(10, 6, op, left, right, height, finalHeight);
	for(int i = 0; i < 10; i++)
	{
		cout << finalHeight[i] << " ";
	}
}
*/