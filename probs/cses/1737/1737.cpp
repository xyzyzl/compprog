// straight persistent segtree implementation
#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int MAXN = 200005;

int n, q, T[MAXN];
struct st_node
{
	int l, r;
	ll val = 0;
	st_node(int l, int r, ll val)
	{
		this->l = l;
		this->r = r;
		this->val = val;
	}
};
// keep list of all nodes in the segtree
vector<st_node> st;
vector<int> rts;

int build(int l, int r)
{
	if(r==l)
	{
		st.push_back(st_node(0,0,T[l]));
		return st.size()-1;
	}
	int mid = (l+r)/2;
	int a = build(l, mid);
	int b = build(mid+1, r);
	// make references back to earlier nodes, all nodes are kept in the segtree
	// which is why it's persistent
	st.push_back(st_node(a,b,st[a].val+st[b].val));
	return st.size()-1;
}

int upd(int i, int l, int r, int p, ll val)
{
	if(r==l)
	{
		st.push_back(st_node(0, 0, val));
		return st.size()-1;
	}
	int mid = (l+r)/2;
	int a = st[i].l, b = st[i].r;
	if(p <= mid) a = upd(st[i].l, l, mid, p, val);
	else b = upd(st[i].r, mid+1, r, p, val);
	st.push_back(st_node(a, b, st[a].val+st[b].val));
	return st.size()-1;
}

ll  qry(int i, int l, int r, int a, int b)
{
	if(a<=l && b>=r)
	{
		return st[i].val;
	}
	if(a> r || b< l)
	{
		return 0;
	}
	int mid = (l+r)/2;
	return qry(st[i].l, l, mid, a, b) + qry(st[i].r, mid+1, r, a, b);
}

int main()
{
	cin >> n >> q;
	for(int i = 0; i < n; i++) cin >> T[i];
	rts.push_back(build(0, n-1));
	while(q--)
	{
		int typ, arr;
		cin >> typ >> arr;
		--arr;
		if(typ == 1)
		{
			int a, b; cin >> a >> b;
			// update this one
			rts[arr] = upd(rts[arr], 0, n-1, a-1, b);
		} else if(typ == 2)
		{
			int a, b; cin >> a >> b;
			cout << qry(rts[arr], 0, n-1, a-1, b-1) << endl;
		} else
		{
			rts.push_back(rts[arr]);
		}
	}
}