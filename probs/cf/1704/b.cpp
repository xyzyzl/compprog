#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t; cin >> t;
	while(t--)
	{
		int n, x; cin >> n >> x;
		vector<int> a(n);
		for(int i = 0; i < n; i++) cin >> a[i];
		int mx = a[0], mn = a[0];
		int ans = 0;
		for(int i = 1; i < n; i++)
		{
			mx = max(mx, a[i]);
			mn = min(mn, a[i]);
			if(mx - mn > 2*x)
			{
				ans++;
				mx = a[i];
				mn = a[i];
			}
		}
		cout << ans << endl;
	}
}