#include <bits/stdc++.h>

using namespace std;

void solve()
{
	int n; cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i++)
		cin >> a[i];
	if(a[0] == 1 || a[n-1] == n)
	{
		bool inc = 1;
		for(int i = 1; i < n; i++)
		{
			if(a[i] < a[i-1]) inc = 0;
		}
		if(inc) cout << 0 << endl;
		else cout << 1 << endl;
	} else if(a[0] == n && a[n-1] == 1)
	{
		cout << 3 << endl;
	} else 
	{
		cout << 2 << endl;
	}
}

int main()
{
	int t; cin >> t;
	while(t--) solve();
}
