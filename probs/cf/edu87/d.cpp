#include <bits/stdc++.h>

using namespace std;

int n, k;
vector<int> v, q;

int find_le(int x)
{
	int ret = 0;
	for(int i = 0; i < n; i++)
	{
		// if(v[i] > x) break;
		ret += (v[i] <= x);
	}
	for(int i = 0; i < k; i++)
	{
		if(q[i] > 0)
		{
			ret += (q[i] <= x);
		}
		if(q[i] < 0)
		{
			ret -= ((-q[i]) <= ret);
		}
	}
	return ret;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	// int n, k;
	cin >> n >> k;
	// vector<int> v(n), q(k);
	v.resize(n);
	q.resize(k);
	for(int i = 0; i < n; i++) cin >> v[i];
	for(int i = 0; i < k; i++) cin >> q[i];
	if(find_le(INT_MAX) == 0) 
	{
		cout << 0 << endl;
		return 0;
		// all elements are guaranteed to fit in integer so
	}
	int lo = 0;
	int hi = 1000005;
	while(lo < hi-1)
	{
		int mid = (lo+hi)/2;
		if(find_le(mid) > 0) hi = mid;
		else lo = mid;
	}
	// cout << find_le(5) << endl;
	cout << hi << endl;
}
