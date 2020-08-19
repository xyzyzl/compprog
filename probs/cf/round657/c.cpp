#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t; cin >> t;
	while(t--)
	{
		long long n;
		int m;
		cin >> n >> m;
		vector<int> a(m), b(m), c(m);
		vector<long long> p(m);
		for(int i = 0; i < m; i++)
		{
			cin >> a[i] >> b[i];
			c[i] = a[i];
		}
		sort(c.begin(), c.end());
		p[0] = c[0];
		for(int i = 1; i < m; i++)
		{
			p[i] = p[i-1] + c[i];
		}
		long long ans = 0;
		if(m > n)
		{
			for(int i = 0; i < n; i++) ans += c[m-i-1];
			if(n == 1)
			{
				cout << ans << endl;
				continue;
			}
		}
		for(int i = 0; i < m; i++)
		{
			long long x = (upper_bound(c.begin(), c.end(), b[i]) - c.begin()) - 1;
			long long tot = 0;
			if(x >= 0 && a[i] <= c[x])
			{
				if(n < (m-x)) continue;
				if(x >= 0) tot = (p[m-1] - p[x]) + a[i] + b[i] * (n-(m-x));
				else       tot =  p[m-1]         + a[i] + b[i] * (n-(m+1));
			} else 
			{
				if(n < (m-x-1)) continue;
				if(x >= 0) tot = (p[m-1] - p[x]) + b[i] * (n-(m-x-1));
				else       tot =  p[m-1]         + b[i] * (n-m);
			}
			ans = max(ans, tot);
		}
		cout << ans << endl;
	}
}
