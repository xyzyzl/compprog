#include <iostream>
#include <vector>

#define ll long long

using namespace std;

int n, a[100005];
ll bit[200005];

ll sum(int x)
{
	ll ret = 0;
	while(x > 0)
	{
		ret += bit[x];
		x -= (x & -x);
	}
	return ret;
}

void upd(int x, int v)
{
	while(x <= n+1)
	{
		bit[x] += v;
		x += (x & -x);
	}
}

ll inv_count[100005];
ll find_inv()
{
	ll ret = 0;
	for(int i = 0; i < n; i++)
	{
		bit[i] = 0;
	}
	for(int i = 0; i < n; i++)
	{
		inv_count[i] = sum(n+1) - sum(a[i]+1);
		ret += inv_count[i];
		upd(a[i]+1, 1);
	}
	return ret;
}

vector<int> cur[100005];
ll fin[100005];
int main()
{
	freopen("haircut.in", "r", stdin);
	freopen("haircut.out", "w", stdout);
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
		cur[a[i]].push_back(i);
	}
	ll init = find_inv();
	for(int i = n-1; i >= 0; i--)
	{
		for(int j : cur[i])
		{
			init -= inv_count[j];
		}
		fin[i] = init;
	}
	for(int i = 0; i < n; i++)
	{
		cout << fin[i] << endl;
	}
}
