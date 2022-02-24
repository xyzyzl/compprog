#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // pbds
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;
using pii = pair<int,int>;
typedef tree<pii, null_type, less<pii>, rb_tree_tag, tree_order_statistics_node_update> osii;

const int MAXN = 100005;

int n, k, h[MAXN], ih[MAXN], iih[MAXN];
ll st[4*MAXN], lz[4*MAXN];

// increment
void upd(int nd, int i, int j, int l, int r, ll v)
{
	if(lz[nd] != 0)
	{
		st[nd] += lz[nd];
		if(i != j) 
		{
			lz[ 2 * nd     ] += lz[nd]; // update children
			lz[ 2 * nd + 1 ] += lz[nd]; // of node nd
		}
		lz[nd] = 0; // finished updates on node nd
	}
	if(i > r || j < l) return; // not in range
	if(i >= l && j <= r) // completely in range
	{
		st[nd] += v;
		if(i != j)
		{
			lz[ 2 * nd     ] += v; // update children
			lz[ 2 * nd + 1 ] += v; // of node nd
		}
		return;
	}
	int d = (i+j)/2;
	upd( 2 * nd    , i  , d, l, r, v);
	upd( 2 * nd + 1, d+1, j, l, r, v);
	st[nd] = min(st[2 * nd], st[2 * nd + 1]);
}

int first0(int nd, int i, int j)
{
	if(lz[nd] != 0)
	{
		st[nd] += lz[nd];
		if(i != j) 
		{
			lz[ 2 * nd     ] += lz[nd]; // update children
			lz[ 2 * nd + 1 ] += lz[nd]; // of node nd
		}
		lz[nd] = 0; // finished updates on node nd
	}
	if(st[nd] > 0) return -1;
	if(i==j) return i;
	int d = (i+j)/2;
	int res = first0(2*nd, i, d);
	if(res != -1) return res;
	else return first0(2*nd+1, d+1, j);
}

// first index such that h[i] is too big
int first_gt(int i)
{
	int lo = 0, hi = n;
	while(lo < hi)
	{
		int mid = (lo+hi)/2;
		if(h[ih[mid]] > h[i] + k) hi = mid; 
		else lo = mid+1;
	}
	return lo;
}

// last index such that h[i] is too small
int last_lt(int i)
{
	int lo = -1, hi = n-1;
	while(lo < hi)
	{
		int mid = (lo+hi+1)/2;
		if(h[ih[mid]] < h[i] - k) lo = mid; 
		else hi = mid-1;
	}
	return lo;
}

int main()
{
	cin >> n >> k;
	for(int i = 0; i < n; i++)
	{
		cin >> h[i];
		ih[i] = i;
	}
	sort(ih, ih+n, [](int x, int y) { return h[x] < h[y]; });
	for(int i = 0; i < n; i++) iih[ih[i]] = i;
	osii cur; // heights we have currently already seen
	for(int i = 0; i < n; i++)
	{
		cur.insert({h[i], i});
		int s1 = cur.order_of_key({h[i]-k, -1});
		int s2 = cur.size()-cur.order_of_key({h[i]+k+1, -1});
		upd(1, 0, n-1, iih[i], iih[i], s1+s2);
	}
	for(int i = 0; i < n; i++)
	{
		int x = first0(1, 0, n-1);
		if(x == -1)
		{
			cout << "Eighteen naked cowboys in the showers at Ram Ranch" << endl;
			cout << "Big hard throbbing cocks wanting to be sucked" << endl;
			cout << "Eighteen naked cowboys wanting to be fucked" << endl;
			return 1;
		}
		int j = ih[x];
		cout << h[j] << endl;

		upd(1, 0, n-1, 0, last_lt(j), -1);
		upd(1, 0, n-1, x, x, n);
		upd(1, 0, n-1, first_gt(j), n-1, -1);
	}
}