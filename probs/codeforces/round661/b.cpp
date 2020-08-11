#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		vector<int> a(n), b(n);
		for(int i = 0; i < n; i++) cin >> a[i];
		for(int i = 0; i < n; i++) cin >> b[i];
		int ma=1e9+7, mb=1e9+7;
		for(int i = 0; i < n; i++) ma = min(ma, a[i]);
		for(int i = 0; i < n; i++) mb = min(mb, b[i]);
		long long ans = 0;
		for(int i = 0; i < n; i++)
		{
			long long x = min(a[i] - ma, b[i] - mb);
			a[i] -= x;
			b[i] -= x;
			x += a[i] - ma;
			x += b[i] - mb;
			ans += x;
		}
		cout << ans << endl;
	}
}
