#include <bits/stdc++.h>

#define MAXN 100005
using namespace std;

int n, bit[2*MAXN];
pair<int, int> a[MAXN];
#define f first
#define s second

void upd(int ind)
{
	while(ind <= n)
	{
		bit[ind]++;
		ind += ind&-ind;
	}
}

int get(int ind)
{
	int sm = 0;
	while(ind > 0)
	{
		sm += bit[ind];
		ind -= ind&-ind;
	}
	return sm;
}

int main()
{
	freopen("sort.in", "r", stdin);
	freopen("sort.out", "w", stdout);
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		cin >> a[i].f;
		a[i].s = i;
	}
	sort(a, a+n);
	int mx = 1;
	for(int i = 0; i < n; i++)
	{
		upd(a[i].s+1);
		mx = max(mx, i+1 - get(i+1));
	}
	cout << mx << endl;
}