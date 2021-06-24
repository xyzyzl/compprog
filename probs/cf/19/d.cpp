#include <bits/stdc++.h>

using namespace std;

const int MAXN = 200005;

int n, compx[MAXN], uncompx[MAXN], compy[MAXN], uncompy[MAXN], ist[4*MAXN], xx[MAXN];
pair<int, pair<int, int> > qr[MAXN];
set<int> xv, yv;
multiset<int> st[MAXN];

void build(int node, int l, int r)
{
	if(l == r)
	{
		ist[node] = -1;
		xx[l] = node;
	}
	int mid = (l+r)/2;
	build(2*node, l, mid);
	build(2*node+1, mid+1, r);
}

void upd(int node, int x, int y, bool pm)
{
	if(pm)
	{
		st[x].insert(y);
	} else 
	{
		st[x].erase(st[node].find(y));
	}
	if(!st[x].empty()) ist[node] = *st[x].rbegin();
	else ist[node] = -1;
	while(node)
	{
		node = (node-1)/2;
		if(ist[node] == max(ist[2*node], ist[2*node+1])) break;
		ist[node] = max(ist[2*node], ist[2*node+1]);
	}
}

pair<int, int> find(int node, int l, int r, int x, int y)
{
	if(r <= x)
	{
		return {-1, -1};
	}
	if(ist[node] <= y)
	{
		return {-1, -1};
	}
	if(l == r)
	{
		auto w = st[l].upper_bound(y);
		int q = -1;
		if(w != st[l].end()) return {l, q};
	}
	int mid = (l+r)/2;
	pair<int, int> p = find(2*node, l, mid, x, y);
	if(p.second != -1) return p;
	pair<int, int> q = find(2*node, mid+1, r, x, y);
	return q;
}

int main()
{
	cin >> n;
	build(1, 0, n-1);
	for(int i = 0; i < n; i++)
	{
		string s; cin >> s;
		int a, b; cin >> a >> b;
		xv.insert(a);
		yv.insert(b);
		if(s == "add") qr[i].first = 0;
		else if(s=="remove") qr[i].first = 1;
		else qr[i].first = 2;
		qr[i].second = {a,b};
	}
	int a = 0;
	for(int x : xv)
	{
		compx[x] = a;
		uncompx[a] = x;
		++a;
	}
	a=0;
	for(int y : yv)
	{
		compy[y] = a;
		uncompy[a] = y;
		++a;
	}
	for(int i = 0; i < n; i++)
	{
		int x = compx[qr[i].second.first];
		int y = compy[qr[i].second.second];
		if(qr[i].first == 0)
		{
			// add
			upd(1, x, y, 1);
		} else if(qr[i].first == 1)
		{
			// remove
			upd(1, x, y, 0);
		} else 
		{
			// find
			pair<int, int> ret = find(1, 0, n-1, x, y);
			cout << uncompy[ret.second] << endl;
		}
	}
}