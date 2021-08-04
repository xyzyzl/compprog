#include <bits/stdc++.h>

using namespace std;

struct Node
{
	int p, s, sublen, len;
} zero {0,0,0,1}, one {1,1,1,1};

Node operator+(const Node &a, const Node &b)
{
	return {(a.p==a.len ? a.len+b.p : a.p),
			(b.s==b.len ? b.len+a.s : b.s),
			max(max(a.sublen, b.sublen), a.s+b.p),
			a.len+b.len};
}

int n;
template<typename T, size_t N>
struct ST
{
	T st[4*N], def = zero;
	T f(T a, T b) { return a + b; }
	void build(int node = 1, int l = 0, int r = n-1)
	{
		if(l == r)
		{
			st[node] = def;
			return;
		}
		int mid = (l+r)/2;
		build(2*node, l, mid);
		build(2*node+1, mid+1, r);
		st[node] = f(st[2*node], st[2*node+1]);
	}

	void upd(int ind, T val, int node = 1, int l = 0, int r = n-1)
	{
		if(l == r)
		{
			st[node] = val;
			return;
		}
		int mid = (l+r)/2;
		if(ind <= mid)
			upd(ind, val, 2*node, l, mid);
		else
			upd(ind, val, 2*node+1, mid+1, r);
		st[node] = f(st[2*node], st[2*node+1]);
		// cout << st[2*node].sublen << " " << st[2*node+1].sublen << endl;
		// cout << st[node].sublen << endl;
	}

	T qry(int a, int b, int node = 1, int l = 0, int r = n-1)
	{
		if(b < l || r < a) return def;
		if(a <= l && r <= b) return st[node];
		int mid = (l+r)/2;
		return f(qry(a,b,2*node,l,mid), qry(a,b,2*node+1,mid+1,r));
	}

	ST()
	{
		build();
	}
};


string s;
int main()
{
	cin >> s;
	n = s.length();
	ST<Node, 200005> st0;
	ST<Node, 200005> st1;
	for(int i = 0; i < n; i++)
	{
		if(s[i] == '0')
		{
			st0.upd(i, one);
			st1.upd(i, zero);
		} else 
		{
			st0.upd(i, zero);
			st1.upd(i, one);
		}
	}
	// cout << st0.qry(0, n-1).sublen << endl;
	int q; cin >> q;
	while(q--)
	{
		int x; cin >> x;
		--x;
		if(s[x] == '0')
		{
			st0.upd(x, zero);
			st1.upd(x, one);
			s[x] = '1';
		} else 
		{
			st0.upd(x, one);
			st1.upd(x, zero);
			s[x] = '0';
		}
		cout << max(st0.qry(0, n-1).sublen, st1.qry(0, n-1).sublen) << ' ';
	}
	cout << endl;
}
