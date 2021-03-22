// watch your globals !!!!!!!!!
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MAXN = 200005;

int n, leaf[MAXN], m, nv, L[20*MAXN], R[20*MAXN], sz[20*MAXN], val;
ll  inv1, inv2, ans;

// this isn't even small to large merging, this is just merging
// doesn't seem very related tbh
int mrg(int node1, int node2)
{
	if(!node1) return node2;
	if(!node2) return node1;
	inv1 += (ll)sz[L[node1]]*sz[R[node2]]; // so we try to find the inversion counts accordingly
	inv2 += (ll)sz[R[node1]]*sz[L[node2]]; // and for each permutation of them
	L[node1] = mrg(L[node1], L[node2]);
	R[node1] = mrg(R[node1], R[node2]);
	sz[node1] += sz[node2];
	return node1;
}

void upd(int node, int l, int r)
{
	sz[node]++;
	if(l == r) return;
	int mid = (l+r)/2;

	if (val <= mid)
	{
		L[node] = ++nv; // less than the mid value
		upd(L[node], l, mid);
	} else 
	{
		R[node] = ++nv; // greater than the mid value
		upd(R[node], mid+1, r);
	}
}

int read()
{
	cin >> val;
	if(val > 0)
	{
		// it's a leaf
		leaf[m] = ++nv;
		upd(leaf[m], 1, n);
		return leaf[m];
	} else
	{
		// merge next two
		int k = mrg(read(), read());
		ans += min(inv1, inv2);
		inv1=inv2=0;
		return k;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	read();
	cout << ans << endl;
}