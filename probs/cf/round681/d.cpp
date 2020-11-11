#include <bits/stdc++.h>

using namespace std;


void solve()
{
	int n; cin >> n;
	vector<int> v(n);
	for(int i = 0; i < n; i++)
	{
		cin >> v[i];
	}
	int k = 0;
	bool ok = 1;
	for(int i = n-2; i >= 0; i--)
	{
		// cerr << k << endl;
		if(v[i] - k <= v[i+1]) v[i] -= k;
		else
		{
			k = v[i]-v[i+1];
			v[i] -= k;
		}
		if(v[i] < 0)
		{
			cout << "NO" << endl;
			return;
		}
	}
	for(int i = 0; i < n-1; i++)
	{
		if(v[i] > v[i+1])
		{
			cout << "NO" << endl;
			return;
		}
	}
	cout << "YES" << endl;
}

int main()
{
	int t; cin >> t;
	while(t--)
	{
		solve();
	}
}
