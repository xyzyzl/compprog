#include <bits/stdc++.h>

using namespace std;

void solve()
{
	int n, d; cin >> n >> d;
	vector<int> a(n+1);
	for(int i = 1; i <= n; i++) cin >> a[i];
	int ans = 0;
	for(int i = 1; i <= n; i++)
	{
		if(a[i] == 1 && a[i-1] == 0)
		{
			ans++;
		}
	}
	cout << ans << endl;
}

int main()
{
	int t; cin >> t;
	for(int i = 1; i <= t; i++)
	{
		cout << "Case #" << i << ": ";
		solve();
	}
}