// how to do:
// basically sparse segment tree with lazy propagation. i kind of copied a sparse segment tree impl because i do
// not know how to do sparse segtree. will familiarize myself with that and recode this part. but the rest of the question
// seems pretty intuitive. just keep a running prefix sum and prefix max and use lazy to process range updates

#include <bits/stdc++.h>

using namespace std;

const int MX = 1 << 17;
const int INF = 1e9+7;
struct node 
{
	int S, M, l, r, lz = INF;
	node *lc, *rc;
	node(int l, int r)
	{
		lc = rc = NULL;
		this -> l = l;
		this -> r = r;
	}
	// segtree methods
	void mod(int v)
	{
		if(v == INF) return;
		S = (r-l)*v;
		M = max((r-l)*v, 0);
		lz = v;
	}

	void propagate()
	{
		int mid = (l+r)/2;
		if(!lc) lc = new node(l, mid);
		if(!rc) rc = new node(mid, r);
		// do lazy propagation on the new nodes
		lc -> mod(lz);
		rc -> mod(lz);
		lz = INF;
	}

	int calc(int v)
	{
		if(r - l == 1) return l - (v < M);
		propagate();
		if(lc -> M > v) return lc -> calc(v);
		else return rc -> calc(v - lc -> S);
	}

	// make some changes to the track
	void upd(int _l, int _r, int d)
	{
		if(_r <= l || _l >= r) return; // totally out of bounds
		if(_l <= l && r <= _r) // completely in range
		{
			mod(d);
			return;
		}
		propagate();
		lc -> upd(_l, _r, d);
		rc -> upd(_l, _r, d);
		S = lc->S + rc->S;
		M = max(lc->M, rc->M+lc->S);
	}
};

int n;
int main()
{
	cin >> n;
	char c;
	node tree(0, n+1);
	while(true)
	{
		cin >> c;
		if(c == 'E') break;
		else if(c == 'Q')
		{
			int h; cin >> h;
			// find the maximum sum from 0 to i s.t. sum[0, i] <= h
			cout << tree.calc(h) << endl;
		} else if(c == 'I')
		{
			int l, r, d; cin >> l >> r >> d;
			tree.upd(l, r+1, d);
		}
	}
}
