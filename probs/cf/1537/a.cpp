#include <bits/stdc++.h>

using namespace std;

void solve()
{
	int n; cin >> n;
	vector<int> a(n);
	int sm = 0;
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
		sm += a[i];
	}
	if(sm < n) cout << 1 << endl;
	else if(sm == n) cout << 0 << endl;
	else
	{
		cout << sm-n << endl;
	}
}

int main()
{
	int t; cin >> t;
	while(t--)
	{
		solve();
	}
}