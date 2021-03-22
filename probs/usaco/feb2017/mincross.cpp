#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define bitinc(x) (x&-x)

const int MAXN = 100005;
int n, a[MAXN], b[MAXN], c[MAXN], d[MAXN];

int bit[2*MAXN];
int sum(int ind)
{
	int sm = 0;
	while(ind > 0)
	{
		sm += bit[ind];
		ind -= bitinc(ind);
	}
	return sm;
}
void upd(int ind, int val)
{
	while(ind <= n)
	{
		bit[ind] += val;
		ind += bitinc(ind);
	}
}

ll ct_inv()
{
	ll ret=0;
	int mx = 0;
	for(int i = 0; i <= n; i++)
	{
		bit[i] = 0;
	}
	for(int i = n; i > 0; i--)
	{
		ret += sum(c[i]-1);
		upd(c[i], 1);
	}
	return ret;
}

int main()
{
	freopen("mincross.in", "r", stdin);
	freopen("mincross.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		int k;
		cin >> k;
		a[k] = i;
	}
	for(int i = 1; i <= n; i++)
	{
		int k;
		cin >> k;
		b[k] = i;
	}
	for(int i = 1; i <= n; i++)
	{
		c[a[i]] = b[i];
	}
	ll in = ct_inv(), run = in;
	for(int i = n; i > 0; i--)
	{
		run += (2*c[i]-n-1);
		in = min(in, run);
	}
	for(int i = 1; i <= n; i++)
	{
		c[b[i]] = a[i];
	}
	ll nv = ct_inv();
	run = nv;
	for(int i = n; i > 0; i--)
	{
		run += (2*c[i]-n-1);
		nv = min(nv, run);
	}
	cout << min(in, nv) << endl;
}