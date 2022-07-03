#include <bits/stdc++.h>

using namespace std;

void solve()
{
	int n, m; cin >> n >> m;
	vector<int> a(n);
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	int mn = a[0];
	set<int> hs;
	hs.insert(0);
	for(int i = 1; i < n; i++)
	{
		if(a[i] < mn)
		{
			mn = a[i];
			hs.insert(i);
		} 
	}

	for(int i = 0; i < m; i++)
	{
		int k, x; cin >> k >> x;
		--k;
		a[k] -= x;
		auto it = hs.upper_bound(k);
		if(it != hs.begin())
		{
			// find the current train head of k (it) and if a[head] > a[k] then we add
			// k as a head.
			it = prev(it);
			if(*it == k || a[*it] > a[k]) hs.insert(k);
		} else hs.insert(k);

		while(true)
		{
			// remove heads after k s.t. a[head] >= a[k] (because k must be the head of those too)
			it = hs.upper_bound(k);
			if(it != hs.end() && a[*it] >= a[k])
			{
				hs.erase(it);
			} else break;
		}
		cout << hs.size() << " "; 
	}
	cout << endl;
}

int main()
{
	int t; cin >> t;
	while(t--)
	{
		solve();
	}
}
