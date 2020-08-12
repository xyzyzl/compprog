#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long n, d, m;
	cin >> n >> d >> m;
	vector<long long> a(n);
	for(int i = 0; i < n; i++) cin >> a[i];
	sort(a.begin(), a.end());
	long long mn = n-(upper_bound(a.begin(), a.end(), m) - a.begin());
	deque<long long> dq;
	long long ans = 0;
	for(int i = 0; i < n; i++)
	{
		dq.push_back(a[i]);
	}
	for(int i = 0; i < mn-1; i++)
	{
		ans += (long long)dq.back();
		dq.pop_back();
		long long altsum = 0;
		for(int i = 0; i < d; i++)
		{
			if(dq.empty())
			{
				ans += altsum;
				goto here;
			}
			if(dq.front() <= m)
			{
				altsum += dq.front();
			}
			dq.pop_front();
		}
		if(dq.empty())
		{
			ans += altsum;
			goto here;
		}
	}
	if(dq.empty()) goto here;
	ans += (long long) dq.back();
	dq.pop_back();
	while(!dq.empty())
	{
		ans += (long long) dq.back();
		dq.pop_back();
	}
here:
	cout << ans << endl;
}
