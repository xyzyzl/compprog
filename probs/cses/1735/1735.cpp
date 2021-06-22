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
	vector<int> lz3;
	ST()
	{
	}
	ST(int n, vector<ll> a)
	{
		this->n = n;
		this->a = a;
		st.resize(4 * n);
		lz.resize(4 * n);
		lz2.resize(4 * n);
		lz3.resize(4 * n);
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

	void push(int nd, int und)
	{
		if(lz3[nd])
		{
			lz3[und] = 1;
			lz2[und] = lz2[nd];
			lz[und] = lz[nd];
		}
		else 
		{
			lz[und] += lz[nd];
		}
	}

	void prop(int nd, int i, int j)
	{
		if(lz3[nd]) st[nd] = (j-i+1)*lz2[nd];
		st[nd] += (j-i+1)*lz[nd];
		if (i != j)
		{
			int d = (i + j) / 2;
			push(nd, 2 * nd);
			push(nd, 2 * nd + 1);
		}
		lz[nd] = lz2[nd] = lz3[nd] = 0;
	}

	// increment
	void upd(int nd, int i, int j, int l, int r, ll v)
	{
		prop(nd, i, j);
		if (i > r || j < l)
			return;			  // not in range
		if (i >= l && j <= r) // completely in range
		{
			lz[nd] += v;
			return;
		}
		int d = (i + j) / 2;
		upd(2 * nd, i, d, l, r, v);
		upd(2 * nd + 1, d + 1, j, l, r, v);
		prop(2*nd, i, d);
		prop(2*nd+1, d+1, j);
		st[nd] = st[2 * nd] + st[2 * nd + 1];
	}

	// assign
	void upd2(int nd, int i, int j, int l, int r, ll v)
	{
		prop(nd, i, j);
		if (i > r || j < l)
			return;			  // not in range
		if (i >= l && j <= r) // completely in range
		{
			lz[nd] = 0;
			lz2[nd] = v;
			lz3[nd] = 1;
			return;
		}
		int d = (i + j) / 2;
		upd2(2 * nd, i, d, l, r, v);
		upd2(2 * nd + 1, d + 1, j, l, r, v);
		prop(2*nd, i, d);
		prop(2*nd+1, d+1, j);
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
	st1.build(1, 0, n - 1);
	while (q--)
	{
		int t;
		cin >> t;
		if(t == 1)
		{
			int a, b, c; cin >> a >> b >> c; --a; --b;
			st1.upd(1, 0, n-1, a, b, c);
		} else if(t == 2)
		{
			int a, b, c; cin >> a >> b >> c; --a; --b;
			st1.upd2(1, 0, n-1, a, b, c);
		} else 
		{
			int a, b; cin >> a >> b; --a; --b;
			cout << st1.rmq(1, 0, n-1, a, b) << endl;
		}
	}
}