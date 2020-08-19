#include <bits/stdc++.h>

using namespace std;

#define int long long
#define bitinc(x) x&-x

int n, k;
int bit[2000005];
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
signed main()
{
	cin >> n >> k;
	k = min(k, n-k);
	// start at vertex 0
	int q = 1;
	int x = 1;
	for(int i = 0; i < n; i++)
	{
		// cout << "ben shapiro" << endl;
		int p = q;
		q = (q+k-1)%n + 1;
		// int a = min(p, q);
		// int b = max(p, q);
		if(p > q) x += sum(n) - sum(p) + sum(q-1) + 1;
		else x += sum(q-1) - sum(p)+1;
		upd(p, 1);
		upd(q, 1);
		cout << x << " ";
	}
	cout << endl;
}
