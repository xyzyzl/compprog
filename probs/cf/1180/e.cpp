#include <bits/stdc++.h>

using namespace std;

#define MAXN 1000005
#define INF 998244353

#define ll long long int
#define MIN(a,b) ((a > b) ? b : a)

int n, m;
ll st[4*MAXN], lz[4*MAXN];

void build(int nd, int i, int j)
{
	if(i == j)
	{
		st[nd] = 0;
		return;
	}
	int d = (i+j)/2;
	build( 2 * nd    , i  , d);
	build( 2 * nd + 1, d+1, j);
	lz[nd] = 0;
	st[nd] = max(st[2*nd], st[2*nd+1]);
}

void push(int nd)
{
	st[2*nd] += lz[nd];
	st[2*nd+1] += lz[nd];
	lz[2*nd] += lz[nd];
	lz[2*nd+1] += lz[nd];
	lz[nd] = 0;
}

// increment
void upd(int nd, int i, int j, int l, int r, ll v)
{
	if(i > r || j < l) return; // not in range
	if(i >= l && j <= r) // completely in range
	{
		st[nd] += v;
		lz[nd] += v;
		return;
	}
	push(nd);
	int d = (i+j)/2;
	upd( 2 * nd    , i  , d, l, r, v);
	upd( 2 * nd + 1, d+1, j, l, r, v);
	st[nd] = max(st[2 * nd], st[2 * nd + 1]);
}

int f(int nd, int l, int r)
{
	if(l == r) return l;
	push(nd);
	int mid = (l+r)/2;
	if(st[2*nd+1] >= 1) return f(2*nd+1, mid+1, r);
	else return f(2*nd, l, mid);
}

int main()
{
	cin >> n >> m;
	vector<int> a(n), b(m);
	for(int i = 0; i < n; i++) cin >> a[i];
	for(int i = 0; i < m; i++) cin >> b[i];
	int q; cin >> q;
	build(1, 0, MAXN-1);

	for(int i = 0; i < n; i++) upd(1, 0, MAXN-1, 0, a[i], 1);
	for(int i = 0; i < m; i++) upd(1, 0, MAXN-1, 0, b[i], -1);
	
	for(int i = 0; i < q; i++)
	{
		int t, j, x; cin >> t >> j >> x;
		--j;
		if(t==1)
		{
			upd(1, 0, MAXN-1, 0, a[j], -1);
			a[j] = x;
			upd(1, 0, MAXN-1, 0, a[j],  1);
		} else 
		{
			upd(1, 0, MAXN-1, 0, b[j],  1);
			b[j] = x;
			upd(1, 0, MAXN-1, 0, b[j], -1);
		}
		if(st[1] >= 1) cout << f(1, 0, MAXN-1) << endl;
		else cout << -1 << endl;
	}
}
