#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MAXN = 200005;
const ll INF = 1e18;

int n, q;
vector<ll> x;

struct ST
{
	int n;
	vector<ll> a;
	vector<ll> st, lz, lz2;
	ST()
	{
	}
	ST(int n, vector<ll> a)
	{
		this->n = n;
		this->a = a;
		st.resize(4*n);
		lz.resize(4*n);
		lz2.resize(4*n);
	}

	void build(int nd, int i, int j)
	{
		if (i == j)
		{
			st[nd] = a[i];
			return;
		}
		int d = (i + j) / 2;
		build(2 * nd, i, d);
		build(2 * nd + 1, d + 1, j);
		lz[nd] = 0;
		st[nd] = st[2 * nd] + st[2 * nd + 1];
	}

	void push(int nd, int i, int j, ll p, ll q)
	{
		int len = (j-i+1);
		st[nd] += p*len + q*len*(len+1)/2;
		lz[nd] += p;
		lz2[nd] += q;
	}

	void prop(int nd, int i, int j)
	{
		if(i == j) return;
		int d = (i+j)/2;
		push(2*nd, i, d, lz[nd], lz2[nd]);
		push(2*nd+1, d+1, j, lz[nd] + lz2[nd] * (d+1-i), lz2[nd]);
		lz[nd] = lz2[nd] = 0;
	}

	// increment
	void upd(int nd, int i, int j, int l, int r, ll v)
	{
		prop(nd, i, j);
		if (i > r || j < l)
			return;			  // not in range
		if (i >= l && j <= r) // completely in range
		{
			push(nd, i, j, i-l, v);
			return;
		}
		int d = (i + j) / 2;
		upd(2 * nd, i, d, l, r, v);
		upd(2 * nd + 1, d + 1, j, l, r, v);
		st[nd] = st[2 * nd] + st[2 * nd + 1];
	}

	ll rmq(int nd, int i, int j, int l, int r)
	{
		if (i > r || j < l)
			return 0;
		prop(nd, i, j);
		if (i >= l && j <= r)
			return st[nd];
		int d = (i + j) / 2;
		ll p = rmq(2 * nd, i, d, l, r);
		ll q = rmq(2 * nd + 1, d + 1, j, l, r);
		return p + q;
	}
} st1;

int main()
{
	cin >> n >> q;
	x.resize(n);
	for (int i = 0; i < n; i++)
	{
		cin >> x[i];
	}
	st1 = ST(n, x);
	st1.build(1, 0, n-1);
	while (q--)
	{
		int t, a, b;
		cin >> t >> a >> b;
		--a;
		--b;
		if(t == 1)
		{
			st1.upd(1, 0, n-1, a, b, 1);
		} else 
		{
			cout << st1.rmq(1, 0, n-1, a, b) << endl;
		}
	}
}