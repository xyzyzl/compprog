#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		vector<int> v;
		v.push_back(0);
		for(int i = 1; i <= n; i++)
		{
			char c;
			cin >> c;
			v.push_back(c-'0');
		}
		vector<int> ps(1+n);
		for(int i = 1; i <= n; i++)
		{
			ps[i] = ps[i-1] + v[i];
		}
		map<int, int> f;
		for(int i = 0; i <= n; i++)
		{
			f[ps[i] - i]++;
		}
		int ans = 0;
		for(int i = 0; i < n; i++)
		{
			if(!f[ps[i]-i]) continue;
			ans += (f[ps[i]-i]-1)*(f[ps[i]-i])/2;
			f[ps[i]-i] = 0;
		}
		cout << ans << endl;
	}
}

